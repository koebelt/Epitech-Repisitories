/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Reception
*/

#include "Reception.hpp"
#include "iostream"
#include <regex>
#include "./food/Pizza.hpp"
#include "./utils/PlazzaError.hpp"
#include "./process/Process.hpp"
#include <cctype>
#include <algorithm>

namespace plz
{
    void Reception::launch()
    {
        std::string str;

        auto isValidInput = [](std::string line)
        {
            return (std::regex_match(line, std::regex(REGEX)));
        };

        auto getPizzaType = [](std::string pizzaName) -> plz::PizzaType
        {
            const std::map<std::string, PizzaType> infos = {
                {"regina", PizzaType::Regina},
                {"fantasia", PizzaType::Fantasia},
                {"margarita", PizzaType::Margarita},
                {"americana", PizzaType::Americana}};

            for (auto it = infos.begin(); it != infos.end(); it++)
            {
                std::transform(pizzaName.begin(), pizzaName.end(), pizzaName.begin(), [](unsigned char c)
                               { return std::tolower(c); });
                if (it->first == pizzaName)
                    return (it->second);
            }
            throw PlazzaError("Invalid Pizza !");
        };

        auto getPizzaSize = [](std::string pizzaSize) -> plz::PizzaSize
        {
            const std::map<std::string, PizzaSize> infos = {
                {"S", PizzaSize::S},
                {"M", PizzaSize::M},
                {"L", PizzaSize::L},
                {"XL", PizzaSize::XL},
                {"XXL", PizzaSize::XXL}};

            for (auto it = infos.begin(); it != infos.end(); it++)
            {
                if (it->first == pizzaSize)
                    return (it->second);
            }
            throw PlazzaError("Invalid Pizza !");
        };

        // TODO: Pourquoi 10 pizzas max et pourquoi defois le bon nombre n'est pas très bien envoyer ?
        auto parseOrder = [&getPizzaType, &getPizzaSize](std::string line) -> std::queue<Pizza>
        {
            std::stringstream stream(line);
            std::queue<Pizza> pizzas;
            std::string pizzaName, pizzaSize, pizzaCount;

            stream >> pizzaName;
            stream.str() += pizzaName.size();
            stream >> pizzaSize;
            stream.str() += pizzaSize.size();
            stream >> pizzaCount;
            stream.str() += pizzaCount.size();

            for (int count = std::atoi(pizzaCount.erase(0, 1).c_str()); count > 0; count--)
                pizzas.push(Pizza(getPizzaType(pizzaName), getPizzaSize(pizzaSize)));
            return pizzas;
        };

        auto displayStatus = [=]()
        {
            if (_kitchens.size() == 0)
                Logger::no_statuses();
            for (int i = 0; i < _kitchens.size(); i++) {
                IPCPipe("reception-print-status", _kitchens[i].getPid()) << std::string("1");
            }
        };

        while (1)
        {
            std::getline(std::cin, str);
            if (std::cin.eof())
                exit(0);
            Logger::log_cmd(str);
            if (!isValidInput(str))
                continue;
            if (str == "status")
                displayStatus();
            else
            {
                int count = 0;

                for (int i = 0; (i = str.find("; ", i)) != std::string::npos; i++)
                    count++;
                if (count == 0)
                    sendOrder(parseOrder(str));
                else
                    for (int i = 0; i <= count; ++i)
                    {
                        std::string order = str.substr(0, str.find("; "));
                        str.erase(0, str.find("; ") + 2);
                        sendOrder(parseOrder(order));
                    }
            }
        }
    }

    Reception::Reception()
    {
    }

    void Reception::sendOrder(std::queue<Pizza> order)
    {
        int kitchen_idx = 0;

        auto sendNOrder = [&order, &kitchen_idx](Process &kitchen) -> bool
        {
            IPCPipe pipe("reception-order", kitchen.getPid());
            IPCPipe pipe2("kitchen-full", kitchen.getPid());
            std::string message = "";

            pipe << std::to_string(Serialization::pack(order.front()));
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
            pipe2 >> message;

            if (message == "1") kitchen_idx++; else order.pop();
            return (message == "1" ? true : false);
        };

        auto addNewKitchen = [=, &kitchen_idx]()
        {
            _kitchens.push_back(Process());
            pid_t pid_g = _kitchens.back().getPid();
            _listeners[pid_g].addJob([=, &kitchen_idx](pid_t *pid)
                {
                    std::string message = "";

                    while (1) {
                        if ((IPCPipe("kitchen-order-finished", *pid) >> message)) {
                            if (message == "close")
                                break;
                            Logger::order_finished(Serialization::unpack(uint8_t(std::atoi(message.c_str()))));
                        }
                    }
                    removeKitchen(*pid);
                    //_listeners.erase(_listeners.find(*pid));
                }, pid_g);
            _listeners[pid_g].start();
        };

        while (!order.empty())
        {
            int nob = order.size();

            if (_kitchens.size() <= kitchen_idx)
                addNewKitchen();
            if (_kitchens.size() != 0 && nob >= _kitchens.size())
                nob /= _kitchens.size();
            for (int i = 0; i < nob && !order.empty(); i++)
                if (sendNOrder(_kitchens[kitchen_idx])) break;
        }
        std::cout << "END SENDING" << std::endl;
    }
}