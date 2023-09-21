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
			uint64_t			m_uiDataAllocLength;
			uint8_t*			m_pData;
		};
	};

	Buffer(std::vector<uint8_t>& vecData); // EStorage::STD_VECTOR.
	Buffer(uint8_t* pData, uint64_t uiDataLen, uint64_t uiDataAllocLength = 0); // EStorage::POINTER_READONLY. readonly buffer.
	Buffer(); // must set m_uiStorage and other qualifying properties.
	~Buffer();

	uint8_t					storage();
	void					seek(uint64_t uiByteIndex);
	uint64_t				seek();
	
	uint64_t				length();
	uint64_t				capacity();
	uint8_t*				data();

	uint64_t				left();
	uint64_t				canRW(uint64_t uiByteCount);

	uint8_t*				get(uint64_t uiByteCount);
	uint8_t*				get(uint64_t uiIndex, uint64_t uiByteCount);

	void					push(uint8_t* pData, uint64_t uiByteCount);
	void					push(std::vector<uint8_t>& vecData);
	void					pop(uint64_t uiByteCount);

	/*
	void					shift(uint64_t uiByteCount);
	void					unshift(uint8_t* pData, uint64_t uiByteCount);
	void					unshift(std::vector<uint8_t>& vecData);

	void					set(uint64_t uiIndex, uint8_t* pData, uint64_t uiByteCount);
	void					set(uint64_t uiIndex, std::vector<uint8_t>& vecData);
	void					remove(uint64_t uiIndex, uint64_t uiByteCount);
	*/
};