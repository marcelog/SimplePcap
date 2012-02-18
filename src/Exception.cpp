#include <stdexcept>
#include <Exception.h>

using namespace std;
namespace SimplePcapNs {
    GenericPcapException::GenericPcapException(const string& err) : runtime_error(err) {
    }

    FilterException::FilterException(const string& filter, const string& err)
        : GenericPcapException(string("Could not set filter: ") + filter + ": " + err)
    {
    }

    CouldNotOpenDeviceException::CouldNotOpenDeviceException(const string& deviceName, const string& err)
        : GenericPcapException(string("Could not open device: ") + deviceName + ": " + err)
    {
    }
}
