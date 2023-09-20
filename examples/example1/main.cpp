#include "main.h"
#include <cstdint>
#include <string>

using namespace std;
using namespace mx;

void sendInitialPacket()
{
    uint32_t clientMultiplayerVersion = 1;
    string uuid("aabbccddeeffgghhiijj00112233445566");
    string playerName("PlayerName");

    Writer bw;
    bw.ui8(PROTOCOL_OPCODE_INITIAL_PACKET);
    bw.ui32(clientMultiplayerVersion);
    bw.mstr(uuid);
    bw.mstr(playerName);

    sendPacket(bw);
}

void sendPacket(Writer& bw)
{
    //writeToSomewhere(bw.data(), bw.length());
}