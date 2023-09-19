#pragma once

#include <string>

#include "mx.h"
#include "RWBase.h"

class mx::Reader : public mx::RWBase
{
public:
	Reader(Buffer *pBuffer);
	Reader(void);
	~Reader(void);

	uint8_t						ui8();
	uint16_t					ui16();
	uint32_t					ui24();
	uint32_t					ui32();
	uint64_t					ui64();
	
	float						f32();
	double						f64();
	long double					f80();
	
	char*						cstrHeap(uint64_t uiLength);
	char*						cstr(uint64_t uiLength);
	std::string					str(uint64_t uiLength);
	std::string					mstr();

	template <class T>
	void structure(T& structure)
	{
		cstr((char*)&structure, sizeof(T));
	};

	template <class T>
	T* structureHeap()
	{
		return (T*) cstrHeap(sizeof(T));
	};

	float*				vec2();
	float*				vec3();

	float*				mat34();
	float*				mat43();
	float*				mat44();
};