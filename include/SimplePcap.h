#ifndef __SimplePcap_h__
#define __SimplePcap_h__

#include <string>
#include <map>
#include <pcap.h>
#include <Packet.h>
#include <Exception.h>

using namespace std;
namespace SimplePcapNs {
    typedef map<string, string> deviceList;

    class SimplePcap
    {
        private:
            pcap_t *handle;
            int snapLen;
            string deviceName;
            string filterString;
            struct bpf_program fp;
            bpf_u_int32 net;
        public:
            void close();
            static deviceList *findAllDevs();
            int send(string buf);
            Packet *get();
            SimplePcap(
                const string& deviceName, const string& filterString,
                int snapLen, int timeout
            );
            ~SimplePcap();
    };
}
#endif
