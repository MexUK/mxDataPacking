#pragma once

#include "mx.h"
#include "EEndian.h"
#include "Buffer.h"

class mx::RWBase
{
public:
	Buffer*					m_pBuffer;
	bool					m_bBufferApiOwned;
	EEndian					m_uiEndian;

public:
	RWBase(Buffer *pBuffer, bool bBufferApiOwned);
	~RWBase();
	
	uint8_t* data();
	size_t length();

	template <class T>
	T format(T value)
	{
		if (m_uiEndian == EEndian::INVERSE_ENDIAN)
		{
			value = endian(value);
		}

		return value;
	}

	template <class T>
	static T endian(T value)
	{
		switch (sizeof(T))
		{
		case 1:
			return value;
		case 2:
			return _byteswap_ushort(value);
		case 3:
		{
			uint8_t uiPart1 = ((uint64_t)value) & 0xFF;
			uint16_t uiPart2 = (((uint64_t)value) >> 8) & 0xFFFF;
			uiPart2 = _byteswap_ushort(uiPart2);
			return uiPart1 | (uiPart2 << 8);
		}
		case 4:
			return _byteswap_ulong(value);
		case 8:
			return _byteswap_uint64(value);
		default:
			return value;
		}
	}

private:
	void resetApiOwnedBuffer();
};