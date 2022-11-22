/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** ErrorManager
*/

#ifndef ERRORMANAGER_HPP_
#define ERRORMANAGER_HPP_

#include <exception>
#include <string>

class ErrorManager : public std::exception {
    public:
        ErrorManager(const std::string &msg) { _msg = msg; }
        ~ErrorManager() = default;

        const char *what() const throw() { return _msg.c_str(); };
    protected:
    private:
        std::string _msg;
};

#endif /* !ERRORMANAGER_HPP_ */
