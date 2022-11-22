/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "../../utils/CustomError.hpp"

istudio::SceneManager &istudio::SceneManager::operator<<(std::shared_ptr<IScene> scene)
{
    if (!_scenes.size())
        _current = scene->getId();
    _scenes[scene->getId()] = std::move(scene);
	return *this;
}

istudio::SceneManager &istudio::SceneManager::operator<<(int scene)
{
    if (_last != -1)
        _scenes[_current]->unload();
    _last = _current;
    _current = scene;
	return *this;
}

void istudio::SceneManager::load(int scene)
{
    *this << scene;
    _scenes[_current]->load();
}

void istudio::SceneManager::loadAndKeepLast(int scene)
{
    _last = _current;
    _current = scene;
    _scenes[_current]->load();
}

void istudio::SceneManager::llast()
{
    int temp = _current;

    _current = _last;
    _last = temp;
    _scenes[_current]->load();
    if (_last != -1)
        _scenes[_last]->unload();
}

std::shared_ptr<istudio::IScene> &istudio::SceneManager::operator[](int id)
{
    if (_scenes.find(id) == _scenes.end())
        throw CustomError("Scene Manager", "Scene with this id doesn't exist");
    return _scenes[id];
}

std::shared_ptr<istudio::IScene> &istudio::SceneManager::operator->()
{
    if (_current == -1)
        throw CustomError("Scene Manager", "Doesn't have current scene loaded");
    return _scenes[_current];
}

std::shared_ptr<istudio::IScene> &istudio::SceneManager::operator~()
{
    if (_current == -1)
        throw CustomError("Scene Manager", "Doesn't have current scene loaded");
    return _scenes[_current];
}

std::shared_ptr<istudio::IScene> &istudio::SceneManager::operator*()
{
    if (_last == -1)
        throw CustomError("Scene Manager", "Doesn't have scene before");
    return _scenes[_last];
}