#pragma once

#include <cstdint>
#include <vector>

#include "mx.h"
#include "EEndian.h"

#define MX_OCTET_COMBINATION_COUNT			256
#define MX_TWO_OCTETS_COMBINATION_COUNT		65536
#define MX_THREE_OCTETS_COMBINATION_COUNT	16777216
#define MX_FOUR_OCTETS_COMBINATION_COUNT	4294967296
#define MX_FIVE_OCTETS_COMBINATION_COUNT	1099511627776
#define MX_SIX_OCTETS_COMBINATION_COUNT		281474976710656
#define MX_SEVEN_OCTETS_COMBINATION_COUNT	72057594037927936

class mx::Buffer
{
public:
	Formatter*				m_pFormatter;
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