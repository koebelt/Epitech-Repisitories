/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-paul.gazeau-rousseau
** File description:
** Process
*/

#ifndef PROCESS_HPP_
#define PROCESS_HPP_

    #pragma once

    #include "../utils/PlazzaError.hpp"
    #include "../Kitchen.hpp"
    #include <functional>
    #include <memory>
    #include <iostream>

    extern "C" {
        #include <unistd.h>
    }


    namespace plz
    {
        class Process
        {
        public:
            Process() {
                pid_t child;

                if (!(child = fork())) {
                    {
                        std::unique_ptr<Kitchen> el = std::make_unique<Kitchen>(getpid());
                    }
                    exit(0);
                } else {
                    _pid = child;
                }
            };
            ~Process() = default;

            Process &operator=(const Process &el) {
                _pid = el._pid;
                return *this;
            };

            pid_t getPid() const { return _pid; };

        protected:
        private:
            pid_t _pid;
    };
}

#endif /* !PROCESS_HPP_ */
