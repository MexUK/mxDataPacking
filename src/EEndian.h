#pragma once

#include <cstdint>

#include "mx.h"

enum mx::EEndian : uint8_t
{
	INITIAL_ENDIAN		= 0,
	INVERSE_ENDIAN		= 1
};