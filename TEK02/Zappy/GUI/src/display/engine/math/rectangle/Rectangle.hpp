/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Rectangle
*/

#pragma once

extern "C" {
    #include <raylib.h>
}

#include "../vector/Vector2.hpp"

namespace zappy {
    namespace math
    {

        class Rectangle
        {
        public:
            Rectangle() : x(0), y(0), width(1), height(1){};
            Rectangle(float posx, float posy, float recwidth, float recheight) : x(posx), y(posy), width(recwidth), height(recheight) {};
            Rectangle(const Rectangle &rec) {x = rec.x; y = rec.y; width = rec.width; height = rec.height; };
            ~Rectangle() = default;

            ::Rectangle getCRectangle() {return {x, y, width, height}; };

            bool checkCollision(Vector2 point) { return CheckCollisionPointRec(point.getCVector(), {x, y, width, height}); };
            bool checkCollision(Rectangle rec){ return CheckCollisionRecs(rec.getCRectangle(), {x, y, width, height}); };


            float x;                // Rectangle top-left corner position x
            float y;                // Rectangle top-left corner position y
            float width;            // Rectangle width
            float height;           // Rectangle height

        protected:
        private:
    };
}
}