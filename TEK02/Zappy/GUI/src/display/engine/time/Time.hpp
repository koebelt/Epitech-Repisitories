/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Time
*/

#pragma once

    extern "C" {
        #include <raylib.h>
    }


namespace zappy {
    class Time {
        public:
            static void setTargetFPS(int fps);                                             // Set target FPS (maximum)
            static int getFPS(void);                                                       // Get current FPS
            static float getFrameTime(void);                                               // Get time in seconds for last frame drawn (delta time)
            static double getTime(void);
        protected:
        private:
    };
}