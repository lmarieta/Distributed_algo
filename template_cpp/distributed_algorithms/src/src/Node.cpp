#include "Node.h"
#include <iostream>
#include <typeinfo>

Node::Node(int port):sockfd_(CreateSocket()),port_(port){
    address_.sin_family = AF_INET;
    address_.sin_port = htons(port_);  // Port number in network byte order
    address_.sin_addr.s_addr = htonl(INADDR_ANY);  // Destination IP address
    this->ConnectToNode();
}
int Node::CreateSocket(){
    sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd_ < 0) {
        // Error creating socket
        return 1;
    } else {
        return sockfd_;
    }
}
int Node::ConnectToNode(){
    int result = connect(sockfd_,reinterpret_cast<sockaddr*>(&address_), sizeof(address_));
    if (result < 0) {
        // Connection failed, no node listening on the specified port number
        throw std::runtime_error("No node listening on port " + std::to_string(port_));
    }
    return result;
}
ssize_t Node::SendToNode(const void* data, unsigned int data_size){
    ssize_t result = sendto(sockfd_, data, data_size, 0, \
        reinterpret_cast<sockaddr*>(&address_), sizeof(address_));
    if (result < 0) {
        // Data not sent
        throw std::runtime_error("Data not sent");
    }
    return result;
}
struct sockaddr_in Node::getNodeAddress(){
    
    return this->address_;
}
void Node::EstablishLink(Node* node){
    return;
}
void Node::RequestLink(Node* node){
    return;
}
void Node::HandleRequest(Node* node){
    return;
}
void Node::HandleLinkFail(Node* node){
    return;
}
Node::~Node(){
    close(sockfd_);
}