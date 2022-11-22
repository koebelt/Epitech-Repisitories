/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** CustomError
*/

#ifndef CUSTOMERROR_HPP_
#define CUSTOMERROR_HPP_

#include <string>
#include <exception>

/**
 * @author Paul Gazeau-Rousseau
 *
 * @brief This class is used to throw error along the project
 */
namespace istudio {
    class CustomError : public std::exception {
        public:
            CustomError(const std::string &where, const std::string &msg) : _msg("[" + where + "]: " + msg) {};

            const char *what() const throw() { return _msg.c_str(); };
        protected:
        private:
         const std::string _msg;
    };
}

#endif /* !CUSTOMERROR_HPP_ */
