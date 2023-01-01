#include "UDPHeader.h"

UDPHeader::UDPHeader(uint16_t source_port,uint16_t destination_port,uint16_t length,\
uint16_t checksum):  source_port_(source_port),destination_port_(destination_port),\
length_(length),checksum_(checksum) {}
