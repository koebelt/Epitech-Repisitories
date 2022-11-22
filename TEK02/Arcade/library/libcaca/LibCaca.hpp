/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** LibCaca
*/

#ifndef LIBNCURSES_HPP_
#define LIBNCURSES_HPP_

#include "../ILibrary.hpp"
#include "iostream"
#include <chrono>
#include "caca.h"
#include <filesystem>

namespace arcade
{
    class LibCaca : public ILibrary {
        public:
            LibCaca();
            ~LibCaca();

            bool isOpen() override;
            std::shared_ptr<arcade::Event> getCurrentEvent() override;
            float getTimeElapsed() override;
            void resetTimer() override;
            void render(Matrix matrix) override; // Render management
            void render();
            void close() override;
            void init() override;
            int loadProperties(std::vector<std::shared_ptr<Property>>) override;
            const std::string getName() const override;
            void setProp(char c);

            protected:
            private:
                caca_canvas_t *_cv;
                caca_display_t *_dp;
                int _last_event = 0;
                int _timeout = 350000;
                int _quit = 0;
                std::chrono::steady_clock::time_point _time_elapsed;
                std::vector<std::shared_ptr<Property>> _props = {};
    };
}
extern "C" std::shared_ptr<arcade::LibCaca> allocatorGraphic() { return std::make_shared<arcade::LibCaca>(); }

#endif /* !LIBNCURSES_HPP_ */
