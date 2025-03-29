#include <unistd.h>
#include <iostream>
#include <stdexcept>

#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char* argv[])
{
    try 
    {
        if(argc != 2) 
        {
            throw std::runtime_error(
                "Invalid arguments.\nusage: ./server <port_num>");
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception " << e.what() << std::endl;
        return -1;
    }
    std::cout << "test" << std::endl;
    return 0;
}