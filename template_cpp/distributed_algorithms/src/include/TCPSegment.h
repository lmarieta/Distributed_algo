#pragma once // do not include a headfile multiple times

#include <cstdint>
using std::uint16_t;
using std::uint32_t;

class TCPSegment {
    private:
        uint16_t source_port_;
        uint16_t destination_port_;
        uint32_t sequence_number_;
        uint32_t acknowledgment_number_;
        struct control_flags {
            unsigned int header_length : 4;
            unsigned int reserved : 6;
            unsigned int URG : 1;
            unsigned int ACK : 1;
            unsigned int PSH : 1;
            unsigned int RST : 1;
            unsigned int SYN : 1;
            unsigned int FIN : 1;
        } control_flags_;
        uint16_t checksum_;
        uint16_t urgent_pointer_;
    public:
        uint16_t getSourcePort();
        control_flags getControl_Flags();
        TCPSegment(uint16_t source_port=0, uint16_t destination_port=0, uint32_t sequence_number=0,\
        uint32_t acknowledgment_number=0, control_flags control_flags_={0, 0, 0, 0, 0, 0, 0, 0},\
        uint16_t checksum=0, uint16_t urgent_pointer=0);
};