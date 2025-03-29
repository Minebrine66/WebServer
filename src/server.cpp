#include <unistd.h>
#include <iostream>
#include <stdexcept>

#include <netinet/in.h>
#include <sys/socket.h>

using std::cout;
using std::endl;
using std::cerr;

void Argument_Size_Test(int argc)
{
    if(argc != 2) 
    {
        throw std::runtime_error(
            "Invalid arguments.\nusage: ./server <port_num>");
    }
}

int main(int argc, char* argv[])
{
    //checks if port number has been specified
    try 
    {
        Argument_Size_Test(argc);
    }
    catch (const std::exception& e)
    {
        cerr << "Exception " << e.what() << endl;
        return -1;
    }
    cout << "test" << endl;
    return 0;
}