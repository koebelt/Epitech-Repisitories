/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-paul.gazeau-rousseau
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
#define THREADPOOL_HPP_

    #include <condition_variable>
    #include <queue>
    #include <functional>
    #include <deque>

    #include "./Thread.hpp"
    #include "./Mutex.hpp"
    #include "./ScopedLock.hpp"
    #include "./Conditional.hpp"

    #include "../utils/Reference.hpp"
    #include "../food/Pizza.hpp"

namespace plz {
    template <typename T>
    class ThreadPool {
    public:
        ThreadPool() = default;
        ~ThreadPool() = default;

        ThreadPool(const std::function<void(T *)> &job, T &element) {
            addJob(job, element);
            start();
        };

        void start()
        {
            const uint32_t num_threads = std::thread::hardware_concurrency();
            _threads.resize(num_threads);
            uint32_t i = 0;
            for (; i < _elements.size(); i++)
                _threads[_idx + i] = Thread(std::bind(&ThreadPool::loop, this));
            _idx += i;
        };

        void addJob(const std::function<void(T *)> &job, T element)
        {
            {
                ScopedLock lock(_mutex);
                _jobs.push(job);
                _elements.push_back(std::move(element));
            }
            _condition.notify_one();
        };

        void stop()
        {
            {
                ScopedLock lock(_mutex);
                _terminate = true;
            }
            _condition.notify_all();
            for (Thread &active_thread : _threads)
                active_thread.join();
            _threads.clear();
        }

        int getSize() { return _jobs.size(); };
        int getNumbers() { return _elements.size(); };
        T &operator[](int idx) { return _elements[idx]; }
        std::deque<T> &getElements() { return _elements; };

    private:
        void loop()
        {
            int i = -1;
            while (true)
            {
                std::function<void(T *)> job;
                {
                    std::unique_lock<std::mutex> lock(*_mutex);
                    _condition.wait(lock, [this] { return !_jobs.empty() || _terminate; });
                    if (_terminate)
                        return;
                    job = _jobs.front();
                    _jobs.pop();
                    i++;
                }
                job(&_elements[i]);
            }
        }
        bool _terminate = false;
        Mutex _mutex;
        Conditional _condition;
        std::vector<Thread> _threads;
        std::queue<std::function<void(T *)>> _jobs;
        std::deque<T> _elements;
        int _idx = 0;
    };
}

#endif /* !THREADPOOL_HPP_ */
