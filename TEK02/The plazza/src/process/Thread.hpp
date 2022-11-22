/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** IThread
*/

#ifndef ITHREAD_HPP_
#define ITHREAD_HPP_

#pragma once

#include <thread>
#include <functional>
#include <iostream>

#include "../utils/PlazzaError.hpp"
#include "../Cook.hpp"

namespace plz {

    class Thread {
        public:
            Thread() = default;
            Thread(std::function<void ()> fn) : _thread(std::thread(fn)), _exist(true) {
                _function = fn;
            }

            ~Thread() = default;

            Thread(const Thread&) = delete;
            Thread& operator=(const Thread&) = delete;
            Thread(Thread && obj) : _thread(std::move(obj._thread)), _exist(true) {};
            Thread &operator=(Thread &&obj) noexcept {
                if (_exist) join();
                _thread = std::move(obj._thread);
                _exist = true;
                return *this;
            };

            void join() { if (_thread.joinable()) _thread.join(); };
        protected:
        private:
            std::thread _thread;
            std::function<void ()> _function;
            bool _exist = false;
    };
}

#endif /* !ITHREAD_HPP_ */
