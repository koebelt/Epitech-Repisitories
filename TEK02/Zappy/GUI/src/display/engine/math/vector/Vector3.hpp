/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Vector3
*/

#pragma once

extern "C" {
    #include <raylib.h>
}

namespace zappy
{
    namespace math
    {
        class Vector3
        {
        public:
            Vector3(float posx, float posy, float posz) : x(posx), y(posy), z(posz) {};
            Vector3(::Vector3 v) : x(v.x), y(v.y), z(v.z){};
            Vector3(const Vector3 &v) {x = v.x; y = v.y; z = v.z;};
            ~Vector3() = default;

            bool operator==(const Vector3 &v) const {return x == v.x && y == v.y && z == v.z;};

            ::Vector3 getCVector() { return {x, y, z}; };

            float x = 0;
            float y = 0;
            float z = 0;
        protected:
        private:
    };
}
}