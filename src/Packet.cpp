#include <Packet.h>

using namespace std;
namespace SimplePcapNs {
    Packet::Packet(
        int capturedLen,
        int realLen,
        int secOffset,
        int uSecOffset,
        u_char *data
    ) {
        this->capturedLen = capturedLen;
        this->realLen = realLen;
        this->secondsOffset = secOffset;
        this->uSecondsOffset = uSecOffset;
        this->data = string((const char *)data, capturedLen);
    }

    int
    Packet::getCapturedLen()
    {
        return capturedLen;
    }

    int
    Packet::getRealLen()
    {
        return realLen;
    }

    int
    Packet::getSecondsOffset()
    {
        return secondsOffset;
    }

    int
    Packet::getMicroSecondsOffset()
    {
        return uSecondsOffset;
    }

    string
    Packet::getData()
    {
        return this->data;
    }

    string
    Packet::__toString()
    {
        char buff[256];
        snprintf(
            buff, sizeof(buff),
            "[ Packet: capLen: %d realLen: %d secOffset: %d uSecOffset: %d ]",
            capturedLen, realLen, secondsOffset, uSecondsOffset
        );
        return string(buff);
    }
}
