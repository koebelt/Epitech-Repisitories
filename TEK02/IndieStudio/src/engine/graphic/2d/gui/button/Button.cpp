/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Button
*/

#include "Button.hpp"



namespace istudio
{
    namespace graphic {

        Button::Button(math::Rectangle rect, std::string text, int fontSize, istudio::graphic::Color color) : _boundingBox(rect), _text(text), _fontSize(fontSize), _color(color)
        {
            _isLoaded = true;
        }
        
        Button::Button(std::string filename, istudio::math::Vector2 pos, float scale, int states)
        {
            _isLoaded = true;
            _isGraphic = true;
            _texture = LoadTexture(filename.c_str());
            _boundingBox = istudio::math::Rectangle(pos.x, pos.y, (_texture.width / states) * scale, _texture.height * scale);
            _states = states;
            _rec = {0, 0, (float)_texture.width / states, (float)_texture.height};
            _scale = scale;

        }

        Button::~Button()
        {
            unload();
        }
        
        void Button::load(std::string filename, istudio::math::Vector2 pos, float scale, int states)
        {
            _isLoaded = true;
            _isGraphic = true;
            _texture = LoadTexture(filename.c_str());
            _boundingBox = istudio::math::Rectangle(pos.x, pos.y, (_texture.width / states) * scale, _texture.height * scale);
            _states = states;
            _rec = {0, 0, (float)_texture.width / states, (float)_texture.height};
            _scale = scale;
        }

        /**
        ** @author : koebelt <thomas.koebel@epitech.eu>
        **
        ** @brief Function update (Class Button): Draws the button, in the right state(if the mouse hovers it) and returns if if has been pressed.
        **
        ** @return bool
        **/
        bool Button::update()
        {
            math::Vector2 mousePoint(GetMousePosition());
            ::Color color = _color.getCColor();

            if (!_isLoaded) return false;
            if (!_isGraphic) {
                if (_boundingBox.checkCollision(mousePoint)) {
                    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                        return true;
                    DrawRectangle(_boundingBox.x, _boundingBox.y, _boundingBox.width, _boundingBox.height, {color.r, color.g, color.b, (unsigned char)(color.a - 50 > 0 ? color.a - 50 : color.a)});
                } else {
                    DrawRectangle(_boundingBox.x, _boundingBox.y, _boundingBox.width, _boundingBox.height, color);
                }

                Text::drawText(_text, _boundingBox.x, _boundingBox.y, _fontSize, istudio::graphic::Color((unsigned char)abs(color.r - 255), (unsigned char)abs(color.g - 255), (unsigned char)abs(color.b - 255)));
                return false;
            } else {
                if (_boundingBox.checkCollision(mousePoint)) {
                    _state = 1;
                    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) || IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                    {
                        _state = 2;
                    }
                } else
                    _state = 0;
                if (_states != 1) {
                    _rec.x = _state * _boundingBox.width / _scale;
                    DrawTextureTiled(_texture, _rec, _boundingBox.getCRectangle(), {_rec.x - _rec.width * _state, _rec.y}, 0, _scale, {255, 255, 255, 255});
                } else
                    DrawTextureTiled(_texture, _rec, _boundingBox.getCRectangle(), {_rec.x, _rec.y}, 0, _scale, {255, 255, 255, 255});

                //DrawTextureRec(_texture, _rec, (Vector2){_boundingBox.x, _boundingBox.y}, {255, 255, 255, 255});
                if (_state == 2 && IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                    return true;
                else
                    return false;
            }
        }

        void Button::unload()
        {
            if (!_isLoaded) return;
            _isLoaded = false;
            if (!_isGraphic) return;
            UnloadTexture(_texture);
        }
    }
}