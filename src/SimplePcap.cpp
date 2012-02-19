#include <pcap.h>
#include <SimplePcap.h>

using namespace std;
namespace SimplePcapNs {
 
    SimplePcap::~SimplePcap()
    {
        if (handle != NULL) {
            pcap_close(handle);
            handle = NULL;
        }
    }

    void
    SimplePcap::close()
    {
        if (handle != NULL) {
            pcap_close(handle);
            handle = NULL;
        }
    }

    Packet *
    SimplePcap::get()
    {
        struct pcap_pkthdr header;
        u_char *data = (u_char *)pcap_next(handle, &header);
        if (data == NULL) {
            throw GenericPcapException("pcap_next() returned null");
        }
        Packet *ret = new Packet(
            header.caplen, header.len, header.ts.tv_sec, header.ts.tv_usec, data
        );
        return ret;
    }

    deviceList *
    SimplePcap::findAllDevs()
    {
        deviceList *ret = new deviceList;
        pcap_if_t *alldevs;
        pcap_if_t *d;
        char errbuf[PCAP_ERRBUF_SIZE];

        if (pcap_findalldevs(&alldevs, errbuf) == -1)
        {
            throw GenericPcapException(string(errbuf));
        }
        for (d = alldevs; d != NULL; d = d->next)
        {
            if (d->description) {
                (*ret)[d->name] = d->description;
            } else {
                (*ret)[d->name] = "";
            }
        }
        pcap_freealldevs(alldevs);
        return ret;
    }

    SimplePcap::SimplePcap(
        const string& deviceName, const string& filterString, int snapLen, int timeout
    ) {
        char errbuf[PCAP_ERRBUF_SIZE];
        this->deviceName = string(deviceName);
        this->filterString = string(filterString);
        this->snapLen = snapLen;
        handle = pcap_open_live(deviceName.c_str(), snapLen, 1, timeout, errbuf);
        if (handle == NULL) {
            throw CouldNotOpenDeviceException(deviceName, string(errbuf));
        }
        if (pcap_compile(handle, &fp, filterString.c_str(), 0, net) == -1) {
            string errorString = string(pcap_geterr(handle));
            pcap_close(handle);
            throw FilterException(filterString, errorString);
        }
        if (pcap_setfilter(handle, &fp) == -1) {
            string errorString = string(pcap_geterr(handle));
            pcap_close(handle);
            throw FilterException(filterString, errorString);
        }
    }
}

