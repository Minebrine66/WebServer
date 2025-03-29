#include <unistd.h>
#include <iostream>
#include <stdexcept>

#include <netinet/in.h>
#include <sys/socket.h>

using std::cout;
using std::endl;


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
        cout << "Exception " << e.what() << endl;
        return -1;
    }
    cout << "test" << endl;
    return 0;
}