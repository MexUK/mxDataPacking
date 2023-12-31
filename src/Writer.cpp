#include "Writer.h"

using namespace std;
using namespace mx;

Writer::Writer(Buffer* pBuffer) :
	RWBase(pBuffer, false)
{
}

Writer::Writer(uint8_t* pData, uint64_t uiDataLen, uint64_t uiDataAllocLength) :
	RWBase(new Buffer(pData, uiDataLen, uiDataAllocLength), true)
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
	m_pBuffer->push(&uiValue, sizeof(uint8_t));
}

void					Writer::ui16(uint16_t uiValue)
{
	uiValue = format(uiValue);
	m_pBuffer->push((uint8_t*)&uiValue, sizeof(uint16_t));
}

void					Writer::ui24(uint32_t uiValue)
{
	uiValue = format(uiValue);
	m_pBuffer->push((uint8_t*)&uiValue, sizeof(uint16_t) + sizeof(uint8_t));
}

void					Writer::ui32(uint32_t uiValue)
{
	uiValue = format(uiValue);
	m_pBuffer->push((uint8_t*)&uiValue, sizeof(uint32_t));
}

void					Writer::ui64(uint64_t uiValue)
{
	uiValue = format(uiValue);
	m_pBuffer->push((uint8_t*)&uiValue, sizeof(uint64_t));
}


void					Writer::i8(int8_t iValue)
{
	m_pBuffer->push((uint8_t*)&iValue, sizeof(int8_t));
}

void					Writer::i16(int16_t iValue)
{
	iValue = format(iValue);
	m_pBuffer->push((uint8_t*)&iValue, sizeof(int16_t));
}

void					Writer::i24(int32_t iValue)
{
	iValue = format(iValue);
	m_pBuffer->push((uint8_t*)&iValue, sizeof(int16_t) + sizeof(int8_t));
}

void					Writer::i32(int32_t iValue)
{
	iValue = format(iValue);
	m_pBuffer->push((uint8_t*)&iValue, sizeof(int32_t));
}

void					Writer::i64(int64_t iValue)
{
	iValue = format(iValue);
	m_pBuffer->push((uint8_t*)&iValue, sizeof(int64_t));
}

// float
void					Writer::f32(float fValue)
{
	fValue = format(fValue);
	m_pBuffer->push((uint8_t*)&fValue, sizeof(float));
}

void					Writer::f64(double fValue)
{
	fValue = format(fValue);
	m_pBuffer->push((uint8_t*)&fValue, sizeof(double));
}

// string
void					Writer::cstr(char* pData, uint64_t uiLength)
{
	m_pBuffer->push((uint8_t*)pData, uiLength);
}

void					Writer::mstr(string& strData)
{
	uint64_t uiLen = strData.length();

	if (uiLen < 0xFC)
	{
		ui8(uiLen);
	}
	else if (uiLen < 0xFFFF)
	{
		ui8(0xFF);
		ui16(uiLen);
	}
	else if (uiLen < 0xFFFFFF)
	{
		ui8(0xFE);
		ui24(uiLen);
	}
	else if (uiLen < 0xFFFFFFFF)
	{
		ui8(0xFD);
		ui32(uiLen);
	}
	else
	{
		ui8(0xFC);
		ui64(uiLen);
	}

	m_pBuffer->push((uint8_t*)strData.c_str(), uiLen);
}

// vector
void					Writer::vec2(float* pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 2 * sizeof(float));
}

void					Writer::vec3(float* pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 3 * sizeof(float));
}

void					Writer::vec4(float* pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 4 * sizeof(float));
}

// matrix
void					Writer::mat34(float* pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 3 * 4 * sizeof(float));
}

void					Writer::mat43(float* pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 4 * 3 * sizeof(float));
}

void					Writer::mat44(float* pFloats)
{
	m_pBuffer->push((uint8_t*)&pFloats, 4 * 4 * sizeof(float));
}

