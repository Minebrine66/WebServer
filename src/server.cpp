#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include <string>

#include <netinet/in.h>
#include <sys/socket.h>

using std::cout;
using std::endl;
using std::cerr;

uint16_t strToInt(char argv[])
{
    //char *last;
    //converts to number in base 10
    long num = std::stoi(argv, nullptr, 10);
    //performs check if number is malformed or out of bounds
    cout << num << endl;
    if (num < 0 || num > UINT16_MAX)
    {
        return 0;
    }
    return num;
}

int main(int argc, char* argv[])
{
    //checks if port number has been specified
    if(argc != 2)
    {
        cerr << "Invalid arguments!\nusage: ./server <port_num>" << endl;
        return -1;
    }
    //converts provided argument into int
    uint16_t port = strToInt(argv[1]);
    if (port == 0)
    {
        cerr << "Invalid port number!" << endl;
        return -1;
    }


    cout << "test" << endl;
    return 0;
}