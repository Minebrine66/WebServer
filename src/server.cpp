#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <locale>

#include <netinet/in.h>
#include <sys/socket.h>

using std::cout;
using std::endl;
using std::cerr;

#define UINT16_MAX 65535

// Converts String to Int
uint16_t strToInt(char argv[])
{
    // checks if argument has all numerical chars
    std::string arg(argv);
    if (arg.find_first_not_of("0123456789") == std::string::npos)
    {
        // converts to number in base 10
        long num = std::stoi(argv);
        // performs check if number is malformed or out of bounds
        if (num < 0 || num > UINT16_MAX)
        {
            return 0;
        }
        return num;
    }
    else
    {
        return 0;
    }
}

// Returns file descriptor of socket 
int create_socket(uint16_t port)
{
    // Create socket
    int serverSocketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocketFd < 0)
    {
        // failed to create socket, error out
        return -1;
    }

    sockaddr_in serverIP;
    serverIP.sin_family = AF_INET;
    serverIP.sin_port = htons(port);
    serverIP.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(serverSocketFd, (struct sockaddr*)&serverIP, sizeof(serverIP)) < 0)
    {
        // failed to bind, error out 
        return -2;
    }
    // Set socket to listening socket
    if (listen(serverSocketFd, 500) < 0)
    {
        // failed to set socket as listening, error out
        return -3;
    }
    
    // Socket is good to go, return fd
    return serverSocketFd;
}

int main(int argc, char* argv[])
{
    // checks if port number has been specified
    if(argc != 2)
    {
        cerr << "ERROR: Invalid arguments!\nusage: ./server <port_num>" << endl;
        return -1;
    }
    uint16_t port = strToInt(argv[1]);
    // checks if port number is within valid range
    if (port == 0)
    {
        cerr << "ERROR: Port number out of range!" << endl;
        return -1;
    }

    int sockfd = create_socket(port);
    switch (sockfd)
    {
        // check if socket can be created
        case -1: 
            cerr << "ERROR: Unable to create socket!" << endl;
            return -1;
        // check if socket can be binded
        case -2: 
            cerr << "ERROR: Unable to bind socket!" << endl;
            return -1;
        // check if socket is set as listening socket
        case -3:
            cerr << "ERROR: Unable to set socket as listening!" << endl;
            return -1;
    }       


    cout << "test" << endl;
    return 0;
}