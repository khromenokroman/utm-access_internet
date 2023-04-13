#include<iostream>

using namespace std;

void restart_service(string service)
{
    system("supervisorctl restart utm");
}