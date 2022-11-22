/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** TextBox
*/

#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_

#include "./Text.hpp"
#include "../sprite/Sprite.hpp"
#include <string>
#include "../../../../../game/utils/Timer.hpp"

namespace istudio {
    namespace graphic {
        class TextBox {
            public:
                TextBox() = default;
                ~TextBox();

                std::string getContent() { return _content; };

                void load(std::string texture, int cols, int rows, int fontSize, istudio::graphic::Color textColor, std::string text = "", int maxChar = -1);
                void unload();
                void update(int key);
                void update();
                void setText(std::string text);
                void draw(istudio::math::Vector2 pos, float scale, istudio::graphic::Color color, float px, float py, int maxCharDisplayed = -1);
                std::string getText() { return _text; };
            private:
                std::string _content;
                std::string _text;
                istudio::Font _font;
                Sprite _sprite;
                bool _isLoaded = false;
                int _fontSize;
                istudio::graphic::Color _textColor;
                Timer _timer;
                int _maxChar;
        };
    }
}

#endif /* !TEXTBOX_HPP_ */
