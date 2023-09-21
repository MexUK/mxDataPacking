#pragma once

#include "mxDataPacking.h"

#define PROTOCOL_OPCODE_INITIAL_PACKET 1

void sendInitialPacket();
void sendPacket(mx::Writer& bw);