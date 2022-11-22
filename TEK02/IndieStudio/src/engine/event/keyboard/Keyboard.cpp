/*
** EPITECH PROJECT, 2022
** system
** File description:
** Keyboard
*/

#include "Keyboard.hpp"

namespace istudio
{
    namespace event
    {
        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Keyboard constructor
        **/
        Keyboard::Keyboard()
        {
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Keyboard destructor
        **/
        Keyboard::~Keyboard()
        {
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function isKeyPressed (Class Keyboard): Function to know if a key is pressed on the keyboard
        ** @param key (int): Key to check
        **
        ** @return bool
        **/
        bool Keyboard::isKeyPressed(int key)
        {
            return IsKeyPressed(key);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function isKeyDown (Class Keyboard): Function to know if a key is held down
        ** @param key (int): Key to check
        **
        ** @return bool
        **/
        bool Keyboard::isKeyDown(int key)
        {
            return IsKeyDown(key);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function isKeyReleased (Class Keyboard): Function to check if a key is released
        ** @param key (int): Key to check
        **
        ** @return bool
        **/
        bool Keyboard::isKeyReleased(int key)
        {
            return IsKeyReleased(key);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function isKeyUp (Class Keyboard): Function to know if a key isn't pressed
        ** @param key (int): Key to check
        **
        ** @return bool
        **/
        bool Keyboard::isKeyUp(int key)
        {
            return IsKeyUp(key);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function setExitKey (Class Keyboard): Function to assign a key to close the game
        ** @param key (int): Key to quit the game
        **
        ** @return Nothing
        **/
        void Keyboard::setExitKey(int key)
        {
            SetExitKey(key);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function getKeyPressed (Class Keyboard): Function that returns which key is pressed
        **
        ** @return int
        **/
        int Keyboard::getKeyPressed(void)
        {
            return GetKeyPressed();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function getCharPressed (Class Keyboard): Function that returns which character is pressed
        **
        ** @return int
        **/
        int Keyboard::getCharPressed(void)
        {
            return GetCharPressed();
        }
    }
}