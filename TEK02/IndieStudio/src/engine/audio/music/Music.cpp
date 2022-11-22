/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Music
*/

#include "../Audio.hpp"


namespace istudio {

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Music constructor
    ** @param fileName (std::string): Name of the music file
    **/
    Audio::Music::Music(std::string fileName)
    {
        _isLoaded = true;
        _music = LoadMusicStream(fileName.c_str());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Music destructor
    **/
    Audio::Music::~Music()
    {
        unload();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function playMusicStream (Class Music): Function to play a music
    **
    ** @return Nothing
    **/
    void Audio::Music::play()
    {
        if (!_isLoaded) return;
        PlayMusicStream(_music);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function isMusicStreamPlaying (Class Music): Function to know if a music is playing
    **
    ** @return bool
    **/
    bool Audio::Music::isPlaying()
    {
        if (!_isLoaded) return false;
        return IsMusicStreamPlaying(_music);
    }

    /**
    ** @author : koebelt <thomas.koebel@epitech.eu>
    **
    ** @brief Function load (Class Music): load a new music
    ** @param fileName (std::string): filename
    **
    ** @return Nothing
    **/
    void Audio::Music::load(std::string fileName)
    {
        _isLoaded = true;
        _music = LoadMusicStream(fileName.c_str());
    }

    void Audio::Music::unload()
    {
        if (!_isLoaded) return;
        _isLoaded = false;
        UnloadMusicStream(_music);
    }

    void Audio::Music::update()
    {
        if (!_isLoaded) return;
        UpdateMusicStream(_music);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function stopMusicStream (Class Music): Function to stop a music
    **
    ** @return Nothing
    **/
    void Audio::Music::stop()
    {
        if (!_isLoaded) return;
        StopMusicStream(_music);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function pauseMusicStream (Class Music): Function to pause a music
    **
    ** @return Nothing
    **/
    void Audio::Music::pause()
    {
        if (!_isLoaded) return;
        PauseMusicStream(_music);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function resumeMusicStream (Class Music): Function to resume a music
    **
    ** @return Nothing
    **/
    void Audio::Music::resume()
    {
        if (!_isLoaded) return;
        ResumeMusicStream(_music);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setMusicVolume (Class Music): Function to set the volume of a music
    ** @param volume (float): Volume of the music
    **
    ** @return Nothing
    **/
    void Audio::Music::setVolume(float volume)
    {
        if (!_isLoaded) return;
        SetMusicVolume(_music, volume);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setMusicPitch (Class Music): Function to set the pitch of the music
    ** @param pitch (float): Pitch of the music
    **
    ** @return Nothing
    **/
    void Audio::Music::setPitch(float pitch)
    {
        if (!_isLoaded) return;
        SetMusicPitch(_music, pitch);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function getMusicTimeLength (Class Music): Function to know the length of a music
    **
    ** @return float
    **/
    float Audio::Music::getTimeLength()
    {
        if (!_isLoaded) return -1;
        return GetMusicTimeLength(_music);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function getMusicTimePlayed (Class Music): Function to know the time played for a music
    **
    ** @return float
    **/
    float Audio::Music::getTimePlayed()
    {
        if (!_isLoaded) return -1;
        return GetMusicTimePlayed(_music);
    }
}