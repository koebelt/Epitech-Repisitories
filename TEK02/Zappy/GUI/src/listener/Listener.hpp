/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Listener
*/

#pragma once

extern "C" {
    #include <sys/socket.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <sys/select.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <stdlib.h>
}
#include <exception>
#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <iostream>

#include "../common/ErrorManager.hpp"

namespace zappy {
    class Listener {
        public:
            Listener(int port, std::string ip);
            ~Listener();
            void loop(void);
            void requestMapSize(void);
            void requestNameOfAllTeams(void);
            void requestContentMap(void);
            void requestPlayerPosition(void);
            void requestPlayerPosition(std::string playerId);
            void requestPlayerLevel(std::string playerId);
            void requestPlayerInventory(std::string playerId);
            void requestTimeUnit(void);

            void clearQueue(void);

            std::queue<std::string> getQueue() const { return _res;};
            std::mutex &getMutex() { return _queueMutex; };

            bool getIsServerLost() const { return _isServerLost;};

        protected:
        private:
            void _listenServer(void);
            void _waitWelcome(void);
            int _fd;
            struct sockaddr_in _client_addr;
            fd_set _rfds;
            fd_set _wfds;
            std::queue<std::string> _res{};
            bool _isConnected = false;
            std::string _tmp;
            std::thread _thread;
            bool _isFinished = false;
            std::mutex _queueMutex;
            bool _isServerLost;
    };
}