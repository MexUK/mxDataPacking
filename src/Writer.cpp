#include "Writer.h"

using namespace std;
using namespace mx;

Writer::Writer(Buffer* pBuffer) :
	RWBase(pBuffer, false)
{
}

Writer::Writer() :
	RWBase(new Buffer(), true)
{
}

Writer::~Writer()
{
	RWBase::~RWBase();
}

// int
void					Writer::ui8(uint8_t uiValue)
{
	m_pBuffer->push(&uiValue, 1);
}

void					Writer::ui16(uint16_t uiValue)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
		uiValue = _byteswap_ushort(uiValue);
	m_pBuffer->push((uint8_t*)&uiValue, 2);
}

void					Writer::ui24(uint32_t uiValue)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
	{
		uint8_t uiPart1 = uiValue & 0xFF;
		uint16_t uiPart2 = (uiValue >> 8) & 0xFFFF;
		uiPart2 = _byteswap_ushort(uiPart2);
		uint32_t uiValue2 = uiPart1 | (uiPart2 << 8);
		m_pBuffer->push((uint8_t*)&uiValue2, 3);
	}
	else
	{
		m_pBuffer->push((uint8_t*)&uiValue, 3);
	}
}

void					Writer::ui32(uint32_t uiValue)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
		uiValue = _byteswap_ulong(uiValue);
	m_pBuffer->push((uint8_t*)&uiValue, 4);
}

void					Writer::ui64(uint64_t uiValue)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
		uiValue = _byteswap_uint64(uiValue);
	m_pBuffer->push((uint8_t*)&uiValue, 8);
}

// float
void					Writer::f32(float fValue)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
		fValue = _byteswap_ulong(fValue);
	m_pBuffer->push((uint8_t*)&fValue, 4);
}

void					Writer::f64(double fValue)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
		fValue = _byteswap_uint64(fValue);
	m_pBuffer->push((uint8_t*)&fValue, 8);
}

void					Writer::f80(long double fValue)
{
	f64(fValue);
}

// string
void					Writer::cstr(char* pData, uint64_t uiLength)
{
	m_pBuffer->push((uint8_t*)pData, uiLength);
}

void					Writer::mstr(string& strData)
{
	ui64(strData.length());
	m_pBuffer->push((uint8_t*)strData.c_str(), strData.length());
}

// vector
void					Writer::vec2(float* pFloats)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
	{
		pFloats[0] = _byteswap_ulong(pFloats[0]);
		pFloats[1] = _byteswap_ulong(pFloats[1]);
	}
	m_pBuffer->push((uint8_t*)&pFloats, 8);
}

void					Writer::vec3(float *pFloats)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
	{
		pFloats[0] = _byteswap_ulong(pFloats[0]);
		pFloats[1] = _byteswap_ulong(pFloats[1]);
		pFloats[2] = _byteswap_ulong(pFloats[2]);
	}
	m_pBuffer->push((uint8_t*)&pFloats, 12);
}

// matrix
void					Writer::mat34(float* pFloats)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
	{
		pFloats[0] = _byteswap_ulong(pFloats[0]);
		pFloats[1] = _byteswap_ulong(pFloats[1]);
		pFloats[2] = _byteswap_ulong(pFloats[2]);
		pFloats[3] = _byteswap_ulong(pFloats[3]);
		pFloats[4] = _byteswap_ulong(pFloats[4]);
		pFloats[5] = _byteswap_ulong(pFloats[5]);
		pFloats[6] = _byteswap_ulong(pFloats[6]);
		pFloats[7] = _byteswap_ulong(pFloats[7]);
		pFloats[8] = _byteswap_ulong(pFloats[8]);
		pFloats[9] = _byteswap_ulong(pFloats[9]);
		pFloats[10] = _byteswap_ulong(pFloats[10]);
		pFloats[11] = _byteswap_ulong(pFloats[11]);
	}
	m_pBuffer->push((uint8_t*)&pFloats, 48);
}

void					Writer::mat43(float* pFloats)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
	{
		pFloats[0] = _byteswap_ulong(pFloats[0]);
		pFloats[1] = _byteswap_ulong(pFloats[1]);
		pFloats[2] = _byteswap_ulong(pFloats[2]);
		pFloats[3] = _byteswap_ulong(pFloats[3]);
		pFloats[4] = _byteswap_ulong(pFloats[4]);
		pFloats[5] = _byteswap_ulong(pFloats[5]);
		pFloats[6] = _byteswap_ulong(pFloats[6]);
		pFloats[7] = _byteswap_ulong(pFloats[7]);
		pFloats[8] = _byteswap_ulong(pFloats[8]);
		pFloats[9] = _byteswap_ulong(pFloats[9]);
		pFloats[10] = _byteswap_ulong(pFloats[10]);
		pFloats[11] = _byteswap_ulong(pFloats[11]);
	}
	m_pBuffer->push((uint8_t*)&pFloats, 48);
}

void					Writer::mat44(float* pFloats)
{
	if (m_uiEndian == EEndian::INVERSE_ENDIAN)
	{
		pFloats[0] = _byteswap_ulong(pFloats[0]);
		pFloats[1] = _byteswap_ulong(pFloats[1]);
		pFloats[2] = _byteswap_ulong(pFloats[2]);
		pFloats[3] = _byteswap_ulong(pFloats[3]);
		pFloats[4] = _byteswap_ulong(pFloats[4]);
		pFloats[5] = _byteswap_ulong(pFloats[5]);
		pFloats[6] = _byteswap_ulong(pFloats[6]);
		pFloats[7] = _byteswap_ulong(pFloats[7]);
		pFloats[8] = _byteswap_ulong(pFloats[8]);
		pFloats[9] = _byteswap_ulong(pFloats[9]);
		pFloats[10] = _byteswap_ulong(pFloats[10]);
		pFloats[11] = _byteswap_ulong(pFloats[11]);
		pFloats[12] = _byteswap_ulong(pFloats[12]);
		pFloats[13] = _byteswap_ulong(pFloats[13]);
		pFloats[14] = _byteswap_ulong(pFloats[14]);
		pFloats[15] = _byteswap_ulong(pFloats[15]);
	}
	m_pBuffer->push((uint8_t*)&pFloats, 64);
}

