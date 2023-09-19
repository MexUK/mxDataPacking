#include "Reader.h"
//#include "Static/String.h" // temp - for unpack754_32/64/80
#include "EEndian.h"

using namespace std;
using namespace mx;

Reader::Reader(Buffer* pBuffer) :
	RWBase(pBuffer, false)
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
uint8_t					Reader::ui8()
{
	return m_pBuffer->get(1)[0];
}

uint16_t					Reader::ui16()
{
	return *(uint16_t*)m_pBuffer->get(2);
}

uint32_t					Reader::ui24()
{
	uint16_t uiPart1 = *(uint16_t*)m_pBuffer->get(2);
	uint8_t uiPart2 = *(uint8_t*)m_pBuffer->get(1);
	return (uiPart1 << 8) + uiPart2;
}

uint32_t					Reader::ui32()
{
	return *(uint32_t*)m_pBuffer->get(4);
}

uint64_t					Reader::ui64()
{
	return *(uint64_t*)m_pBuffer->get(8);
}

// float
float						Reader::f32()
{
	return *(float*)m_pBuffer->get(4);
}

double						Reader::f64()
{
	return *(double*)m_pBuffer->get(8);
}

long double					Reader::f80()
{
	// todo
	return *(long double*)m_pBuffer->get(10);
}

// string
char*					Reader::cstrHeap(uint64_t uiLength)
{
	uint8_t* pBuffer = new uint8_t[uiLength];
	pBuffer = m_pBuffer->get(uiLength);
	return (char*)pBuffer;
}

char*					Reader::cstr(uint64_t uiLength)
{
	return (char*)m_pBuffer->get(uiLength);
}

string					Reader::str(uint64_t uiLength)
{
	string str((char*)m_pBuffer->get(uiLength));
	return str;
}

string					Reader::mstr()
{
	uint64_t uiLength = ui64();
	string str((char*)m_pBuffer->get(uiLength));
	return str;
}

// vector
float*					Reader::vec2()
{
	return (float*)m_pBuffer->get(8);
}

float*					Reader::vec3()
{
	return (float*)m_pBuffer->get(12);
}

// matrix
float*					Reader::mat34()
{
	return (float*)m_pBuffer->get(48);
}

float*					Reader::mat43()
{
	return (float*)m_pBuffer->get(48);
}

float*					Reader::mat44()
{
	return (float*)m_pBuffer->get(64);
}
