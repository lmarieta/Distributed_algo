#include "Process.h"

Process::Process(uint32_t ipaddress,uint16_t port,vector<UDPSegment> messages): \
ipaddress_(ipaddress),port_(port),messages_(messages){}
Process::~Process(){}