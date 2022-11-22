/*
** EPITECH PROJECT, 2022
** system
** File description:
** Camera
*/

#include "Camera.hpp"


namespace zappy
{
    namespace graphic
    {
        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Camera constructor
        ** @param position (math::Vector3): Camera's posotion
        ** @param target (math::Vector3): Camera's target
        ** @param rotation (math::Vector3): Camera's axis rotation
        ** @param fov (float): Camera's fov
        ** @param projection (int): Camera's projection
        **/
        Camera::Camera(math::Vector3 position, math::Vector3 target, math::Vector3 rotation, float fov , int projection)
        {
            _camera = {position.getCVector(), target.getCVector(), rotation.getCVector(), fov, projection};
        }
        
        void Camera::setPosition(math::Vector3 position, math::Vector3 target, math::Vector3 rotation)
        {
            _camera.position = position.getCVector();
            _camera.target = target.getCVector();
            _camera.up = rotation.getCVector();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function setMode (Class Camera): Function to set the camera's mode
        ** @param mode (int): Camera's mode
        **
        ** @return Nothing
        **/
        void Camera::setMode(int mode)
        {
            SetCameraMode(_camera, mode);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function update (Class Camera): Function to update the camera
        **
        ** @return Nothing
        **/
        void Camera::update()
        {
            UpdateCamera(&_camera);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function drawGrid (Class Camera): Function to draw the camera's grid
        ** @param size (int): Size of the camera's grid
        ** @param meshSize (float): Size of the mesh
        **
        ** @return Nothing
        **/
        void Camera::drawGrid(int size, float meshSize)
        {
            DrawGrid(size, meshSize);
        }

        ::Camera3D Camera::getCCamera()
        {
            return (_camera);
        }
    }
}