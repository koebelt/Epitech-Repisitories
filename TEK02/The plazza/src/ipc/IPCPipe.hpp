/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** IPCPipe
*/

#ifndef IPCPIPE_HPP_
#define IPCPIPE_HPP_

extern "C" {
    #include <cinttypes>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/socket.h>
    #include <signal.h>
}

#include <string>
#include <memory>
#include <iostream>
#include <thread>
#include <chrono>

#include "../utils/PlazzaError.hpp"

#define BUFFER_SIZE 2048

#define READ_MODE 1
#define WRITE_MODE 2

class IPCPipe {
    public:
        // Refaire les pipes et faire en sorte qu'elle soit unique
        IPCPipe(const std::string &profile, pid_t pid) : _profile(profile + "-" + std::to_string(pid)), _path("./fifo/" + profile + "-" + std::to_string(pid)) {
            if (access(_path.c_str(), F_OK))
                mkfifo(_path.c_str(), 0777);
            signal(SIGPIPE, SIG_IGN);
        };

        ~IPCPipe() {
            unlink(_path.c_str());
        };

        bool operator<<(std::string message) {
            if (access(_path.c_str(), F_OK))
                return (false);
            int fd = open(_path.c_str(), O_WRONLY);
            if (fd == -1)
                return (false);
            write(fd, message.c_str(), message.size());
            close(fd);
            return (true);
        };
        bool operator>>(std::string &received) {
            int ret = 0;
            char buffer[BUFFER_SIZE];

            if (access(_path.c_str(), F_OK))
                return (false);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            int fd = open(_path.c_str(), O_RDONLY);
            if (fd == -1)
                return (false);
            ret = read(fd, buffer, BUFFER_SIZE);
            buffer[ret] = '\0';
            received = buffer;
            close(fd);
            return (ret > 0);
        };

        std::string getName(void) { return _path; };
        std::string getProfile(void) { return _profile; };
    protected:
    private:
        const std::string _profile;
        const std::string _path;
};

#endif /* !IPCPIPE_HPP_ */
