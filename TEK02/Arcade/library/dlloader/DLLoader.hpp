/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <iostream>
#include <dlfcn.h>
#include <memory>
#include <string>
#include "../../common/ErrorManager.hpp"

namespace dlloader
{
    class DLLoader
    {
    private:
        void *_handle;
        std::string _pathToLib;
        std::string _allocClassSymbol;


    public:
        DLLoader(const DLLoader &) = delete;
        DLLoader(DLLoader && other) : _handle(other._handle), _pathToLib(other._pathToLib), _allocClassSymbol(other._allocClassSymbol) { other._handle = nullptr; };

        DLLoader(std::string const &pathToLib) : _handle(nullptr), _pathToLib(pathToLib)
        {
            if (!(_handle = dlopen(_pathToLib.c_str(), RTLD_NOW | RTLD_LAZY)))
                throw ErrorManager("Unable to open the Dynamic Lib");

            auto allocFunc = (dlsym(_handle, "allocatorGraphic"));

            if (allocFunc)
                _allocClassSymbol = "allocatorGraphic";
            else {
                _allocClassSymbol = "allocatorGame";
            }
        }

        ~DLLoader() = default;

        template <class T>
        std::shared_ptr<T> DLGetInstance()
        {
            using allocClass = std::shared_ptr<T>(*)();

            allocClass allocFunc = reinterpret_cast<allocClass>(dlsym(_handle, _allocClassSymbol.c_str()));

            if (!allocFunc) {
                std::cerr << dlerror() << std::endl;
                DLCloseLib();
                throw ErrorManager("Cannot find the allocFunc");
            }
            return allocFunc();
        }

        void DLCloseLib()
        {
            if (_handle && dlclose(_handle) != 0) {
                std::cerr << dlerror() << std::endl;
                throw ErrorManager("Failed to close the lib");
            }
        }

        std::string getPath() {
            return this->_pathToLib;
        }

        std::string getType() {
            return this->_allocClassSymbol;
        }
    };
}

#endif /* !DLLOADER_HPP_ */
