/*
** EPITECH PROJECT, 2022
** system
** File description:
** Color
*/

#pragma once

    extern "C" {
        #include <raylib.h>
    }

namespace zappy {
    namespace graphic {
        class Color {
            public:
                Color() : r(255), g(255), b(255), a(255) {};
                Color(unsigned char red, unsigned char green, unsigned char blue) : r(red), g(green), b(blue), a(255) {};
                Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : r(red), g(green), b(blue), a(alpha){};
                Color(const Color &color) {r = color.r; g = color.g; b = color.b; a = color.a;};
                ~Color() = default;

                ::Color getCColor() { return {r, g, b, a}; };

                unsigned char r; // Color red value
                unsigned char g; // Color green value
                unsigned char b; // Color blue value
                unsigned char a; // Color alpha value
                protected:
                private:
        };
    }
}

