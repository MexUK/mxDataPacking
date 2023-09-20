**Data Packing (C++ Library)**

![Build Status](https://github.com/MexUK/mxDataPacking/actions/workflows/msbuild.yml/badge.svg)  
![Build Status](https://github.com/MexUK/mxDataPacking/actions/workflows/cmake-win-linux-mac.yml/badge.svg)

A C++ library with no dependencies, for packing/unpacking binary data, with an optional memory buffer.

-----

**Introduction**

This C++ library is used for packing and unpacking binary data, and aims to be easy to use.  
  
```cpp
Writer bw;
bw.ui8(10);
bw.ui64(20);
bw.cstr("example");
//sendOrWrite(bw.data(), bw.length());

//uint8_t* pBuffer =
//uint64_t uiBufferLen =
Reader br(pBuffer, uiBufferLen);
int a = br.ui8();
int b = br.ui64();
string c = br.cstr("example");
```
  
The API includes classes Writer and Reader which both extend RWBase, and RWBase stores a Buffer object.  
The Buffer class, either uses either a std::vector<uint8_t> or a pointer, data length, and alloc length.

-----

**License**

This library has the MIT license.  
  
Meaning you can use/edit your copy of this library, even commercially, but include the license file.

-----

**Examples**

Please check the examples folder for example usage of this library.

-----

**API**

mx

```cpp
namespace mx
{
	enum EEndian;
	enum EStorage;
	class Buffer;
	class RWBase;
	class Reader;
	class Writer;
}
```

mx::EEndian

```cpp
mx::EEndian::INITIAL_ENDIAN = 0;
mx::EEndian::INVERSE_ENDIAN = 1;
```

mx::EStorage

```cpp
mx::EStorage::STD_VECTOR = 0;
mx::EStorage::POINTER_AND_LENGTH = 1;
```

mx::Writer : public mx::RWBase

```cpp
mx::Writer::Writer(Buffer* pBuffer);
mx::Writer::Writer(uint8_t* pData, uint64_t uiDataLen, uint64_t uiDataAllocLength = 0);
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
void mx::Writer::st(T& structure);
```

mx::Reader : public mx::RWBase

```cpp
mx::Reader::Reader(Buffer *pBuffer);
mx::Reader::Reader(uint8_t* pData, uint64_t uiDataLen, uint64_t uiDataAllocLength = 0);
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
T mx::Reader::st();
```

mx::RWBase

```cpp
uint8_t* mx::RWBase::data(); // Returns a pointer to the start of the data.
size_t mx::RWBase::length(); // Returns the total length of the data.

template <class T>
T mx::RWBase::format(T value);

template <class T>
static T mx::RWBase::endian(T value);
```

mx::Buffer

```cpp
mx::Buffer::Buffer(std::vector<uint8_t>& vecData);
mx::Buffer::Buffer(uint8_t* pData, uint64_t uiDataLen, uint64_t uiDataAllocLength = 0); // readonly buffer
mx::Buffer::Buffer(); // must set m_uiStorage

uint8_t mx::Buffer::storage();
void mx::Buffer::seek(uint64_t uiByteIndex);
uint64_t mx::Buffer::seek();

uint64_t mx::Buffer::length();
uint64_t mx::Buffer::capacity();
uint8_t* mx::Buffer::data();

uint64_t mx::Buffer::left();
uint64_t mx::Buffer::canRW(uint64_t uiByteCount);

uint8_t* mx::Buffer::get(uint64_t uiByteCount);
uint8_t* mx::Buffer::get(uint64_t uiIndex, uint64_t uiByteCount);
void mx::Buffer::seek(uint64_t uiIndex);

void mx::Buffer::push(uint8_t* pData, uint64_t uiByteCount);
void mx::Buffer::push(std::vector<uint8_t> vecData);
void mx::Buffer::pop(uint64_t uiByteCount);
```

-----

