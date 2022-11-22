/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Sprite
*/

#pragma once

extern "C" {
    #include <raylib.h>
}
#include "../2d.hpp"
#include "../../../math/Math.hpp"

namespace istudio {
    namespace graphic {
        class Sprite {
            public:
                Sprite(){};
                Sprite(Texture text, int cols, int rows);
                Sprite(std::string text, int cols, int rows);
                ~Sprite() = default;

                void load(Texture text, int cols, int rows);
                void load(std::string text, int cols, int rows);
                void draw(istudio::math::Vector2 pos, float scale, istudio::graphic::Color color);
                void draw(istudio::math::Vector2 pos, int rows, int cols, float scale, istudio::graphic::Color color);
                void drawLeft(istudio::math::Vector2 pos, float scale, istudio::graphic::Color color);
                void drawDown(istudio::math::Vector2 pos, float scale, istudio::graphic::Color color);
                void unload();
                istudio::math::Rectangle *getRect() {return &_rect;};

            protected:
            private:
                bool _isLoaded = false;
                Texture _texture;
                istudio::math::Rectangle _rect;
        };

    }
}
