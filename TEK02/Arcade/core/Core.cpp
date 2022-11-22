/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(std::string path)
{
    LoadLibraries(path);
}

Core::~Core()
{}

void Core::LoadLibraries(std::string default_lib)
{
    std::string path = "./lib/";
    std::shared_ptr<arcade::ILibrary> default_library = nullptr;

    for (const auto &entry : std::filesystem::directory_iterator(path))
        _libs.emplace_back(dlloader::DLLoader(entry.path().generic_string()));

    for (int i = 0; i < _libs.size(); i++) {
        if (_libs[i].getType() == "allocatorGame")
            _game_libs.push_back(_libs[i].DLGetInstance<arcade::IGame>());
        if (_libs[i].getType() == "allocatorGraphic") {
            default_library = _libs[i].DLGetInstance<arcade::ILibrary>();
            _graphical_libs.push_back(default_library);
            if (_libs[i].getPath() == default_lib) {
                _current_lib = default_library;
                _current_lib->init();
            }
        }
    }
    if (!_current_lib)
        throw ErrorManager("The default lib wasn't found");
    if (_game_libs.size() == 0)
        throw ErrorManager("No games was found");
    if (_current_game && _current_lib)
        _current_lib->loadProperties(_current_game->getProperties());
}

void Core::Loop()
{
    std::shared_ptr<arcade::Event> event;

    while (_current_lib->isOpen()) {
        if (_current_game) {
            while ((event = _current_lib->getCurrentEvent())) {
                if (MenuEvents(event))
                    break;
                _current_game->listen(event);
            }
            if (!_current_game)
                continue;
            if (_current_game->update(_current_lib->getTimeElapsed(), std::bind(&arcade::ILibrary::resetTimer, _current_lib))) {
                _current_game = nullptr;
                continue;
            }
            _current_lib->render(_current_game->getMatrix());
        } else {
            while (MenuEvents(_current_lib->getCurrentEvent()));
            _current_lib->render();
        }
    }
    _current_lib->close();
}

void Core::NextGame()
{
    std::shared_ptr<arcade::IGame> old_game;
    int has_appeared = 0;
    std::shared_ptr<arcade::IGame> tmp = nullptr;

    if (!_current_game) {
        _current_game = _game_libs[0];
        _current_lib->loadProperties(_current_game->getProperties());
    } else {
        old_game = _current_game;
        for (int i = 0; i < _game_libs.size(); i++) {
            tmp = _game_libs[i];
            if (has_appeared == 1) {
                _current_game = tmp;
                _current_game->reset();
                _current_lib->loadProperties(_current_game->getProperties());
                return;
            }
            if (old_game == tmp)
                has_appeared = 1;
        }
    } if (_current_game == old_game) {
            _current_game = _game_libs[0];
            _current_game->reset();
            _current_lib->loadProperties(_current_game->getProperties());
    }
}

void Core::PreviousGame()
{
    std::shared_ptr<arcade::IGame> tmp = nullptr;
    std::shared_ptr<arcade::IGame> new_game = nullptr;
    std::shared_ptr<arcade::IGame> last_game = nullptr;

    if (!_current_game) {
        _current_game = _game_libs[0];
        _current_lib->loadProperties(_current_game->getProperties());
    } else {
        for (int i = 0; i < _game_libs.size(); i++) {
            tmp = _game_libs[i];
            if (_current_game == tmp) {
                if (!new_game) {
                    for (int i = 0; i < _game_libs.size(); i++)
                        last_game = _game_libs[i];
                    _current_game = last_game;
                    _current_game->reset();
                    _current_lib->loadProperties(_current_game->getProperties());
                    return;
                } else {
                    _current_game = new_game;
                    _current_game->reset();
                    _current_lib->loadProperties(_current_game->getProperties());
                    return;
                }
            }
        new_game = tmp;
        }
    }
}


void Core::NextLibrary()
{
    std::shared_ptr<arcade::ILibrary> old_lib;
    int has_appeared = 0;
    std::shared_ptr<arcade::ILibrary> tmp = nullptr;


    old_lib = _current_lib;
    for (int i = 0; i < _graphical_libs.size(); i++) {
        tmp = _graphical_libs[i];
        if (has_appeared == 1) {
            _current_lib->close();
            _current_lib = tmp;
            _current_lib->init();
            if (_current_game && _current_lib)
                _current_lib->loadProperties(_current_game->getProperties());
            return;
        }
        if (tmp == old_lib)
            has_appeared = 1;
    }
    if (_current_lib == old_lib) {
        _current_lib->close();
        _current_lib = _graphical_libs[0];
        _current_lib->init();
        if (_current_game && _current_lib)
            _current_lib->loadProperties(_current_game->getProperties());
    }
}

void Core::PreviousLibrary()
{
    std::shared_ptr<arcade::ILibrary> tmp = nullptr;
    std::shared_ptr<arcade::ILibrary> new_lib = nullptr;
    std::shared_ptr<arcade::ILibrary> last_lib = nullptr;


    for (int i = 0; i < _graphical_libs.size(); i++) {
        tmp = _graphical_libs[i];
        if (_current_lib == tmp) {
            if (!new_lib) {
                for (int i = 0; i < _graphical_libs.size(); i++)
                    last_lib = _graphical_libs[i];
                _current_lib->close();
                _current_lib = last_lib;
                _current_lib->init();
                if (_current_game && _current_lib)
                    _current_lib->loadProperties(_current_game->getProperties());
                return;
            } else {
                _current_lib->close();
                _current_lib = new_lib;
                _current_lib->init();
                if (_current_game && _current_lib)
                    _current_lib->loadProperties(_current_game->getProperties());
                return;
            }
        }
        new_lib = tmp;
    }
}

int Core::MenuEvents(std::shared_ptr<arcade::Event> event)
{
    if (!event)
        return 0;
    if (event->getValue() == (std::vector<int>){arcade::Event::AKEY_Y})
        PreviousLibrary();
    if (event->getValue() == (std::vector<int>){arcade::Event::AKEY_U})
        NextLibrary();
    if (event->getValue() == (std::vector<int>){arcade::Event::AKEY_I})
        PreviousGame();
    if (event->getValue() == (std::vector<int>){arcade::Event::AKEY_O})
        NextGame();
    if (event->getValue() == (std::vector<int>){arcade::Event::AKEY_R})
        if (_current_game)
            _current_game->reset();
    if (event->getValue() == (std::vector<int>){arcade::Event::AKEY_M}) {
        _current_game = nullptr;
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    try {
        Core core = Core(av[1]);
        core.Loop();
    } catch (ErrorManager &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}