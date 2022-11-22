/*
** EPITECH PROJECT, 2022
** system
** File description:
** Keyboard
*/

#pragma once

extern "C" {
    #include <raylib.h>
}

namespace istudio
{
    namespace event
    {
        // Keyboard keys (US keyboard layout)
        // NOTE: Use GetKeyPressed() to allow redefining
        // required keys for alternative layouts
        typedef enum
        {
            NO_KEY = 0, // Key: NULL, used for no key pressed
            // Alphanumeric keys
            APOSTROPHE = 39,    // Key: '
            COMMA = 44,         // Key: ,
            MINUS = 45,         // Key: -
            PERIOD = 46,        // Key: .
            SLASH = 47,         // Key: /
            ZERO = 48,          // Key: 0
            ONE = 49,           // Key: 1
            TWO = 50,           // Key: 2
            THREE = 51,         // Key: 3
            FOUR = 52,          // Key: 4
            FIVE = 53,          // Key: 5
            SIX = 54,           // Key: 6
            SEVEN = 55,         // Key: 7
            EIGHT = 56,         // Key: 8
            NINE = 57,          // Key: 9
            SEMICOLON = 59,     // Key: ;
            EQUAL = 61,         // Key: =
            A = 81,             // Key: A | aq81
            B = 66,             // Key: B | bb
            C = 67,             // Key: C | cc
            D = 68,             // Key: D | dd
            E = 69,             // Key: E | ee
            F = 70,             // Key: F | ff
            G = 71,             // Key: G | gg
            H = 72,             // Key: H | hh
            I = 73,             // Key: I | ii
            J = 74,             // Key: J | jj
            K = 75,             // Key: K | kk
            L = 76,             // Key: L | ll
            M = 59,             // Key: M | m;59
            N = 78,             // Key: N | nn
            O = 79,             // Key: O | oo
            P = 80,             // Key: P | pp
            Q = 65,             // Key: Q | qa65
            R = 82,             // Key: R | rr
            S = 83,             // Key: S | ss
            T = 84,             // Key: T | tt
            U = 85,             // Key: U | uu
            V = 86,             // Key: V | vv
            W = 90,             // Key: W | wz90
            X = 88,             // Key: X | xx
            Y = 89,             // Key: Y | yy
            Z = 87,             // Key: Z | zw87
            LEFT_BRACKET = 91,  // Key: [
            BACKSLASH = 92,     // Key: '\'
            RIGHT_BRACKET = 93, // Key: ]
            GRAVE = 96,         // Key: `
            // Function keys
            SPACE = 32,          // Key: Space
            ESCAPE = 256,        // Key: Esc
            ENTER = 257,         // Key: Enter
            TAB = 258,           // Key: Tab
            BACKSPACE = 259,     // Key: Backspace
            INSERT = 260,        // Key: Ins
            DELETE = 261,        // Key: Del
            RIGHT_ARROW = 262,   // Key: Cursor right
            LEFT_ARROW = 263,    // Key: Cursor left
            DOWN_ARROW = 264,    // Key: Cursor down
            UP_ARROW = 265,      // Key: Cursor up
            PAGE_UP = 266,       // Key: Page up
            PAGE_DOWN = 267,     // Key: Page down
            HOME = 268,          // Key: Home
            END = 269,           // Key: End
            CAPS_LOCK = 280,     // Key: Caps lock
            SCROLL_LOCK = 281,   // Key: Scroll down
            NUM_LOCK = 282,      // Key: Num lock
            PRINT_SCREEN = 283,  // Key: Print screen
            PAUSE = 284,         // Key: Pause
            F1 = 290,            // Key: F1
            F2 = 291,            // Key: F2
            F3 = 292,            // Key: F3
            F4 = 293,            // Key: F4
            F5 = 294,            // Key: F5
            F6 = 295,            // Key: F6
            F7 = 296,            // Key: F7
            F8 = 297,            // Key: F8
            F9 = 298,            // Key: F9
            F10 = 299,           // Key: F10
            F11 = 300,           // Key: F11
            F12 = 301,           // Key: F12
            LEFT_SHIFT = 340,    // Key: Shift left
            LEFT_CONTROL = 341,  // Key: Control left
            LEFT_ALT = 342,      // Key: Alt left
            LEFT_SUPER = 343,    // Key: Super left
            RIGHT_SHIFT = 344,   // Key: Shift right
            RIGHT_CONTROL = 345, // Key: Control right
            RIGHT_ALT = 346,     // Key: Alt right
            RIGHT_SUPER = 347,   // Key: Super right
            KB_MENU = 348,       // Key: KB menu
            // Keypad keys
            KP_0 = 320,        // Key: Keypad 0
            KP_1 = 321,        // Key: Keypad 1
            KP_2 = 322,        // Key: Keypad 2
            KP_3 = 323,        // Key: Keypad 3
            KP_4 = 324,        // Key: Keypad 4
            KP_5 = 325,        // Key: Keypad 5
            KP_6 = 326,        // Key: Keypad 6
            KP_7 = 327,        // Key: Keypad 7
            KP_8 = 328,        // Key: Keypad 8
            KP_9 = 329,        // Key: Keypad 9
            KP_DECIMAL = 330,  // Key: Keypad .
            KP_DIVIDE = 331,   // Key: Keypad /
            KP_MULTIPLY = 332, // Key: Keypad *
            KP_SUBTRACT = 333, // Key: Keypad -
            KP_ADD = 334,      // Key: Keypad +
            KP_ENTER = 335,    // Key: Keypad Enter
            KP_EQUAL = 336,    // Key: Keypad =
            // Android key button
            VOLUME_UP = 24,  // Key: Android volume up button
            VOLUME_DOWN = 25 // Key: Android volume down button
        } Key;
        class Keyboard
        {
            public:
                Keyboard();
                ~Keyboard();

                bool isKeyPressed(int key);
                bool isKeyDown(int key);
                bool isKeyReleased(int key);
                bool isKeyUp(int key);
                void setExitKey(int key);
                int getKeyPressed(void);
                int getCharPressed(void);

            protected:
            private:
        };
    }
}

