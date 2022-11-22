/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** TextBox
*/

#include "TextBox.hpp"

#include "../../../../event/keyboard/Keyboard.hpp"
#include <iostream>

istudio::graphic::TextBox::~TextBox()
{
    unload();
}

void istudio::graphic::TextBox::load(std::string texture, int cols, int rows, int fontSize, istudio::graphic::Color textColor, std::string text, int maxChar)
{
    if (_isLoaded) return;
    _isLoaded = true;
    _timer.tick();
    _sprite.load(texture, cols, rows);
    _fontSize = fontSize;
    _textColor = textColor;
    _maxChar = maxChar;
    _content = "";
    _text = text;
    _font.load("./assets/miscs/game.ttf");
}

void istudio::graphic::TextBox::unload()
{
    if (!_isLoaded) return;
    _isLoaded = false;
    _sprite.unload();
    _content.clear();
    _text.clear();
    _font.unload();
}

void istudio::graphic::TextBox::update(int key)
{
    if (_maxChar > 0 && _content.size() >= _maxChar && key != event::BACKSPACE) return;
    switch (key) {
        case event::A:
            _content += 'A';
            break;
        case event::B:
            _content += 'B';
            break;
        case event::C:
            _content += 'C';
            break;
        case event::D:
            _content += 'D';
            break;
        case event::E:
            _content += 'E';
            break;
        case event::F:
            _content += 'F';
            break;
        case event::G:
            _content += 'G';
            break;
        case event::H:
            _content += 'H';
            break;
        case event::I:
            _content += 'I';
            break;
        case event::J:
            _content += 'J';
            break;
        case event::K:
            _content += 'K';
            break;
        case event::L:
            _content += 'L';
            break;
        case event::M:
            _content += 'M';
            break;
        case event::N:
            _content += 'N';
            break;
        case event::O:
            _content += 'O';
            break;
        case event::P:
            _content += 'P';
            break;
        case event::Q:
            _content += 'Q';
            break;
        case event::R:
            _content += 'R';
            break;
        case event::S:
            _content += 'S';
            break;
        case event::T:
            _content += 'T';
            break;
        case event::U:
            _content += 'U';
            break;
        case event::V:
            _content += 'V';
            break;
        case event::W:
            _content += 'W';
            break;
        case event::X:
            _content += 'X';
            break;
        case event::Y:
            _content += 'Y';
            break;
        case event::Z:
            _content += 'Z';
            break;
        case event::ZERO:
            _content += '0';
            break;
        case event::ONE:
            _content += '1';
            break;
        case event::TWO:
            _content += '2';
            break;
        case event::THREE:
            _content += '3';
            break;
        case event::FOUR:
            _content += '4';
            break;
        case event::FIVE:
            _content += '5';
            break;
        case event::SIX:
            _content += '6';
            break;
        case event::SEVEN:
            _content += '7';
            break;
        case event::EIGHT:
            _content += '8';
            break;
        case event::NINE:
            _content += '9';
            break;
        case event::BACKSPACE:
            if (!_content.empty())
                _content.pop_back();
            break;
    }
}

void istudio::graphic::TextBox::draw(istudio::math::Vector2 pos, float scale, istudio::graphic::Color color, float px, float py, int maxCharDisplayed)
{
    std::string cli = "";

    _sprite.draw(pos, scale, color);
    _timer.tock();
    auto duration = _timer.duration();
    if (duration > 1000) {
        cli = "|";
        _timer.tick();
    }
    double total = (_sprite.getRect()->width) * scale;
    double percentX = (_sprite.getRect()->width * px);
    double percentY = (_sprite.getRect()->height * py);
    if (maxCharDisplayed > 0 && _content.size() > maxCharDisplayed)
        Text::drawText(_content.substr(_content.size() - maxCharDisplayed), pos.x + percentX, pos.y + percentY, _fontSize, _textColor);
    else if (_maxChar > 0 && _content.size() >= _maxChar)
        Text::drawText(_content, pos.x + percentX, pos.y + percentY, _fontSize, _textColor);
    else if (maxCharDisplayed < 0 && ((total / _fontSize) < _content.size()))
        Text::drawText(_content.substr(_content.size() - (total / _fontSize)) + cli, pos.x + percentX, pos.y + percentY, _fontSize, _textColor);
    else
        Text::drawText(_content + cli, pos.x + percentX, pos.y + percentY, _fontSize, _textColor);
}

void istudio::graphic::TextBox::update()
{
    if (_maxChar > 0 && _content.size() >= _maxChar) return;
    _timer.tock();
    auto duration = _timer.duration();
    if (duration < 50) return;
    if (_text.empty()) return;
    _content += _text.at(0);
    _text.erase(0, 1);
    _timer.tick();
}

void istudio::graphic::TextBox::setText(std::string text)
{
    _text = text;
    _content.clear();
}
