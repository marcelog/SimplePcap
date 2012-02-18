#ifndef __SimplePcap_Exception_h__
#define __SimplePcap_Exception_h__

#include <stdexcept>
#include <string>

using namespace std;
namespace SimplePcapNs {
    class GenericPcapException : public runtime_error {
        public:
            explicit GenericPcapException(const string& err);
    };

    class CouldNotOpenDeviceException : public GenericPcapException {
        public:
            explicit CouldNotOpenDeviceException(const string& deviceName, const string& err);
    };

    class FilterException : public GenericPcapException {
        public:
            explicit FilterException(const string& filter, const string& err);
    };
}
#endif

