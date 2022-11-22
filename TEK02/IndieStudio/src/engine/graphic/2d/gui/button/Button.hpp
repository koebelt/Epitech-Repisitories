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

namespace istudio {
    namespace graphic {


    class Button {
        public:
            Button() {};
            Button(math::Rectangle rect, std::string text, int fontSize, istudio::graphic::Color color);
            Button(std::string filename, istudio::math::Vector2 pos, float scale = 1, int states = 1);
            ~Button();

            void load(std::string filename, istudio::math::Vector2 pos, float scale = 1, int states = 1);
            bool update();
            void unload();


        protected:
        private:
            bool _isLoaded = false;
            bool _isGraphic = false;
            int _state = 0;
            int _states = 1;
            float _scale;
            ::Texture _texture;
            ::Rectangle _rec;
            math::Rectangle _boundingBox;
            std::string _text;
            int _fontSize;
            istudio::graphic::Color _color;
    };

    }

}