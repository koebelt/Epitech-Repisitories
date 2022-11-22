/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Listener
*/

#include "Listener.hpp"


/**
** @author : Ethan HUSSER
**
** @brief Class Listener constructor
** @param ip (std::string): Ip where you wish to connect
** @param port (int): Port where you wish to listen
**/
zappy::Listener::Listener(int port, std::string ip)
{
    std::cout << "IP: " << ip << " PORT: " << port << std::endl;
    _fd = socket(AF_INET, SOCK_STREAM, 0);
    _isServerLost = false;
    int test = 0;

    if (_fd == -1)
        throw zappy::ErrorManager("Error: Socket not created");
    if (port < 1204 && port > 65535)
        throw zappy::ErrorManager("Error: Invalid Port");
    if (inet_pton(AF_INET, ip.data(), &(&_client_addr)->sin_addr) != 1)
        throw zappy::ErrorManager("Error: Bad IP");
    _client_addr.sin_port = htons(port);
    _client_addr.sin_family = AF_INET;
    _client_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    test = connect(_fd, (struct sockaddr *) &_client_addr, sizeof(_client_addr));
    std::cout << "Test: " << test << std::endl;
    if (test == -1)
        throw zappy::ErrorManager("Error: Connect");

    _thread = std::thread(&zappy::Listener::loop, this);
}

/**
** @author : Ethan HUSSER
**
** @brief Class Listener destructor
**/
zappy::Listener::~Listener()
{
    _isFinished = true;
    close(_fd);
    _thread.join();
}

/**
** @author : Ethan HUSSER
**
** @brief Class Loop method
**/
void zappy::Listener::loop(void)
{
    while (!_isFinished) {
        timeval now = {1, 0};
        FD_ZERO(&_rfds);
        FD_SET(_fd, &_rfds);
        int status = select(FD_SETSIZE, &_rfds, NULL, NULL, &now);

        if (status == -1)
            continue;
        if (FD_ISSET(_fd, &_rfds)) {
            if (!_isConnected)
                _waitWelcome();
            else
                _listenServer();
        }
    }
}

/**
** @author : Ethan HUSSER
**
** @brief Class requestContentMap method
**/
void zappy::Listener::requestContentMap(void)
{
    int ret = 0;
    std::string body = "mct\n";

    if (FD_ISSET(_fd, &_wfds)) {
        ret = write(_fd, body.c_str(), (sizeof(char) * body.size()));
        if (ret == -1)
            return;
    }
}

/**
** @author : Ethan HUSSER
**
** @brief Class requestMapSize method
**/
void zappy::Listener::requestMapSize(void)
{
    int ret = 0;
    std::string body = "msz\n";

    if (FD_ISSET(_fd, &_wfds)) {
        ret = write(_fd, body.c_str(), (sizeof(char) * body.size()));
        if (ret == -1)
            return;
    }
}

/**
** @author : Ethan HUSSER
**
** @brief Class requestNameOfAllTeams method
**/
void zappy::Listener::requestNameOfAllTeams(void)
{
    int ret = 0;
    std::string body = "tna\n";

    if (FD_ISSET(_fd, &_wfds)) {
        ret = write(_fd, body.c_str(), (sizeof(char) * body.size()));
        if (ret == -1)
            return;
    }
}

/**
** @author : Ethan HUSSER
**
** @brief Class requestPlayerInventory method
** @param playerId (std::string): Id of the player
**/
void zappy::Listener::requestPlayerInventory(std::string playerId)
{
    int ret = 0;
    std::string body = "pin " + playerId + '\n';

    if (FD_ISSET(_fd, &_wfds)) {
        ret = write(_fd, body.c_str(), (sizeof(char) * body.size()));
        if (ret == -1)
            return;
    }
}

/**
** @author : Ethan HUSSER
**
** @brief Class requestPlayerLevel method
** @param playerId (std::string): Id of the player
**/
void zappy::Listener::requestPlayerLevel(std::string playerId)
{
    int ret = 0;
    std::string body = "plv " + playerId + '\n';

    if (FD_ISSET(_fd, &_wfds)) {
        ret = write(_fd, body.c_str(), (sizeof(char) * body.size()));
        if (ret == -1)
            return;
    }
}

/**
** @author : Ethan HUSSER
**
** @brief Class requestPlayerPosition method
** @param playerId (std::string): Id of the player
**/
void zappy::Listener::requestPlayerPosition(std::string playerId)
{
    int ret = 0;
    std::string body = "ppo " + playerId + '\n';

    if (FD_ISSET(_fd, &_wfds)) {
        ret = write(_fd, body.c_str(), (sizeof(char) * body.size()));
        if (ret == -1)
            return;
    }
}

/**
** @author : Ethan HUSSER
**
** @brief Class requestTimeUnit method
**/
void zappy::Listener::requestTimeUnit(void)
{
    int ret = 0;
    std::string body = "sgt\n";

    if (FD_ISSET(_fd, &_wfds)) {
        ret = write(_fd, body.c_str(), (sizeof(char) * body.size()));
        if (ret == -1)
            return;
    }
}

/**
** @author : Ethan HUSSER
**
** @brief Class clearQueue method
**/
void zappy::Listener::clearQueue(void)
{
    std::lock_guard<std::mutex> lock(_queueMutex);
    while (!_res.empty())
        _res.pop();
}

/**
** @author : Ethan HUSSER
**
** @brief Class _listenServer method
**/
void zappy::Listener::_listenServer(void)
{
    char c;
    int ret = 0;

    ret = read(_fd, &c, 1);
    if (ret == 0) {
        _isServerLost = true;
        sleep(3);
        exit(0);
    }
    _tmp += c;
    if (c == '\n') {
        std::lock_guard<std::mutex> lock(_queueMutex);
        _res.push(_tmp);
        _tmp.clear();
    }
}

/**
** @author : Ethan HUSSER
**
** @brief Class _waitWelcome method
**/
void zappy::Listener::_waitWelcome(void)
{
    char response[100];
    std::string result;
    std::string body = "GRAPHIC\n";
    int ret = 0;
    int ret2 = 0;

    ret = read(_fd, response, 100);
    response[ret] = '\0';
    if (ret == -1)
        return;
    result += response;
    if (result == "WELCOME\n") {
        _isConnected = true;
        ret2 = write(_fd, body.c_str(), (sizeof(char) * body.size()));
        if (ret2 == -1)
            return;
    }
}
