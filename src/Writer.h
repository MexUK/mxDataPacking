#pragma once

#include <string>

#include "mx.h"
#include "RWBase.h"

class mx::Writer : public mx::RWBase
{
public:
	Writer(Buffer* pBuffer);
	Writer(uint8_t* pBufferData, uint64_t uiBufferLen);
	Writer(void);
	~Writer(void);

	void					ui8(uint8_t uiValue);
	void					ui16(uint16_t uiValue);
	void					ui24(uint32_t uiValue);
	void					ui32(uint32_t uiValue);
	void					ui64(uint64_t uiValue);
	
	void					f32(float fValue);
	void					f64(double fValue);
	
	void					cstr(char* pData, uint64_t uiLength);
	void					mstr(std::string& strData);

	void					vec2(float* pFloats);
	void					vec3(float* pFloats);
	void					vec4(float* pFloats);

	void					mat34(float* pFloats);
	void					mat43(float* pFloats);
	void					mat44(float* pFloats);

	template <class T>
	void structure(T& structure)
	{
		cstr((char*)&structure, sizeof(T));
	};
};