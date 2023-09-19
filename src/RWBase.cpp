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
	return m_pBuffer->m_vecData.data();
}

size_t RWBase::len()
{
	return m_pBuffer->m_vecData.size();
}

