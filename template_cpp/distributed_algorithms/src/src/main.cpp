#include <chrono>
#include <iostream>
#include <thread>
#include <climits>   // CHAR_BIT
#include <cstddef>   // std::size_t
#include <typeinfo>
#include "parser.hpp"
#include "hello.h"
#include <signal.h>
#include "Node.h"

using std::cout;
using std::endl;

template <typename T>
constexpr std::size_t
bit_size() noexcept
{
  return sizeof(T) * CHAR_BIT;
}

static void stop(int) {
  // reset signal handlers to default
  signal(SIGTERM, SIG_DFL);
  signal(SIGINT, SIG_DFL);

  // immediately stop network packet processing
  std::cout << "Immediately stopping network packet processing.\n";

  // write/flush output file if necessary
  std::cout << "Writing output.\n";

  // exit directly from signal handler
  exit(0);
}

int main(int argc, char **argv) {

  signal(SIGTERM, stop);
  signal(SIGINT, stop);

  // `true` means that a config file is required.
  // Call with `false` if no config file is necessary.
  bool requireConfig = true;

  Parser parser(argc, argv);
  parser.parse();

  hello();
  std::cout << std::endl;

  std::cout << "My PID: " << getpid() << "\n";
  std::cout << "From a new terminal type `kill -SIGINT " << getpid() << "` or `kill -SIGTERM "
            << getpid() << "` to stop processing packets\n\n";

  std::cout << "My ID: " << parser.id() << "\n\n";

  std::cout << "List of resolved hosts is:\n";
  std::cout << "==========================\n";
  auto hosts = parser.hosts();
  for (auto &host : hosts) {
    std::cout << host.id << "\n";
    std::cout << "Human-readable IP: " << host.ipReadable() << "\n";
    std::cout << "Machine-readable IP: " << host.ip << "\n";
    std::cout << "Human-readable Port: " << host.portReadable() << "\n";
    std::cout << "Machine-readable Port: " << host.port << "\n";
    std::cout << "\n";
  }
  std::cout << "\n";

  std::cout << "Path to output:\n";
  std::cout << "===============\n";
  std::cout << parser.outputPath() << "\n\n";

  std::cout << "Path to config:\n";
  std::cout << "===============\n";
  std::cout << parser.configPath() << "\n\n";

  std::cout << "Doing some initialization...\n\n";

  //TEST TO BE DELETED
  // Create a socket
  Node tmp(64042);
  Node tmp2(63786);

  struct sockaddr_in aa = tmp.getNodeAddress();

  cout << "HREE" <<aa.sin_port<< endl;

  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
      // Error creating socket
      return 1;
  }

  // Set up the destination address and port number
  struct sockaddr_in dest_addr;
  dest_addr.sin_family = AF_INET;
  dest_addr.sin_port = htons(64042);  // Port number in network byte order
  dest_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // Destination IP address

  // Set up the data to be sent
  std::string data = "Hello, world!";
  size_t data_size = data.size();

  // Send the data
  ssize_t sent_bytes = sendto(sockfd, data.c_str(), data_size, 0, \
  reinterpret_cast<sockaddr*>(&dest_addr), sizeof(dest_addr)); \
  // Use ssize_t because error returns negative value. data.c_str() is of type const void*,
  // i.e. a pointer to any type. Last parameter is of type socklen_t, i.e. size of a socket
  // address structure
  if (sent_bytes < 0) {
      // Error sending data
      cout << "Allah est grand"<<endl;
      return 1;
  }

  // Close the socket
  close(sockfd);
  //

  std::cout << "Broadcasting and delivering messages...\n\n";

  // After a process finishes broadcasting,
  // it waits forever for the delivery of messages.
  while (true) {
    std::this_thread::sleep_for(std::chrono::hours(1));
  }

  return 0;
}
