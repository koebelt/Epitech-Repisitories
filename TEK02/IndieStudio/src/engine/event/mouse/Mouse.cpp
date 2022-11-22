/*
** EPITECH PROJECT, 2022
** system
** File description:
** Mouse
*/

#include "Mouse.hpp"

namespace istudio
{
    namespace event
    {

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Mouse constructor
        **/
        Mouse::Mouse()
        {
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Mouse destructor
        **/
        Mouse::~Mouse()
        {
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function isButtonPressed (Class Mouse): Function to know if a button is pressed
        ** @param button (int): Button to check
        **
        ** @return bool
        **/
        bool Mouse::isButtonPressed(int button)
        {
            return IsMouseButtonPressed(button);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function isButtonDown (Class Mouse): Function to know if a button is down
        ** @param button (int): Button to check
        **
        ** @return bool
        **/
        bool Mouse::isButtonDown(int button)
        {
            return IsMouseButtonDown(button);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function isButtonReleased (Class Mouse): Function to know if a button is released
        ** @param button (int): Button to check
        **
        ** @return bool
        **/
        bool Mouse::isButtonReleased(int button)
        {
            return IsMouseButtonReleased(button);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function isButtonUp (Class Mouse): Function to know if a button isn't pressed
        ** @param button (int): Button to check
        **
        ** @return bool
        **/
        bool Mouse::isButtonUp(int button)
        {
            return IsMouseButtonUp(button);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function getX (Class Mouse): Function to get x coordinate
        **
        ** @return int
        **/
        int Mouse::getX(void)
        {
            return GetMouseX();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function getY (Class Mouse): Function to get y coordinate
        **
        ** @return int
        **/
        int Mouse::getY(void)
        {
            return GetMouseY();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class getPosition constructor
        **/
        istudio::math::Vector2 Mouse::getPosition(void)
        {
            return GetMousePosition();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class getDelta constructor
        **/
        istudio::math::Vector2 Mouse::getDelta(void)
        {
            return GetMouseDelta();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function setPosition (Class Mouse): Function to set the position of the mouse
        ** @param x (int): X coordinate
        ** @param y (int): Y coordinate
        **
        ** @return Nothing
        **/
        void Mouse::setPosition(int x, int y)
        {
            SetMousePosition(x, y);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function setOffset (Class Mouse): Function to set the offset fot the mouse
        ** @param offsetX (int): X offset
        ** @param offsetY (int): Y offset
        **
        ** @return Nothing
        **/
        void Mouse::setOffset(int offsetX, int offsetY)
        {
            SetMouseOffset(offsetX, offsetY);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function setScale (Class Mouse): Function to set the scale for the mouse
        ** @param scaleX (float): X scale
        ** @param scaleY (float): Y scale
        **
        ** @return Nothing
        **/
        void Mouse::setScale(float scaleX, float scaleY)
        {
            SetMouseScale(scaleX, scaleY);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function getWheelMove (Class Mouse): Function to know the moves of the wheel
        **
        ** @return float
        **/
        float Mouse::getWheelMove(void)
        {
            return GetMouseWheelMove();
        }
    }
}