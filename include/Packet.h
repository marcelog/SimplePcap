#ifndef __SimplePcap_Packet_h__
#define __SimplePcap_Packet_h__

#include <string>

using namespace std;
namespace SimplePcapNs {
    class Packet
    {
        private:
            int capturedLen;
            int realLen;
            int secondsOffset;
            int uSecondsOffset;
            string data;
        public:
            string __toString();
            int getSecondsOffset();
            int getMicroSecondsOffset();
            int getRealLen();
            int getCapturedLen();
            string getData();
            Packet(
                int capturedLen = 0,
                int realLen = 0,
                int secOffset = 0,
                int uSecOffset = 0,
                u_char *data = NULL
            );
    };
}
#endif

