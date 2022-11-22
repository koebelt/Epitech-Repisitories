/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** LinuxServer
*/

#ifndef LINUXSERVER_HPP_
#define LINUXSERVER_HPP_

#include "../IServer.hpp"

extern "C" {
    
};

namespace istudio {
    class LinuxServer : public IServer {
        public:
            LinuxServer();
            ~LinuxServer();

            void create();
            void start();
        protected:
        private:
    };
}

#endif /* !LINUXSERVER_HPP_ */
