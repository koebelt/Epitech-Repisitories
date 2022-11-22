/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Sound
*/

#include "../Audio.hpp"


namespace zappy {

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Sound constructor
    ** @param fileName (std::string): Name of the file containing the sound
    **/
    Audio::Sound::Sound(const std::string fileName)
    {
        _isLoaded = true;
        _sound = LoadSound(fileName.c_str());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Sound destructor
    **/
    Audio::Sound::~Sound()
    {
        unload();
    }

    void Audio::Sound::load(const std::string fileName)
    {
        _isLoaded = true;
        _sound = LoadSound(fileName.c_str());
    }

    void Audio::Sound::unload()
    {
        if (!_isLoaded) return;
        _isLoaded = false;
        UnloadSound(_sound);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function playSound (Class Sound): Function to play a sound
    **
    ** @return Nothing
    **/
    void Audio::Sound::play()
    {
        if (!_isLoaded) return;
        PlaySound(_sound);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function stopSound (Class Sound): Function to stop a sound
    **
    ** @return Nothing
    **/
    void Audio::Sound::stop()
    {
        if (!_isLoaded) return;
        StopSound(_sound);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function pauseSound (Class Sound): Function to pause a sound
    **
    ** @return Nothing
    **/
    void Audio::Sound::pause()
    {
        if (!_isLoaded) return;
        PauseSound(_sound);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function resumeSound (Class Sound): Function to resume a sound
    **
    ** @return Nothing
    **/
    void Audio::Sound::resume()
    {
        if (!_isLoaded) return;
        ResumeSound(_sound);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function isSoundPlaying (Class Sound): Function to know if a sound is playing
    **
    ** @return bool
    **/
    bool Audio::Sound::isPlaying()
    {
        if (!_isLoaded) return false;
        return IsSoundPlaying(_sound);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setSoundVolume (Class Sound): Function to set the volume of a sound
    ** @param volume (float): Volume of the sound
    **
    ** @return Nothing
    **/
    void Audio::Sound::setVolume(float volume)
    {
        if (!_isLoaded) return;
        SetSoundVolume(_sound, volume);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setSoundPitch (Class Sound): Function to set the pitch of a sound
    ** @param pitch (float): Pitch of the sound
    **
    ** @return Nothing
    **/
    void Audio::Sound::setPitch(float pitch)
    {
        if (!_isLoaded) return;
        SetSoundPitch(_sound, pitch);
    }
}