/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "../library/ILibrary.hpp"
#include "../game/IGame.hpp"
#include "../library/dlloader/DLLoader.hpp"
#include "../common/Event.hpp"
#include "../common/Property.hpp"
#include "../common/Vector.hpp"
#include "../common/Matrix.hpp"
#include "../common/ErrorManager.hpp"
#include "string"
#include <list>
#include <filesystem>
#include <memory>

class Core {
    public:
        Core(std::string path);
        ~Core();
        void LoadLibraries(std::string);
        void Loop();
        int MenuEvents(std::shared_ptr<arcade::Event> event);
        void NextGame();
        void PreviousGame();
        void NextLibrary();
        void PreviousLibrary();

    protected:
    private:
        std::vector<dlloader::DLLoader> _libs;
        std::vector<std::shared_ptr<arcade::ILibrary>> _graphical_libs;
        std::vector<std::shared_ptr<arcade::IGame>> _game_libs;
        
        std::shared_ptr<arcade::ILibrary> _current_lib;
        std::shared_ptr<arcade::IGame> _current_game;
};

#endif /* !CORE_HPP_ */
