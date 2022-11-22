/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Timer
*/

#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <chrono>

namespace istudio
{
    class Timer
    {
        using timep_t = typename std::chrono::steady_clock::time_point;
        timep_t _start = std::chrono::steady_clock::now(), _end = {};

        public:
            Timer(bool enabled = false) { if (enabled) tick(); };
            void tick() {
                _end = timep_t{};
                _start = std::chrono::steady_clock::now();
            }

            void tock() { _end = std::chrono::steady_clock::now(); }

            auto duration() const {
                return std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();
            }
    };
}

#endif /* !TIMER_HPP_ */
