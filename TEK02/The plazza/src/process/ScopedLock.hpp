/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** ScopedLock
*/

#ifndef SCOPEDLOCK_HPP_
#define SCOPEDLOCK_HPP_

#include "./Mutex.hpp"

class ScopedLock {
    public:
        ScopedLock(Mutex &mutex) : _mutex(mutex) { _mutex.lock(); };
        ~ScopedLock() { _mutex.unlock(); };

        ScopedLock &operator=(const ScopedLock &el) = delete;
        ScopedLock(const ScopedLock &el) = delete;

    protected:
    private:
        Mutex &_mutex;
};

#endif /* !SCOPEDLOCK_HPP_ */
