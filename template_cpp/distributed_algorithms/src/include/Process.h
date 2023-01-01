#pragma once // do not include a headfile multiple times

#include <cstdint>
#include <vector>
#include "UDPSegment.h"
using std::uint32_t;
using std::uint16_t;
using std::vector;

class Process
{
private:
    uint32_t ipaddress_;//ipv4, An Internet Protocol address (IP address) is the logical address of our network hardware by which other devices identify it in a network. IP address stands for Internet Protocol address which is an unique number or a numerical representation that uniquely identifies a specific interface on the network. Each device that is connected to internet an IP address is assigned to it for its unique identification
    uint16_t port_;//Port number is the part of the addressing information used to identify the senders and receivers of messages in computer networking. Different port numbers are used to determine what protocol incoming traffic should be directed to. Port number identifies a specific process to which an Internet or other network message is to be forwarded when it arrives at a server. Ports are identified for each protocol and It is considered as a communication endpoint. 
    vector<UDPSegment> messages_;
public:
    Process(uint32_t ipaddress=0,uint16_t port=0,vector<UDPSegment> messages=vector<UDPSegment>());
    ~Process();
};
