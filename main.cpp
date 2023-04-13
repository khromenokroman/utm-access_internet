#include<iostream>
#include "header.h"

using namespace std;

string const PATH = "/opt/utm/transport/conf/transport.properties";
// string const PATH = "transport.properties";
int main()
{
    try
    {
        if (!read_conf(PATH))
        {
            replace_conf(PATH);
            restart_service("utm");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

}