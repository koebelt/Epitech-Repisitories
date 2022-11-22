/*
** EPITECH PROJECT, 2022
** system
** File description:
** Cursor
*/

#include "Cursor.hpp"

namespace zappy
{
    namespace event
    {
        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Cursor constructor
        **/
        Cursor::Cursor()
        {
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Cursor destructor
        **/
        Cursor::~Cursor()
        {
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function show (Class Cursor): Function to show the cursor
        **
        ** @return Nothing
        **/
        void Cursor::show(void)
        {
            ShowCursor();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function hide (Class Cursor): Function to hide the cursor
        **
        ** @return Nothing
        **/
        void Cursor::hide(void)
        {
            HideCursor();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function isHidden (Class Cursor): Function to know if the cursor is hidden
        **
        ** @return bool
        **/
        bool Cursor::isHidden()
        {

            return IsCursorHidden();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function enable (Class Cursor): Function to enable the cursor inside of the game
        **
        ** @return Nothing
        **/
        void Cursor::enable(void)
        {
            EnableCursor();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function disable (Class Cursor): Function to disable the cursor inside of the game
        **
        ** @return Nothing
        **/
        void Cursor::disable(void)
        {
            DisableCursor();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function isOnScreen (Class Cursor): Function to know if the cursor is on screen
        **
        ** @return bool
        **/
        bool Cursor::isOnScreen(void)
        {
            return IsCursorOnScreen();
        }
    }
}