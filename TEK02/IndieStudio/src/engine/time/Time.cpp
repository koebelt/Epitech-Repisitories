/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Time
*/

#include "Time.hpp"

namespace istudio {

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setTargetFPS (Class Time): Function set target's fps
    ** @param fps (int): Fps for the target
    **
    ** @return Nothing
    **/
    void Time::setTargetFPS(int fps)
    {
        SetTargetFPS(fps);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function getFPS (Class Time): Function to get the fps
    **
    ** @return int
    **/
    int Time::getFPS(void)
    {
        return GetFPS();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function getFrameTime (Class Time): Function to get the frame time
    **
    ** @return float
    **/
    float Time::getFrameTime(void)
    {
        return GetFrameTime();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function getTime (Class Time): Function to get the time
    **
    ** @return double
    **/
    double Time::getTime(void)
    {
        return GetTime();
    }
}