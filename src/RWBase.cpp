#include <cstdint>

#include "RWBase.h"

using namespace mx;

RWBase::RWBase(Buffer* pBuffer, bool bBufferApiOwned) :
	m_pBuffer(pBuffer),
	m_bBufferApiOwned(bBufferApiOwned),
	m_uiEndian(INITIAL_ENDIAN)
{
}

RWBase::~RWBase()
{
	if (m_bBufferApiOwned)
	{
		resetApiOwnedBuffer();
	}
}

void RWBase::resetApiOwnedBuffer()
{
	delete m_pBuffer;
	m_pBuffer = nullptr;
	m_bBufferApiOwned = false;
}

uint8_t* RWBase::data()
{
	return m_pBuffer->data();
}

uint64_t RWBase::length()
{
	return m_pBuffer->length();
}

void RWBase::reset()
{
	m_uiEndian = EEndian::INITIAL_ENDIAN;
	if (m_bBufferApiOwned)
	{
		resetApiOwnedBuffer();
	}
	else
	{
		m_pBuffer = nullptr;
	}
}

