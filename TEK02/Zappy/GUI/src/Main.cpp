/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Main
*/

#include <iostream>
#include "display/Display.hpp"
#include "listener/Listener.hpp"
#include <thread>

void printUsage(void)
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machines; localhost by default" << std::endl;
}

int main(int argc, char **argv)
{
    std::string ip = "127.0.0.1";
    std::string av;
    int port = 0;

    if (argc == 2) {
        if ((av = argv[1]) == "-help")
            printUsage();
            return (0);
    } if (argc == 3) {
        if ((av = argv[1]) == "-p")
            port = atoi(argv[2]);
    } else if (argc == 5) {
        if ((av = argv[1]) == "-h")
            ip = argv[2];
        else if ((av = argv[3]) == "-h")
            ip = argv[4];
        else {
            printUsage();
            return (84);
        }
        if ((av = argv[3]) == "-p")
            port = atoi(argv[4]);
        else if ((av = argv[1]) == "-p")
            port = atoi(argv[2]);
    } else {
        printUsage();
        return (84);
    } if (port == 0) {
        printUsage();
        return (84);
    }
    try {
        zappy::Display display;
        zappy::Listener listener(port, ip.c_str());
        display.loop(listener);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
