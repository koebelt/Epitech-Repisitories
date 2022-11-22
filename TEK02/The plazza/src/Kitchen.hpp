/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <vector>
#include <algorithm>
#include <map>

#include "./Cook.hpp"
#include "./Stock.hpp"

#include "./process/Mutex.hpp"
#include "./process/Thread.hpp"
#include "./process/SafeQueue.hpp"
#include "./utils/Logger.hpp"
#include "./utils/Clock.hpp"
#include "./ipc/IPCPipe.hpp"

#include "./process/ThreadPool.hpp"

extern "C" {
    #include <sys/types.h>
    #include <signal.h>
}

#define DIE_TIME 5000

namespace plz {

    class Kitchen {
        public:
            Kitchen() = default;
            Kitchen(pid_t pid);
            ~Kitchen();

            void launch();
            bool isOpen() const;
            bool isActive();
            bool isFull();
        protected:
        private:
            bool _open = false;
            pid_t _pid = -1; // PID OF THE KITCHEN
            ThreadPool<Stock> _stock; // Stock of ingredient in a thread because of independant refill
            ThreadPool<Cook> _cooks; // List of all cooks which been threaded
            ThreadPool<int> _listPool;
            SafeQueue<Pizza> _pizzaQueue; //List of all pizzas added by reception
            Mutex _mutex; // Mutex for the kitchen
            Clock _clock;
            // Friends
            friend class Cook;
    };
}

#endif /* !KITCHEN_HPP_ */
