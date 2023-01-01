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
    vector<void*> data_;// data vector
    public:
    Node(int port=0);
    int CreateSocket();
    int ConnectToNode(Node &dest_node);
    int getPort();
    void setData(vector<void*> data);
    void addData(void* data);
    void removeData(void* data);
    ssize_t SendToNode(Node &dest_node, void* data, unsigned int data_size);
    struct sockaddr_in getNodeAddress();
    vector<void*> getData();
    ~Node();
};