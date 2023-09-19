#include "RWBase.h"
#include <cstdint>

using namespace mx;

RWBase::RWBase(Buffer* pBuffer, bool bBufferApiOwned) :
	m_pBuffer(pBuffer),
	m_bBufferApiOwned(bBufferApiOwned),
	m_uiEndian(LITTLE_ENDIAN)
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