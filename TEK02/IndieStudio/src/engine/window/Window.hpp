/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Window
*/

#pragma once

    #include <string>
    extern "C" {
        #include <raylib.h>
    }
    #include "../math/Math.hpp"
    #include "../graphic/Graphic.hpp"
    #include "../event/Event.hpp"
    #include "../audio/Audio.hpp"

namespace istudio {
    class Window {
        public:
            Window();
            Window(int width, int height, const std::string title);
            ~Window();
            void init(int width, int height, const std::string title);
            bool shouldClose();
            void close();
            bool isHidden(void);                    // Check if window is currently hidden (only PLATFORM_DESKTOP)
            bool isMinimized(void);                 // Check if window is currently minimized (only PLATFORM_DESKTOP)
            bool isMaximized(void);                 // Check if window is currently maximized (only PLATFORM_DESKTOP)
            bool isFocused(void);                   // Check if window is currently focused (only PLATFORM_DESKTOP)
            bool isResized(void);                   // Check if window has been resized last frame
            bool isState(unsigned int flag);        // Check if one specific window flag is enabled
            void setState(unsigned int flags);      // Set window configuration state using flags
            void clearState(unsigned int flags);    // Clear window configuration state flags
            void toggleFullscreen(void);                  // Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
            void maximize(void);                    // Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
            void minimize(void);                    // Set window state: minimized, if resizable (only PLATFORM_DESKTOP)
            void restore(void);                     // Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
            void setIcon(graphic::Image image);              // Set icon for window (only PLATFORM_DESKTOP)
            void setTitle(std::string title);       // Set title for window (only PLATFORM_DESKTOP)
            void setPosition(int x, int y);         // Set window position on screen (only PLATFORM_DESKTOP)
            void setMinSize(int width, int height); // Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
            void setSize(int width, int height);    // Set window dimensions
            void *getHandle(void);                  // Get native window handle
            math::Vector2 getPosition(void);              // Get window position XY on monitor
            void clearBackground(graphic::Color color);            // Set background color (framebuffer clear color)
            void beginDrawing(void);                      // Setup canvas (framebuffer) to start drawing
            void endDrawing(void);
            void drawCamera(graphic::Camera);
            void endDrawCamera();

            event::Mouse mouse;
            event::Keyboard keyboard;
            istudio::Audio audio;
        protected:
        private:
            int _height;
            int _width;
            int _x;
            int _y;
            std::string _title;
    };
}

