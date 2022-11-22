/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** PlazzaError
*/

#ifndef PLAZZAERROR_HPP_
#define PLAZZAERROR_HPP_

#include <exception>
#include <string>

class PlazzaError : public std::exception {
    public:
        PlazzaError(const std::string &msg) : _msg(msg) {};

        const char *what() const throw() { return _msg.data(); };
    protected:
    private:
        const std::string _msg;
};

#endif /* !PLAZZAERROR_HPP_ */
