/*
** EPITECH PROJECT, 2022
** system
** File description:
** Cursor
*/

#pragma once

    extern "C" {
        #include <raylib.h>
    }

    namespace istudio
    {
        namespace event
        {
            class Cursor
            {
            public:
                Cursor();
                ~Cursor();

                void show(void);       // Shows cursor
                void hide(void);       // Hides cursor
                bool isHidden(void);   // Check if cursor is not visible
                void enable(void);     // Enables cursor (unlock cursor)
                void disable(void);    // Disables cursor (lock cursor)
                bool isOnScreen(void); // Check if cursor is on the screen

            protected:
            private:
            };
        }
    }
