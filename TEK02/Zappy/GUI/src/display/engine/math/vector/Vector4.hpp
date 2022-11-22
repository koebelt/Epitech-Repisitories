/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Vector4
*/

#pragma once

extern "C" {
    #include <raylib.h>
}

namespace zappy
{
    namespace math
    {
        class Vector4
        {
        public:
            Vector4(float posx, float posy, float posz, float posw) : x(posx), y(posy), z(posz), w(posw) {};
            Vector4(::Vector4 v) : x(v.x), y(v.y), z(v.z), w(v.w) {};
            Vector4(const Vector4 &v) {x = v.x; y = v.y; z = v.z; w = v.w;};
            ~Vector4() = default;

            ::Vector4 getCVector() { return {x, y, z, w}; };

            float x = 0;
            float y = 0;
            float z = 0;
            float w = 0;
        protected:
        private:
    };
}
}