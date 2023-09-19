#include "Writer.h"
//#include "Static/String.h" // temp - for pack754_32/64/80
#include "EEndian.h"

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
	m_pBuffer->push((uint8_t*)&uiValue, 2);
}

void					Writer::ui24(uint32_t uiValue)
{
	m_pBuffer->push((uint8_t*)&uiValue, 3);
}

void					Writer::ui32(uint32_t uiValue)
{
	m_pBuffer->push((uint8_t*)&uiValue, 4);
}

void					Writer::ui64(uint64_t uiValue)
{
	m_pBuffer->push((uint8_t*)&uiValue, 8);
}

// float
void					Writer::f32(float fValue)
{
	m_pBuffer->push((uint8_t*)&fValue, 4);
}

void					Writer::f64(double fValue)
{
	m_pBuffer->push((uint8_t*)&fValue, 8);
}

void					Writer::f80(long double fValue)
{
	m_pBuffer->push((uint8_t*)&fValue, 10);
}

// string
void					Writer::cstr(char* pData, uint64_t uiLength)
{
	m_pBuffer->push((uint8_t*)pData, uiLength);
}

void					Writer::str(string& strData)
{
	m_pBuffer->push((uint8_t*)strData.c_str(), strData.length());
}

void					Writer::mstr(string& strData)
{
	ui64(strData.length());
	m_pBuffer->push((uint8_t*)strData.c_str(), strData.length());
}

// vector
void					Writer::vec2(float* pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 8);
}

void					Writer::vec3(float *pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 12);
}

// matrix
void					Writer::mat34(float* pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 48);
}

void					Writer::mat43(float* pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 48);
}

void					Writer::mat44(float* pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 64);
}

