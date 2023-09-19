#pragma once

#include <cstdint>
#include <vector>

#include "mx.h"
#include "EEndian.h"

class mx::Buffer
{
public:
	uint64_t					m_uiIndex;

	uint8_t						m_uiStorage;
	union
	{
		std::vector<uint8_t>	m_vecData;
		struct
		{
			uint64_t			m_uiDataLength;
			uint8_t*			m_pData;
		};
	};

	Buffer(std::vector<uint8_t>& vecData);
	Buffer(uint8_t* pBufferData, uint64_t uiBufferLen);
	Buffer();
	~Buffer();

	uint8_t					storage();
	void					seek(uint64_t uiByteIndex);
	uint64_t				seek();
	
	uint64_t				length();
	uint64_t				capacity();
	uint8_t*				data();

	uint64_t				left();
	uint64_t				canRead(uint64_t uiByteCount);

	uint8_t*				get(uint64_t uiByteCount);
	uint8_t*				get(uint64_t uiIndex, uint64_t uiByteCount);

	void					push(uint8_t* pData, uint64_t uiByteCount);
	void					push(std::vector<uint8_t>& vecData);
	void					pop(uint64_t uiByteCount);

	/*
	void					shift(uint64_t uiEntryCount);
	void					unshift(std::vector<uint8_t> vecBytes);

	void					set(uint64_t uiIndex, std::vector<uint8_t> vecBytes);
	void					remove(uint64_t uiIndex, uint64_t uiByteCount);
	*/
};