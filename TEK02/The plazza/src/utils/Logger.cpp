/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-paul.gazeau-rousseau
** File description:
** Logger
*/

#include "Logger.hpp"



namespace plz
{
    void Logger::new_log()
    {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << "\n\n-------------------------- [PLAZZA] New log from the " << std::put_time(&tm, "%d-%m-%Y at %H-%M-%S") << " --------------------------" << std::endl;
        out << "----------------- The Parameters were: Multiplier(" << Reference::_mult << "), Number of Cooks(" << Reference::_nbCooks << "), Time(" << Reference::_time << ") -----------------\n\n"
            << std::endl;
        out.close();
    }

    void Logger::create_kitchen(pid_t id)
    {
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << "A new Kitchen of " << Reference::_nbCooks << " cooks and pid " << id << " has been created." << std::endl;
        std::cout << "A new Kitchen of " << Reference::_nbCooks << " cooks and pid " << id << " has been created." << std::endl;
        out.close();
    }

    void Logger::create_cook()
    {
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << "A new Cook has been created." << std::endl;
        std::cout << "A new cook has been created." << std::endl;
        out.close();
    }

    void Logger::destroy_cook()
    {
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << "A Cook has been deleted." << std::endl;
        std::cout << "A cook has been deleted." << std::endl;
        out.close();
    }
    
    void Logger::destroy_kitchen(pid_t id)
    {
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << "The Kitchen of id " << id << " was inactive for too long and has been deleted." << std::endl;
        std::cout << "The Kitchen of id " << id << " was inactive for too long and has been deleted." << std::endl;
        out.close();
    }
    
    void Logger::pizza_assigned_to_kitchen(pid_t id, Pizza pizza)
    {
        std::string size;
        std::string type;
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        switch (pizza.getPizzaType()) {
            case PizzaType::Regina: type = "Regina "; break;
            case PizzaType::Margarita: type = "Margarita "; break;
            case PizzaType::Fantasia: type = "Fantasia "; break;
            case PizzaType::Americana: type = "Americana "; break;
        }
        switch (pizza.getSize()) {
            case PizzaSize::S: size = "S"; break;
            case PizzaSize::M: size = "M"; break;
            case PizzaSize::L: size = "L"; break;
            case PizzaSize::XL: size = "XL"; break;
            case PizzaSize::XXL: size = "XXL"; break;
        }
        out << "The Kitchen of id " << id << " has taken the Pizza " << type << size << " into it's queue." << std::endl;
        std::cout << "The Kitchen of id " << id << " has taken the Pizza " << type << size << " into it's queue." << std::endl;
        out.close();
    }
    
    void Logger::pizza_assigned_to_cook(pid_t id, int cook_id, Pizza pizza)
    {
        std::string size;
        std::string type;
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        switch (pizza.getPizzaType()) {
            case PizzaType::Regina: type = "Regina "; break;
            case PizzaType::Margarita: type = "Margarita "; break;
            case PizzaType::Fantasia: type = "Fantasia "; break;
            case PizzaType::Americana: type = "Americana "; break;
        }
        switch (pizza.getSize()) {
            case PizzaSize::S: size = "S"; break;
            case PizzaSize::M: size = "M"; break;
            case PizzaSize::L: size = "L"; break;
            case PizzaSize::XL: size = "XL"; break;
            case PizzaSize::XXL: size = "XXL"; break;
        }
        out << "The Cook " << cook_id << " of the Kitchen of id " << id << " has started to cook the pizza " << type << size << "." << std::endl;
        std::cout << "The Cook " << cook_id << " of the Kitchen of id " << id << " has started to cook the pizza " << type << size << "." << std::endl;
        out.close();
    }
    
    void Logger::cook_finished_pizza(pid_t id, int cook_id, Pizza pizza)
    {
        std::string size;
        std::string type;
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        switch (pizza.getPizzaType()) {
            case PizzaType::Regina: type = "Regina "; break;
            case PizzaType::Margarita: type = "Margarita "; break;
            case PizzaType::Fantasia: type = "Fantasia "; break;
            case PizzaType::Americana: type = "Americana "; break;
        }
        switch (pizza.getSize()) {
            case PizzaSize::S: size = "S"; break;
            case PizzaSize::M: size = "M"; break;
            case PizzaSize::L: size = "L"; break;
            case PizzaSize::XL: size = "XL"; break;
            case PizzaSize::XXL: size = "XXL"; break;
        }
        out << "The Cook " << cook_id << " of the Kitchen of id " << id << " has finished to cook the pizza " << type << size << "." << std::endl;
        std::cout << "The Cook " << cook_id << " of the Kitchen of id " << id << " has finished to cook the pizza " << type << size << "." << std::endl;
        out.close();
    }
    
