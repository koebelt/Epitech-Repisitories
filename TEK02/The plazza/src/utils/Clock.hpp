/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <chrono>

class Clock {
    public:
        Clock() = default;
        Clock(int timeInMillisecond) : _started(false), _timeInMillisecond(timeInMillisecond) {};

        void stop() {
            _started = false;
        };
        void start() {
            _started = true;
            _lastTime = std::chrono::steady_clock::now();
        };
        bool hasStarted() { return _started; };
        bool hasReached() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - _lastTime).count() >= _timeInMillisecond; }
    protected:
    private:
        int _timeInMillisecond;
        std::chrono::steady_clock::time_point _lastTime;
        bool _started;
};

#endif /* !CLOCK_HPP_ */
