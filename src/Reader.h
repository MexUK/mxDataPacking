#pragma once

#include <string>

#include "mx.h"
#include "RWBase.h"
#include "Buffer.h"

class mx::Reader : public mx::RWBase
{
public:
	Reader(Buffer *pBuffer);
	Reader(uint8_t* pData, uint64_t uiDataLen, uint64_t uiDataAllocLength = 0);
	Reader(void);
	~Reader(void);

	uint8_t						ui8();
	uint16_t					ui16();
	uint32_t					ui24();
	uint32_t					ui32();
	uint64_t					ui64();

	int8_t						i8();
	int16_t						i16();
	int32_t						i24();
	int32_t						i32();
	int64_t						i64();

	float						f32();
	double						f64();
	
	char*						cstr(uint64_t uiLength);
	std::string					mstr();

	float*						vec2();
	float*						vec3();
	float*						vec4();

	float*						mat34();
	float*						mat43();
	float*						mat44();

	template <class T>
	T st()
	{
		return *(T*)cstr(sizeof(T));
	};

	template <class T>
	T* stp()
	{
		return (T*)cstr(sizeof(T));
	};
};