#include "TCPSegment.h"

TCPSegment::TCPSegment(uint16_t source_port, uint16_t destination_port, uint32_t sequence_number,\
        uint32_t acknowledgment_number, TCPSegment::control_flags control_flags,uint16_t checksum, \
        uint16_t urgent_pointer): source_port_(source_port), destination_port_(destination_port),\
        sequence_number_(sequence_number), acknowledgment_number_(acknowledgment_number), \
        control_flags_(control_flags), checksum_(checksum), urgent_pointer_(urgent_pointer) {}
uint16_t TCPSegment::getSourcePort() {return source_port_;}
TCPSegment::control_flags TCPSegment::getControl_Flags() {return control_flags_;}