**Data Packing (C++)**

A C++ library with no dependencies, for packing/unpacking binary data, with a byte-vector buffer.

-----

**License**

The library has MIT license.  
This basically means you can use/edit the library for almost any purpose, make sure to  
include the "LICENSE" file with your copy of this library.

-----

**Example**

```cpp
#include "mx.h"
#include "Writer.h"
#include "Reader.h"

void func1()
{
   // write

   Writer bw;

   bw.ui8(1);
   bw.ui16(2);
   bw.ui24(3);
   bw.ui32(4);
   bw.ui64(8);
   bw.m_uiEndian = EEndian::INVERSE_ENDIAN;
   bw.ui64(8);
   bw.m_uiEndian = EEndian::INITIAL_ENDIAN;
   bw.f32(32.0f);
   bw.f64(64.0);
   string str("abcde");
   bw.cstr((char*)str.data(), 5);
   bw.mstr(str);

   sendPacket(bw.data(), bw.len());

   // read

   uint8_t packet[4096];
   uint64_t packetLen;
   packetLen = readPacket(packet);

   Reader br(packet, packetLen);

   uint8_t data1 = br.ui8();
   uint16_t data2 = br.ui16();
   uint32_t data3 = br.ui24();
   uint32_t data4 = br.ui32();
   uint64_t data8 = br.ui64();
   br.m_uiEndian = EEndian::INVERSE_ENDIAN;
   uint64_t data8b = br.ui64();
   br.m_uiEndian = EEndian::INITIAL_ENDIAN;
   float data32 = br.f32();
   double data64 = br.f64();
   str = br.cstr(5);
   str = br.mstr();
}
```

-----

**API**

mx

```cpp
namespace mx
{
	enum EEndian;
	class Buffer;
	class RWBase;
	class Reader;
	class Writer;
}
```

mx::EEndian

```cpp
mx::EEndian::INITIAL_ENDIAN;
mx::EEndian::INVERSE_ENDIAN;
```

mx::Writer : public mx::RWBase

```cpp
mx::Writer::Writer(Buffer* pBuffer);
mx::Writer::Writer(uint8_t* pBufferData, uint64_t uiBufferLen); // Constructs Buffer which copies pBufferData.
mx::Writer::Writer(void);
mx::Writer::~Writer(void);

void mx::Writer::ui8(uint8_t uiValue);
void mx::Writer::ui16(uint16_t uiValue);
void mx::Writer::ui24(uint32_t uiValue);
void mx::Writer::ui32(uint32_t uiValue);
void mx::Writer::ui64(uint64_t uiValue);
	
void mx::Writer::f32(float fValue);
void mx::Writer::f64(double fValue);
	
void mx::Writer::cstr(char* pData, uint64_t uiLength);
void mx::Writer::mstr(std::string& strData);

void mx::Writer::vec2(float* pFloats);
void mx::Writer::vec3(float* pFloats);
void mx::Writer::vec4(float* pFloats);

void mx::Writer::mat34(float* pFloats);
void mx::Writer::mat43(float* pFloats);
void mx::Writer::mat44(float* pFloats);

template <class T>
void mx::Writer::structure(T& structure);
```

mx::Reader : public mx::RWBase

```cpp
mx::Reader::Reader(Buffer *pBuffer);
mx::Reader::Reader(uint8_t* pBufferData, uint64_t uiBufferLen); // Constructs Buffer which copies pBufferData.
mx::Reader::Reader(void);
mx::Reader::~Reader(void);

uint8_t mx::Reader::ui8();
uint16_t mx::Reader::ui16();
uint32_t mx::Reader::ui24();
uint32_t mx::Reader::ui32();
uint64_t mx::Reader::ui64();

float mx::Reader::f32();
double mx::Reader::f64();

char* mx::Reader::cstr(uint64_t uiLength);
std::string mx::Reader::mstr();

template <class T>
void mx::Reader::structure(T& structure);
```

mx::RWBase

```cpp
uint8_t* mx::RWBase::data();
size_t mx::RWBase::len();
```

mx::Buffer

```cpp
uint64_t mx::Buffer::m_uiIndex;
std::vector<uint8_t> mx::Buffer::m_vecData;

mx::Buffer::Buffer(uint8_t* pBufferData, uint64_t uiBufferLen);
mx::Buffer::Buffer();

uint8_t* mx::Buffer::get(uint64_t uiByteCount);
uint8_t* mx::Buffer::get(uint64_t uiIndex, uint64_t uiByteCount);
void mx::Buffer::seek(uint64_t uiIndex);

void mx::Buffer::push(uint8_t* pData, uint64_t uiDataLen);
void mx::Buffer::push(std::vector<uint8_t> vecBytes);
void mx::Buffer::pop(uint64_t uiEntryCount);
```

-----

