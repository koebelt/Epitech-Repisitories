/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** ErrorManager
*/

#pragma once

#include <exception>
#include <string>

namespace zappy {
    class ErrorManager : public std::exception {
        public:
            ErrorManager(const std::string &msg) { _msg = msg; }
            ~ErrorManager() = default;

            const char *what() const throw() { return _msg.c_str(); };
        protected:
        private:
            std::string _msg;
    };
}
