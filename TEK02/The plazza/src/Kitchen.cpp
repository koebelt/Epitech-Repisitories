/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include "./utils/Reference.hpp"
#include "./process/Serialization.hpp"

#include <iostream>
#include <functional>

plz::Kitchen::Kitchen(pid_t pid) :
    _pid(pid),
    _clock(Clock(DIE_TIME)),
    _open(true)
{
    Logger::create_kitchen(_pid);

    _stock.addJob([=](Stock *stock) {

        while (_open) {
            std::this_thread::sleep_for(std::chrono::milliseconds(Reference::_time));
            stock->refill();
        }
    }, Stock(_pid));
    for (int i = 0; i < Reference::_nbCooks; i++)
        _cooks.addJob([=](Cook *cook) {
            std::shared_ptr<Pizza> pizza = std::make_shared<Pizza>();

            while (_open) {
                if (!_pizzaQueue.tryPop(*pizza))
                    continue;
                if (!pizza->canPack(_stock[0])) {
                    _pizzaQueue.push(*pizza);
                    continue;
                }
                cook->_holdingPizza = pizza;
                int64_t time = cook->_holdingPizza->getCookTime() * int(Reference::_mult * 1000.f);
                std::this_thread::sleep_for(std::chrono::milliseconds(time));
                ScopedLock lock(_mutex);
                pizza->pack(_stock[0]);
                IPCPipe("kitchen-order-finished", _pid) << std::to_string(Serialization::pack(*pizza));
                cook->_holdingPizza = nullptr;
            }
        }, Cook());
    _stock.start();
    _cooks.start();
    launch();
}

plz::Kitchen::~Kitchen()
{
    IPCPipe("kitchen-order-finished", _pid) << "close";
    IPCPipe("reception-print-status", _pid) << "close";
    _open = false;
    _stock.stop();
    _cooks.stop();
    _listPool.stop();
    Logger::destroy_kitchen(_pid);
}

bool plz::Kitchen::isOpen() const
{
    return _open;
}

void plz::Kitchen::launch()
{
    auto inactiveAction = [=]() {
        if (!_clock.hasStarted())
            _clock.start();
        else if (_clock.hasReached())
            return (0);
        return (1);
    };

    _listPool.addJob([=](int *) {
        std::map<const std::string, std::function<void (std::string message)>> fn = {
            {"reception-order-" + std::to_string(_pid), [=](std::string message) {
                Pizza pizza = Serialization::unpack(uint8_t(std::atoi(message.data())));
                IPCPipe("kitchen-full", _pid) << std::to_string(isFull());
                if (!isFull()) {
                    _pizzaQueue.push(pizza);
                    Logger::pizza_assigned_to_kitchen(_pid, pizza);
                }
            }}
        };

        auto order = IPCPipe("reception-order", _pid);
        while (_open) {
            std::string message = "";
            if ((order >> message)) {
                if (message == "close")
                    break;
                fn[order.getProfile()](message);
                _clock.stop();
            }
        }
    }, 0);
    _listPool.addJob([=](int *) {
        while (_open) {
            std::string message = "";
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            IPCPipe("reception-print-status", _pid) >> message;
            if (message == "close")
                break;
            Logger::status(_pid, _pizzaQueue.getQueue(), _cooks.getElements());
        }
    }, 0);

    _listPool.start();
    while (_open) {
        if (!isActive() && !inactiveAction())
            break;
        else if (isActive()) _clock.stop();
    }
}

bool plz::Kitchen::isActive()
{
    return _pizzaQueue.size() != 0 || std::any_of(_cooks.getElements().begin(), _cooks.getElements().end(), [](Cook &cook) {
        return cook.getHoldingPizza() != nullptr;
    });
}

bool plz::Kitchen::isFull()
{
    return _pizzaQueue.size() >= Reference::_nbCooks;
}