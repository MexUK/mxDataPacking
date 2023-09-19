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
	~RWBase();
	
	void resetApiOwnedBuffer();
};