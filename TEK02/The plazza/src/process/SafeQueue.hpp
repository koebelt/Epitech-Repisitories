/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** SafeQueue
*/

#ifndef SAFEQUEUE_HPP_
#define SAFEQUEUE_HPP_

#include <queue>

#include "./Mutex.hpp"
#include "./ScopedLock.hpp"

template <typename T>
class ISafeQueue {
    public:
        virtual ~ISafeQueue() = default;
        virtual void push(T value) = 0;
        virtual bool tryPop(T &value) = 0;
    protected:
    private:
};

template <typename T>
class SafeQueue : public ISafeQueue<T> {
    public:

        void push(T value) {
            ScopedLock lock(_mutex);
            _elements.push(value);
        }

        bool tryPop(T &value) {
            ScopedLock lock(_mutex);
            if (_elements.empty())
                return (false);
            value = _elements.front();
            _elements.pop();
            return (true);
        }

        int size() { return _elements.size(); };

        std::queue<T> getQueue() { return _elements; };

        SafeQueue &operator=(const SafeQueue &el) = delete;

    protected:
    private:
        Mutex _mutex;
        std::queue<T> _elements;
};


#endif /* !SAFEQUEUE_HPP_ */
