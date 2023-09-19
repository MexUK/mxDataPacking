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

