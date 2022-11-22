/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <mutex>
#include <memory>

class Mutex {
    public:
        Mutex() = default;

        void lock() { _mutex.lock(); };
        void unlock() { _mutex.unlock(); };
        void trylock() { _mutex.try_lock(); };

        Mutex &operator=(const Mutex &el) = delete;

        std::mutex &operator*() {
            return _mutex;
        };

    protected:
    private:
        std::mutex _mutex;
};

#endif /* !MUTEX_HPP_ */
