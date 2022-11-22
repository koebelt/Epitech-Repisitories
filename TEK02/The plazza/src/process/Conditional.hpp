/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** IConditional
*/

#ifndef CONDITIONAL_HPP_
#define CONDITIONAL_HPP_

#include <condition_variable>
#include <mutex>
#include <functional>

class Conditional {
    public:
        void wait(std::unique_lock<std::mutex> &lock, std::function<int ()> fn) { _conditional.wait(lock, fn); };
        void notify_one() { _conditional.notify_one(); };
        void notify_all() { _conditional.notify_all(); };
    protected:
    private:
        std::condition_variable _conditional;
};

#endif /* !CONDITIONAL_HPP_ */
