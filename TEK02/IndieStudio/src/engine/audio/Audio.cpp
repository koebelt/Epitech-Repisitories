/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Audio
*/

#include "Audio.hpp"

namespace istudio {

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Audio constructor
    **/
    Audio::Audio()
    {
        InitAudioDevice();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Audio destructor
    **/
    Audio::~Audio()
    {
        CloseAudioDevice();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setMasterVolume (Class Audio): Function to set the master volume for the game
    ** @param volume (float): Volume for the game
    **
    ** @return Nothing
    **/
    void Audio::setMasterVolume(float volume)
    {
        SetMasterVolume(volume);
    }

}