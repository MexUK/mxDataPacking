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
	return *m_pBuffer->get(sizeof(uint8_t));
}

uint16_t					Reader::ui16()
{
	return format(*(uint16_t*)m_pBuffer->get(sizeof(uint16_t)));
}

uint32_t					Reader::ui24()
{
	return format(*(uint32_t*)m_pBuffer->get(sizeof(uint16_t) + sizeof(uint8_t)));
}

uint32_t					Reader::ui32()
{
	return format(*(uint32_t*)m_pBuffer->get(sizeof(uint32_t)));
}

uint64_t					Reader::ui64()
{
	return format(*(uint64_t*)m_pBuffer->get(sizeof(uint64_t)));
}


int8_t						Reader::i8()
{
	return *(int8_t*)*m_pBuffer->get(sizeof(int8_t));
}

int16_t						Reader::i16()
{
	return format(*(int16_t*)m_pBuffer->get(sizeof(int16_t)));
}

int32_t						Reader::i24()
{
	return format(*(int32_t*)m_pBuffer->get(sizeof(int16_t) + sizeof(int8_t)));
}

int32_t						Reader::i32()
{
	return format(*(int32_t*)m_pBuffer->get(sizeof(int32_t)));
}

int64_t						Reader::i64()
{
	return format(*(int64_t*)m_pBuffer->get(sizeof(int64_t)));
}

// float
float						Reader::f32()
{
	return format(*(float*)m_pBuffer->get(sizeof(float)));
}

double						Reader::f64()
{
	return format(*(double*)m_pBuffer->get(sizeof(double)));
}

// string
char*						Reader::cstr(uint64_t uiLength)
{
	return (char*)m_pBuffer->get(uiLength);
}

string						Reader::mstr()
{
	uint64_t uiLength = ui8();

	switch (uiLength)
	{
	case 0xFF:
		uiLength = ui16();
		break;
	case 0xFE:
		uiLength = ui24();
		break;
	case 0xFD:
		uiLength = ui32();
		break;
	case 0xFC:
		uiLength = ui64();
		break;
	default:
		break;
	}

	string str((char*)m_pBuffer->get(uiLength));
	return str;
}

// vector
float*						Reader::vec2()
{
	return (float*)m_pBuffer->get(2 * sizeof(float));
}

float*						Reader::vec3()
{
	return (float*)m_pBuffer->get(3 * sizeof(float));
}

float*						Reader::vec4()
{
	return (float*)m_pBuffer->get(4 * sizeof(float));
}

// matrix
float*						Reader::mat34()
{
	return (float*)m_pBuffer->get(3 * 4 * sizeof(float));
}

float*						Reader::mat43()
{
	return (float*)m_pBuffer->get(4 * 3 * sizeof(float));
}

float*						Reader::mat44()
{
	return (float*)m_pBuffer->get(4 * 4 * sizeof(float));
}

