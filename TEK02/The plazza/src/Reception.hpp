/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include <list>
#include <algorithm>
#include "./Kitchen.hpp"
#include "./process/Thread.hpp"
#include "./process/Process.hpp"
#include "./process/Serialization.hpp"
#include <memory>

#define REGEX "(^(status|((regina|fantasia|margarita|americana) (S|M|L|XL|XXL) (x[1-9][0-9]*)(; )?)+))$"

namespace plz {
    class Reception {
        public:
            Reception();
            std::vector<Process> getKitchens() { return _kitchens; };
            void removeKitchen(pid_t pid) { _kitchens.erase(std::remove_if(_kitchens.begin(), _kitchens.end(), [&pid](const Process &process) {
                return process.getPid() == pid;
            }), _kitchens.end());};
            void sendOrder(std::queue<Pizza> order);
            void launch();

        protected:
        private:
            std::vector<Process> _kitchens;
            std::map<pid_t, ThreadPool<pid_t>> _listeners;
    };
}

#endif /* !RECEPTION_HPP_ */
