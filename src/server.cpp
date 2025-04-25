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

// Converts String to Int
uint16_t strToInt(char argv[])
{
    //checks if argument has all numerical chars
    std::string arg(argv);
    if (arg.find_first_not_of("0123456789") == std::string::npos)
    {
        //converts to number in base 10
        long num = std::stoi(argv);
        //performs check if number is malformed or out of bounds
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

// Creates socket given a port number
int create_socket(uint16_t port)
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverIP;
    serverIP.sin_family = AF_INET;
    serverIP.sin_port = hton(port);
    serverIP.sin_Addr.s_addr = INADDR_ANY;

    //bind socket
    if (bind(serverSocket, (struct sockaddr*)&serverIP, sizeof(serverIP)) < 0)
    {
        
    }
    

}
int main(int argc, char* argv[])
{
    //checks if port number has been specified
    if(argc != 2)
    {
        cerr << "ERROR: Invalid arguments!\nusage: ./server <port_num>" << endl;
        return -1;
    }
    uint16_t port = strToInt(argv[1]);
    //checks if port number is valid
    if (port == 0)
    {
        cerr << "ERROR: Invalid port number!" << endl;
        return -1;
    }


    cout << "test" << endl;
    return 0;
}