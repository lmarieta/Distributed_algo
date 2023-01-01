#include "Node.h"
#include <iostream>
#include <typeinfo>
#include <algorithm>

Node::Node(int port):sockfd_(CreateSocket()),port_(port){
    address_.sin_family = AF_INET;
    address_.sin_port = htons(port_);  // Port number in network byte order
    address_.sin_addr.s_addr = htonl(INADDR_ANY);  // Destination IP address
}
int Node::CreateSocket(){
    sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd_ < 0) {
        // Error creating socket
        throw std::runtime_error("Socket not created");
    }
    return sockfd_;
}
int Node::ConnectToNode(Node &dest_node){
    sockaddr_in addr = dest_node.getNodeAddress();
    int result = connect(sockfd_,reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
    if (result < 0) {
        // Connection failed, no node listening on the specified port number
        throw std::runtime_error("No node listening on port " + std::to_string(dest_node.getPort()));
    }
    return result;
}
int Node::getPort(){
    return this->port_;
}
ssize_t Node::SendToNode(Node &dest_node, void* data, unsigned int data_size){
    this->removeData(data);
    dest_node.addData(data);
    sockaddr_in addr = dest_node.getNodeAddress();
    ssize_t result = sendto(sockfd_, data, data_size, 0, \
        reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
    if (result < 0) {
        // Data not sent
        throw std::runtime_error("Data not sent");
    }
    return result;
}
struct sockaddr_in Node::getNodeAddress(){
    return this->address_;
}
void Node::setData(vector<void*> data){
    data_ = data;
}
void Node::addData(void* data){
    // Add at the end of data_
    data_.push_back(data);
}
void Node::removeData(void* data){
    // Does nothing if data not in data_
    data_.erase(std::remove(data_.begin(),data_.end(),data),data_.end());
}
vector<void*> Node::getData(){
    return data_;
}
Node::~Node(){
    close(sockfd_);
}