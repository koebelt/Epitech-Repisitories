/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Text
*/

#pragma once

extern "C" {
        #include <raylib.h>
    }
#include <string>
#include "../../../color/Color.hpp"
#include "font/Font.hpp"

namespace istudio {
    namespace graphic {
        class Text {
            public:
                static void drawFPS(int posX, int posY);
                static void drawText(std::string text, int posX, int posY, int fontSize, Color color);
                static void drawText(Font &font, std::string text, int posX, int posY, int fontSize, Color color);
            protected:
            private:
        };
    }
}