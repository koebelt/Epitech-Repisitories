/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Text
*/

#include "Text.hpp"

namespace zappy {
    namespace graphic {

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function drawFPS (Class Text): Function that print the fps of the game
        ** @param posX (int): X coordinate
        ** @param posY (int): Y coordinate
        **/
        void Text::drawFPS(int posX, int posY)
        {
            DrawFPS(posX, posY);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function drawText (Class Text): Function to draw a text
        ** @param text (char): Text to print
        ** @param posX (int): X coordinate
        ** @param posY (int): Y coordinate
        ** @param fontSize (int): Size of the font of the text
        ** @param color (Color): Color of the text
        **/
        void Text::drawText(std::string text, int posX, int posY, int fontSize, zappy::graphic::Color color)
        {
            DrawText(text.c_str(), posX, posY, fontSize, color.getCColor());
        }
        
        void Text::drawText(Font &font, std::string text, int posX, int posY, int fontSize, Color color)
        {
            DrawTextEx(font.getCFont()/*GetFontDefault()*/, text.c_str(), {(float)posX, (float)posY}, fontSize, 1 , color.getCColor());
        }
    }
}