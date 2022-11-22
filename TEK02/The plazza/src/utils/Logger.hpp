/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-paul.gazeau-rousseau
** File description:
** Logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

    #include "../food/Pizza.hpp"
    #include "../process/SafeQueue.hpp"
    #include "../process/ThreadPool.hpp"
    #include <iostream>
    #include <fstream>
    #include "Reference.hpp"
    #include <iostream>
    #include <fstream>
    #include <iomanip>
    #include <ctime>
    extern "C" {
        #include <unistd.h>
    }

namespace plz {

    class Logger {
        public:
            static void new_log();
            static void create_kitchen(pid_t id);
            static void create_cook();
            static void destroy_cook();
            static void destroy_kitchen(pid_t id);
            static void pizza_assigned_to_kitchen(pid_t id, Pizza pizza);
            static void pizza_assigned_to_cook(pid_t id, int cook_id, Pizza pizza);
            static void cook_finished_pizza(pid_t id, int cook_id, Pizza pizza);
            static void order_finished(Pizza pizza);
            static void stock_ready(pid_t id);
            static void stock_refilled(pid_t id);
            static void status(pid_t id, std::queue<Pizza> _pizzaQueue, std::deque<Cook> _cooks);
            static std::string get_pizza(Pizza _pizza);
            static void no_statuses();
            static void log(std::string log);
            static void log_cmd(std::string log);

        protected:
        private:
            inline static int fd;
    };

}


#endif /* !LOGGER_HPP_ */
