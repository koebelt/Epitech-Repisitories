/*
** EPITECH PROJECT, 2022
** system
** File description:
** Mouse
*/

#pragma once

#include "../Event.hpp"
#include "../../math/Math.hpp"
#include "Cursor.hpp"

extern "C" {
    #include <raylib.h>
}

namespace zappy
{
    namespace event
    {
        typedef enum
        {
            LEFT = 0,    // Mouse button left
            RIGHT = 1,   // Mouse button right
            MIDDLE = 2,  // Mouse button middle (pressed wheel)
            SIDE = 3,    // Mouse button side (advanced mouse device)
            EXTRA = 4,   // Mouse button extra (advanced mouse device)
            FORWARD = 5, // Mouse button fordward (advanced mouse device)
            BACK = 6,    // Mouse button back (advanced mouse device)
        } MouseButton;
        class Mouse
        {
            public:
                Mouse();
                ~Mouse();

                bool isButtonPressed(int button);
                bool isButtonDown(int button);
                bool isButtonReleased(int button);
                bool isButtonUp(int button);
                int getX(void);
                int getY(void);
                zappy::math::Vector2 getPosition(void);
                zappy::math::Vector2 getDelta(void);
                void setPosition(int x, int y);
                void setOffset(int offsetX, int offsetY);
                void setScale(float scaleX, float scaleY);
                float getWheelMove(void);

                zappy::event::Cursor cursor;

            protected:
            private:
        };
    }
}
