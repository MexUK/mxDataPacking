#include "Reader.h"

using namespace std;
using namespace mx;

Reader::Reader(Buffer* pBuffer) :
	RWBase(pBuffer, false)
{
}

Reader::Reader(uint8_t* pData, uint64_t uiDataLen, uint64_t uiDataAllocLength) :
	RWBase(new Buffer(pData, uiDataLen, uiDataAllocLength), true)
{
}

Reader::Reader() :
	RWBase(new Buffer(), true)
{
}

Reader::~Reader()
{
	RWBase::~RWBase();
}

// int
uint8_t						Reader::ui8()
{
	return m_pBuffer->get(1)[0];
}

uint16_t					Reader::ui16()
{
	return format(*(uint16_t*)m_pBuffer->get(2));
}

uint32_t					Reader::ui24()
{
	return format(*(uint32_t*)m_pBuffer->get(3));
}

uint32_t					Reader::ui32()
{
	return format(*(uint32_t*)m_pBuffer->get(4));
}

uint64_t					Reader::ui64()
{
	return format(*(uint64_t*)m_pBuffer->get(8));
}

// float
float						Reader::f32()
{
	return format(*(float*)m_pBuffer->get(4));
}

double						Reader::f64()
{
	return format(*(double*)m_pBuffer->get(8));
}

// string
char*						Reader::cstr(uint64_t uiLength)
{
	return (char*)m_pBuffer->get(uiLength);
}

string						Reader::mstr()
{
	uint64_t uiLength = ui64();
	string str((char*)m_pBuffer->get(uiLength));
	return str;
}

// vector
float*						Reader::vec2()
{
	return (float*)m_pBuffer->get(8);
}

float*						Reader::vec3()
{
	return (float*)m_pBuffer->get(12);
}

float*						Reader::vec4()
{
	return (float*)m_pBuffer->get(16);
}

// matrix
float*						Reader::mat34()
{
	return (float*)m_pBuffer->get(48);
}

float*						Reader::mat43()
{
	return (float*)m_pBuffer->get(48);
}

float*						Reader::mat44()
{
	return (float*)m_pBuffer->get(64);
}
