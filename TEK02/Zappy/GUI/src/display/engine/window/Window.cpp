/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Window
*/

#include "Window.hpp"


namespace zappy
{
    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Window constructor
    **/
    Window::Window()
    {
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Window constructor
    ** @param width (int): Window's width
    ** @param height (int): Window's height
    ** @param title (std::string): Window's title
    **/
    Window::Window(int width, int height, const std::string title) : _width(width), _height(height), _title(title)
    {
        InitWindow(_width, _height, _title.c_str());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Window destructor
    **/
    Window::~Window()
    {
        close();
    }

    void Window::init(int width, int height, const std::string title)
    {
        _width = width;
        _height = height;
        _title = title;
        InitWindow(_width, _height, _title.c_str());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function shouldClose (Class Window): Function to know if the window should close (exit key pressed or exit crossed pressed)
    **
    ** @return bool
    **/
    bool Window::shouldClose()
    {
        return WindowShouldClose();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function close (Class Window): Function to close the window
    **
    ** @return Nothing
    **/
    void Window::close()
    {
        CloseWindow();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function isMaximized (Class Window): Function to know if the window is maximized
    **
    ** @return bool
    **/
    bool Window::isMaximized(void)
    {
        return IsWindowMaximized();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function isFocused (Class Window): Function to know if the window is focused
    **
    ** @return bool
    **/
    bool Window::isFocused(void)
    {
        return IsWindowFocused();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function isResized (Class Window): Function to know if the window is resized
    **
    ** @return bool
    **/
    bool Window::isResized(void)
    {
        return IsWindowResized();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function isState (Class Window): Function to know if a state is set in the window
    ** @param int (unsigned): Window's state to check
    **
    ** @return bool
    **/
    bool Window::isState(unsigned int flag)
    {
        return IsWindowState(flag);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setState (Class Window): Function to set the state of a window for a flage
    ** @param int (unsigned): Window's flag to set the state
    **
    ** @return Nothing
    **/
    void Window::setState(unsigned int flags)
    {
        SetWindowState(flags);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function clearState (Class Window): Function to clear the sets of the flags
    ** @param int (unsigned): Window's flags to reset
    **
    ** @return Nothing
    **/
    void Window::clearState(unsigned int flags)
    {
        ClearWindowState(flags);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function toggleFullscreen (Class Window): Fuction to toggle fullscreen for the window
    **
    ** @return Nothing
    **/
    void Window::toggleFullscreen(void)
    {
        ToggleFullscreen();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function maximize (Class Window): Function to maximise the window
    **
    ** @return Nothing
    **/
    void Window::maximize(void)
    {
        MaximizeWindow();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function minimize (Class Window): Function to minimize the window
    **
    ** @return Nothing
    **/
    void Window::minimize(void)
    {
        MinimizeWindow();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function restore (Class Window): Function to restore the window to it's original state
    **
    ** @return Nothing
    **/
    void Window::restore(void)
    {
        RestoreWindow();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setIcon (Class Window): Function to set the icon of the window
    ** @param image (graphic::Image): Window's icon to set
    **
    ** @return Nothing
    **/
    void Window::setIcon(graphic::Image image)
    {

        SetWindowIcon(image.getCImg());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setTitle (Class Window): Function to set the title of the window
    ** @param title (std::string): Window's title to set
    **
    ** @return Nothing
    **/
    void Window::setTitle(std::string title)
    {
        SetWindowTitle(title.c_str());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setPosition (Class Window): Function to set the position of a window
    ** @param x (int): X coordinate
    ** @param y (int): Y coordinate
    **
    ** @return Nothing
    **/
    void Window::setPosition(int x, int y)
    {
        SetWindowPosition(x, y);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setMinSize (Class Window): Function to set the minimum size of a window
    ** @param width (int): Minimum window's width
    ** @param height (int): Minimum window's height
    **
    ** @return Nothing
    **/
    void Window::setMinSize(int width, int height)
    {
        SetWindowMinSize(width, height);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setSize (Class Window): Function to set the size of a window
    ** @param width (int): Window's width
    ** @param height (int): Window's height
    **
    ** @return Nothing
    **/
    void Window::setSize(int width, int height)
    {
        SetWindowSize(width, height);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function getHandle (Class *Window): Function to get the handle for the window
    **
    ** @return Nothing
    **/
    void *Window::getHandle(void)
    {
        return GetWindowHandle();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class getPosition constructor
    **/
    math::Vector2 Window::getPosition(void)
    {
        ::Vector2 pos = GetWindowPosition();
        return math::Vector2(pos.x, pos.y);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function clearBackground (Class Window): Function to clear the background of the window
    ** @param color (graphic::Color): Window's backgroud color
    **
    ** @return Nothing
    **/
    void Window::clearBackground(graphic::Color color)
    {
        ClearBackground(color.getCColor());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function beginDrawing (Class Window): Function to start the drawing process of the window
    **
    ** @return Nothing
    **/
    void Window::beginDrawing(void)
    {
        BeginDrawing();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function beginDrawing (Class Window): Function to end the drawing process of the window
    **
    ** @return Nothing
    **/
    void Window::endDrawing(void)
    {
        EndDrawing();
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function drawCamera (Class Window): Function to draw the camera in the window
    ** @param camera (graphic::Camera): Camera to draw
    **
    ** @return Nothing
    **/
    void Window::drawCamera(graphic::Camera camera)
    {
        BeginMode3D(camera.getCCamera());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function endDrawCamera (Class Window): Function to stop the drawings of the cameras in the window
    **
    ** @return Nothing
    **/
    void Window::endDrawCamera()
    {
        EndMode3D();
    }
}