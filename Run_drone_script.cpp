#include "ctello.h"
#include <iostream>
#include <unistd.h>

using ctello::Tello;

int main()
{
    Tello tello{};

    if(!tello.Bind())
    {
        return 0;
    }

    std::optional<std::string> response;

    tello.SendCommand("takeoff");
    do
    {
        response = tello.ReceiveResponse();
    } while (!response);

    for (size_t i = 0; i < 4; i++)
    {
        tello.SendCommand("rc 0 30 0 0");
        std::cout << "rc 0 30 0 0" << std::endl;
        usleep(500000);
        do
        {
            response = tello.ReceiveResponse();
        } while (!response);
        std::cout << *response << std::endl;

        tello.SendCommand("cw 90");
        std::cout << "cw 90" << std::endl;
        do
        {
            response = tello.ReceiveResponse();
        } while (!response);
        std::cout << *response << std::endl;

        tello.SendCommand("rc 0 30 0 0");
        std::cout << "rc 0 30 0 0" << std::endl;
        usleep(500000);
        do
        {
            response = tello.ReceiveResponse();
        } while (!response);
        std::cout << *response << std::endl;


        tello.SendCommand("cw 180");
        std::cout << "cw 180" << std::endl;
        do
        {
            response = tello.ReceiveResponse();
        } while (!response);
        std::cout << *response << std::endl;
    }
    
    tello.SendCommand("land");
    std::cout << "land" << std::endl;
    do
    {
        response = tello.ReceiveResponse();
    } while (!response);
    std::cout << *response << std::endl;

    return 0;
}