#pragma once

#include <cstdint>
#include <vector>

#include "mx.h"
#include "EEndian.h"

class mx::Buffer
{
public:
	uint64_t				m_uiIndex;
	std::vector<uint8_t>	m_vecData;

public:
	Buffer();

	uint8_t*				get(uint64_t uiByteCount);
	uint8_t*				get(uint64_t uiIndex, uint64_t uiByteCount);
	void					seek(uint64_t uiIndex);

	void					push(uint8_t* pData, uint64_t uiDataLen);
	void					push(std::vector<uint8_t> vecBytes);
	void					pop(uint64_t uiEntryCount);

	void					shift(uint64_t uiEntryCount);
	void					unshift(std::vector<uint8_t> vecBytes);

	void					set(uint64_t uiIndex, std::vector<uint8_t> vecBytes);
	void					remove(uint64_t uiIndex, uint64_t uiByteCount);
};