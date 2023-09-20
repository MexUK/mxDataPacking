#pragma once

#include <cstdint>

#include "mx.h"

enum mx::EStorage : uint8_t
{
	STD_VECTOR			= 0,
	POINTER_READONLY	= 1
};