/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include <iostream>


namespace istudio
{
    namespace graphic
    {
        Sprite::Sprite(Texture text, int cols, int rows)
        {
            _isLoaded = true;
            _texture = text;
            _rect = istudio::math::Rectangle(0, 0, (float)_texture.getWidth() / cols, (float)_texture.getHeight() / rows);
        }

        Sprite::Sprite(std::string text, int cols, int rows)
        {
            _isLoaded = true;
            _texture = istudio::graphic::Texture(text);
            _rect = istudio::math::Rectangle(0, 0, (float)_texture.getWidth() / cols, (float)_texture.getHeight() / rows);
        }

        void Sprite::load(Texture text, int cols, int rows)
        {
            _isLoaded = true;
            _texture = text;
            _rect = istudio::math::Rectangle(0, 0, (float)_texture.getWidth() / cols, (float)_texture.getHeight() / rows);
        }

        void Sprite::load(std::string text, int cols, int rows)
        {
            _isLoaded = true;
            _texture.load(text);
            _rect = istudio::math::Rectangle(0, 0, (float)_texture.getWidth() / cols, (float)_texture.getHeight() / rows);
        }

        void Sprite::draw(istudio::math::Vector2 pos, float scale, istudio::graphic::Color color)
        {
            if (!_isLoaded) return;
            _rect = istudio::math::Rectangle(_rect.x, _rect.y, _rect.width, _rect.height);
            _texture.draw(pos, _rect, scale, color);
        }

        void Sprite::draw(istudio::math::Vector2 pos, int row, int col, float scale, istudio::graphic::Color color)
        {
            if (!_isLoaded) return;
            _rect = istudio::math::Rectangle(_rect.width * col, _rect.height * row, _rect.width, _rect.height);
            _texture.draw(pos, _rect, scale, color);
        }

        void Sprite::drawLeft(istudio::math::Vector2 pos, float scale, istudio::graphic::Color color)
        {
            if (!_isLoaded) return;
            if (_rect.width + _rect.x >= _texture.getWidth())
                _rect = istudio::math::Rectangle(0, _rect.y, _rect.width, _rect.height);
            else
                _rect = istudio::math::Rectangle(_rect.x + _rect.width, _rect.y, _rect.width, _rect.height);
            _texture.draw(pos, _rect, scale, color);
        }

        void Sprite::drawDown(istudio::math::Vector2 pos, float scale, istudio::graphic::Color color)
        {
            if (!_isLoaded) return;
            if (_rect.height + _rect.y >= _texture.getHeight())
                _rect = istudio::math::Rectangle(_rect.x, 0, _rect.width, _rect.height);
            else
                _rect = istudio::math::Rectangle(_rect.x, _rect.y + _rect.height, _rect.width, _rect.height);
            _texture.draw(pos, _rect, scale, color);
        }

        void Sprite::unload()
        {
            if (!_isLoaded) return;
            _isLoaded = false;
            _texture.unload();
        }
    }
}
