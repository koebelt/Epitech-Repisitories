/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Audio
*/

#pragma once

extern "C" {
        #include <raylib.h>
    }
#include <string>

namespace zappy {
    class Audio {
        public:
            Audio();
            ~Audio();
            void setMasterVolume(float volume);
            class Music {
                public:
                    Music() = default;
                    Music(std::string fileName);
                    ~Music();
                    void load(std::string fileName);
                    void unload();
                    void play();
                    bool isPlaying();
                    void stop();
                    void pause();
                    void update();
                    void resume();
                    void setVolume(float volume);
                    void setPitch(float pitch);
                    float getTimeLength();
                    float getTimePlayed();

                protected:
                private:
                    bool _isLoaded = false;
                    ::Music _music;
            };
            class Sound {
                public:
                    Sound() = default;
                    Sound(const std::string fileName);
                    ~Sound();
                    void load(const std::string filename);
                    void unload();
                    void play();
                    void stop();
                    void pause();
                    void resume();
                    bool isPlaying();
                    void setVolume(float volume);
                    void setPitch(float pitch);

                protected:
                private:
                    bool _isLoaded = false;
                    ::Sound _sound;
            };
        protected:
        private:
        };
        
        
}