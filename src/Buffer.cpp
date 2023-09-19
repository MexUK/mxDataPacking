#include "Buffer.h"
#include <iterator>

using namespace std;
using namespace mx;

Buffer::Buffer() :
	m_uiIndex(0)
{
}

uint8_t*				Buffer::get(uint64_t uiByteCount)
{
	uint8_t* pData = m_vecData.data();
	m_uiIndex += uiByteCount;
	return pData;
}

uint8_t*				Buffer::get(uint64_t uiIndex, uint64_t uiByteCount)
{
	uint8_t* pData = m_vecData.data() + uiIndex;
	m_uiIndex += uiByteCount;
	return pData;
}

void					Buffer::seek(uint64_t uiIndex)
{
	m_uiIndex = uiIndex;
}


void					Buffer::push(uint8_t* pData, uint64_t uiDataLen)
{
	m_vecData.insert(m_vecData.end(), pData, pData + uiDataLen);
	m_uiIndex += uiDataLen;
}

void					Buffer::push(vector<uint8_t> vecBytes)
{
	uint8_t* pData = m_vecData.data();
	uint64_t uiSize = vecBytes.size();
	m_vecData.insert(m_vecData.end(), pData, pData + uiSize);
	m_uiIndex += uiSize;
}

void					Buffer::pop(uint64_t uiEntryCount)
{
	//m_uiIndex -= uiEntryCount;
}


void					Buffer::shift(uint64_t uiEntryCount)
{
	//m_uiIndex -= uiEntryCount;
}

void					Buffer::unshift(vector<uint8_t> vecBytes)
{
}


void					Buffer::set(uint64_t uiIndex, vector<uint8_t> vecBytes)
{
}

void					Buffer::remove(uint64_t uiIndex, uint64_t uiByteCount)
{
}
