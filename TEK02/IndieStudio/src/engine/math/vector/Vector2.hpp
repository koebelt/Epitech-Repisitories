/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Vector2
*/

#pragma once

extern "C" {
    #include <raylib.h>
}

namespace istudio
{
    namespace math
    {
        class Vector2
        {
            public:
                Vector2(float posx, float posy) : x(posx), y(posy) {};
                Vector2(::Vector2 v) : x(v.x), y(v.y){};
                Vector2(const Vector2 &v) {x = v.x; y = v.y;};
                ~Vector2() = default;

                ::Vector2 getCVector() { return {x, y}; };

                float x = 0;
                float y = 0;
            protected:
            private:
        };
    }
}

