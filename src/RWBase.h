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
	virtual ~RWBase();
	
	uint8_t* data();
	uint64_t length();

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
#if defined(__GNUC__) || defined(__GNUG__)
		switch (sizeof(T))
		{
		case 1:
			return value;
		case 2:
			return __builtin_bswap16(value);
		case 3:
		{
			uint8_t uiPart1 = ((uint64_t)value) & 0xFF;
			uint16_t uiPart2 = (((uint64_t)value) >> 8) & 0xFFFF;
			uiPart2 = __builtin_bswap16(uiPart2);
			return uiPart1 | (uiPart2 << 8);
		}
		case 4:
			return __builtin_bswap32(value);
		case 8:
			return __builtin_bswap64(value);
		default:
			return value;
#elif defined(_MSC_VER)
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
#endif
		}
	}

private:
	void resetApiOwnedBuffer();
};