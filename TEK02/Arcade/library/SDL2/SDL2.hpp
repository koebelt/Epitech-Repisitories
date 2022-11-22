/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** SDL2
*/

#ifndef LIBNCURSES_HPP_
#define LIBNCURSES_HPP_

#include "../ILibrary.hpp"
#include "iostream"
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <filesystem>

namespace arcade
{
    class SDL2 : public ILibrary {
        public:
            SDL2();
            ~SDL2();

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
                SDL_Window *_win;
                SDL_Renderer *_render;
                SDL_Color _color{255, 255, 255, 255};
                TTF_Font *_font;
                int _last_event = 0;
                int _timeout = 350;
                int _quit = 0;
                std::chrono::steady_clock::time_point _time_elapsed;
                std::vector<std::shared_ptr<Property>> _props = {};
    };
}
extern "C" std::shared_ptr<arcade::SDL2> allocatorGraphic() { return std::make_shared<arcade::SDL2>(); }

#endif /* !LIBNCURSES_HPP_ */
