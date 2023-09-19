#include <iterator>

#include "EStorage.h"
#include "Buffer.h"

using namespace std;
using namespace mx;

Buffer::Buffer(vector<uint8_t>& vecData) :
	m_uiIndex(0),
	m_uiStorage(EStorage::STD_VECTOR),
	m_vecData(vecData.begin(), vecData.end())
{
}

Buffer::Buffer(uint8_t* pBufferData, uint64_t uiBufferLen) :
	m_uiIndex(0),
	m_uiStorage(EStorage::POINTER_AND_LENGTH),
	m_uiDataLength(uiBufferLen),
	m_pData(pBufferData)
{
}

Buffer::Buffer() :
	m_uiIndex(0),
	m_uiStorage(EStorage::POINTER_AND_LENGTH),
	m_uiDataLength(0),
	m_pData(nullptr)
{
}

Buffer::~Buffer()
{
}


uint8_t					Buffer::storage()
{
	return m_uiStorage;
}

void					Buffer::seek(uint64_t uiByteIndex)
{
	m_uiIndex = uiByteIndex;
}

uint64_t				Buffer::seek()
{
	return m_uiIndex;
}

uint64_t				Buffer::left()
{
	return length() - m_uiIndex;
}

uint64_t				Buffer::length()
{
	switch (m_uiStorage)
	{
	case EStorage::STD_VECTOR:
		return m_vecData.size();

	case EStorage::POINTER_AND_LENGTH:
		return m_uiDataLength;

	default:
		return 0;
	}
}

uint8_t*				Buffer::data()
{
	switch (m_uiStorage)
	{
	case EStorage::STD_VECTOR:
		return m_vecData.data();

	case EStorage::POINTER_AND_LENGTH:
		return m_pData;

	default:
		return nullptr;
	}
}


uint8_t*				Buffer::get(uint64_t uiByteCount)
{
	uint8_t* pData;

	switch (m_uiStorage)
	{
	case EStorage::STD_VECTOR:
		pData = m_vecData.data() + m_uiIndex;
		m_uiIndex += uiByteCount;
		return pData;

	case EStorage::POINTER_AND_LENGTH:
		pData = m_pData + m_uiIndex;
		m_uiIndex += uiByteCount;
		return pData;

	default:
		return nullptr;
	}
}

uint8_t*				Buffer::get(uint64_t uiIndex, uint64_t uiByteCount)
{
	uint8_t* pData;

	switch (m_uiStorage)
	{
	case EStorage::STD_VECTOR:
		pData = m_vecData.data() + uiIndex;
		m_uiIndex += uiByteCount;
		return pData;

	case EStorage::POINTER_AND_LENGTH:
		pData = m_pData + uiIndex;
		m_uiIndex += uiByteCount;
		return pData;

	default:
		return nullptr;
	}
}


void					Buffer::push(uint8_t* pData, uint64_t uiByteCount)
{
	switch (m_uiStorage)
	{
	case EStorage::STD_VECTOR:
		m_vecData.insert(m_vecData.end(), pData, pData + uiByteCount);
		m_uiIndex += uiByteCount;
		break;

	case EStorage::POINTER_AND_LENGTH:
		memcpy(m_pData + m_uiIndex, pData, uiByteCount);
		m_uiIndex += uiByteCount;
		m_uiDataLength += uiByteCount;
		break;
	}
}

void					Buffer::push(vector<uint8_t>& vecData)
{
	uint8_t* pData;
	uint64_t uiSize;

	switch (m_uiStorage)
	{
	case EStorage::STD_VECTOR:
		pData = m_vecData.data();
		uiSize = vecData.size();
		m_vecData.insert(m_vecData.end(), pData, pData + uiSize);
		m_uiIndex += uiSize;
		break;

	case EStorage::POINTER_AND_LENGTH:
		pData = vecData.data();
		uiSize = vecData.size();
		memcpy(m_pData + m_uiIndex, pData, uiSize);
		m_uiIndex += uiSize;
		m_uiDataLength += uiSize;
		break;
	}
}

void					Buffer::pop(uint64_t uiByteCount)
{
	switch (m_uiStorage)
	{
	case EStorage::STD_VECTOR:
		m_vecData.erase(m_vecData.end() - uiByteCount);
		m_uiIndex -= uiByteCount;
		break;

	case EStorage::POINTER_AND_LENGTH:
		m_uiIndex -= uiByteCount;
		m_uiDataLength -= uiByteCount;
		break;
	}
}


/*
void					Buffer::shift(uint64_t uiEntryCount)
{
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
*/

