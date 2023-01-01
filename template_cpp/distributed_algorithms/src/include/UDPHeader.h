// The UDPHeader object contains the following information: 1. The information that is required to 
//send the segment at the correct destination. 2. The information that is required to support 
//the protocol specific features.

#pragma once // do not include a headfile multiple times

#include <cstdint>
using std::uint16_t;

class UDPHeader {
    private:
        uint16_t source_port_;
        uint16_t destination_port_;
        uint16_t length_;
        uint16_t checksum_;
    public:
        UDPHeader(uint16_t source_port=0,uint16_t destination_port=0,uint16_t length=0\
        ,uint16_t checksum=0);
};