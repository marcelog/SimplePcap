%module(directors="1") SimplePcap
%{
#include <SimplePcap.h>
#include <vector>
using namespace SimplePcapNs;
%}

%include "std_map.i"
%include "std_string.i"
%include "typemaps.i"
%include "exception.i"

%typemap(out) SimplePcapNs::deviceList
{
    deviceList::iterator iter = $1.begin();
    deviceList::const_iterator end = $1.end();
    array_init(return_value);
    for (; iter != end; ++iter) {
        add_assoc_string(return_value, iter->first.c_str(), (char *)iter->second.c_str(), 1);
    }
}

%newobject SimplePcap::get;
%feature("director") Packet;
%feature("director") SimplePcap;
%include "include/Packet.h"
%include "include/SimplePcap.h"

