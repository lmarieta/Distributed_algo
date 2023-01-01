#pragma once // do not include a headfile multiple times

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <vector>

using std::vector;

class Node{
    private:
    int sockfd_; // socket descriptor
    int port_; // port number
    struct sockaddr_in address_;
    vector<const void*> data_;// data vector
    public:
    Node(int port=0);
    int CreateSocket();
    int ConnectToNode();
    ssize_t SendToNode(const void* data, unsigned int data_size);
    struct sockaddr_in getNodeAddress();
    void EstablishLink(Node* node);
    void RequestLink(Node* node);
    void HandleRequest(Node* node);
    void HandleLinkFail(Node* node);
    ~Node();
};