// The UDPSegment object encapsulates a udp header and data. Currently only data format is string.

#pragma once // do not include a headfile multiple times

#include <string>
#include "UDPHeader.h"
using std::string;

class UDPSegment {
    private:
        UDPHeader udpheader_; //might code it as a class instead
        string data_;//code something robust to data type
    public:
        UDPSegment(UDPHeader udpheader_ = UDPHeader(0,0,0,0),string data=std::string());
};