    void Logger::order_finished(Pizza pizza)
    {
        std::string size;
        std::string type;
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        switch (pizza.getPizzaType()) {
            case PizzaType::Regina: type = "Regina "; break;
            case PizzaType::Margarita: type = "Margarita "; break;
            case PizzaType::Fantasia: type = "Fantasia "; break;
            case PizzaType::Americana: type = "Americana "; break;
        }
        switch (pizza.getSize()) {
            case PizzaSize::S: size = "S"; break;
            case PizzaSize::M: size = "M"; break;
            case PizzaSize::L: size = "L"; break;
            case PizzaSize::XL: size = "XL"; break;
            case PizzaSize::XXL: size = "XXL"; break;
        }
        out << "The order of " << type << size << " has been finished and served." << std::endl;
        std::cout << "The order of " << type << size << " has been finished and served." << std::endl;
        out.close();
    }

    void Logger::stock_ready(pid_t id)
    {
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << "The stock of the Kitchen " << id << " is ready." << std::endl;
        std::cout << "The stock of the Kitchen " << id << " is ready." << std::endl;
        out.close();
    }

    void Logger::stock_refilled(pid_t id)
    {
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << "The stock of the Kitchen " << id << " has been refilled." << std::endl;
        std::cout << "The stock of the Kitchen " << id << " has been refilled." << std::endl;
        out.close();
    }

    void Logger::status(pid_t id, std::queue<Pizza> pizzaQueue, std::deque<Cook> cooks)
    {
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << "\nStatus of the Kitchen of ID:  " << id << std::endl;
        std::cout << "\nStatus of the Kitchen of ID:  " << id << std::endl;

        for (int i = 0; i < cooks.size(); i++) {
            std::cout << "in the looooooop" << std::endl;
            if (cooks[i].getHoldingPizza() != nullptr) {
                out << "The cook of ID " << i << " is cooking the pizza : " << get_pizza(*cooks[i].getHoldingPizza()) << std::endl;
                std::cout << "The cook of ID " << i << " is cooking the pizza : " << get_pizza(*cooks[i].getHoldingPizza()) << std::endl;
            }
            cooks.pop_front();
        }
        if (pizzaQueue.size() > 0) {
            out << "There are still " << pizzaQueue.size() << " Pizzas the queue of this kitchen, they are:" << std::endl;
            std::cout << "There are still " << pizzaQueue.size() << " Pizzas the queue of this kitchen, they are:" << std::endl;
            while (pizzaQueue.size() > 0) {
                Pizza pizza = pizzaQueue.front();
                out << "Pizza: " << get_pizza(pizza) << std::endl;
                std::cout << "Pizza: " << get_pizza(pizza) << std::endl;
                pizzaQueue.pop();
            }
        }
        out.close();
    }

    std::string Logger::get_pizza(Pizza pizza)
    {
        std::string size;
        std::string type;

        switch (pizza.getPizzaType()) {
            case PizzaType::Regina: type = "Regina "; break;
            case PizzaType::Margarita: type = "Margarita "; break;
            case PizzaType::Fantasia: type = "Fantasia "; break;
            case PizzaType::Americana: type = "Americana "; break;
        }
        switch (pizza.getSize()) {
            case PizzaSize::S: size = "S"; break;
            case PizzaSize::M: size = "M"; break;
            case PizzaSize::L: size = "L"; break;
            case PizzaSize::XL: size = "XL"; break;
            case PizzaSize::XXL: size = "XXL"; break;
        }
        return  type + size;
    }
    
    void Logger::no_statuses()
    {
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << "No active kitchens, nothing to display." << std::endl;
        std::cout << "No active kitchens, nothing to display." << std::endl;
        out.close();
    }
    
    void Logger::log(std::string log)
    {
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << log << std::endl;
        std::cout << log << std::endl;
        out.close();
    }

    void Logger::log_cmd(std::string log)
    {
        std::ofstream out;

        out.open("./log/log.log", std::ios::app);
        out << log << std::endl;
        out.close();
    }
}