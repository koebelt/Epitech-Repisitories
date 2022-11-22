/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Button
*/

#pragma once

extern "C" {
    #include <raylib.h>
}
#include "../../../../math/Math.hpp"
#include <string>
#include "../../../color/Color.hpp"
#include "../text/Text.hpp"

namespace zappy {
    namespace graphic {


    class Button {
        public:
            Button(math::Rectangle rect, std::string text, int fontSize, zappy::graphic::Color color);
            Button(std::string filename, zappy::math::Vector2 pos, float scale);
            ~Button();

            bool update();


        protected:
        private:
            bool _isGraphic = false;
            int _state = 0;
            ::Texture _texture;
            ::Rectangle _rec;
            math::Rectangle _boundingBox;
            std::string _text;
            int _fontSize;
            zappy::graphic::Color _color;
    };
    }

}