/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** SDL2
*/

#include "SDL2.hpp"

namespace arcade {

    SDL2::SDL2()
    {
    }

    SDL2::~SDL2()
    {
    }

    bool SDL2::isOpen()
    {
        if (_last_event == SDLK_BACKSPACE || _quit)
            return false;
        else
            return true;
    }

    std::shared_ptr<arcade::Event> SDL2::getCurrentEvent()
    {
        SDL_Event event;

        if (SDL_WaitEventTimeout(&event, _timeout))
        {
            if (event.type == SDL_QUIT) {
                _quit = true;
                return nullptr;
            }
            _last_event = event.key.keysym.sym;
            if (event.key.type == SDL_KEYDOWN || event.key.type == SDL_KEYUP)
            {
                if (event.key.type == SDL_KEYDOWN)
                    switch (_last_event)
                    {
                        case SDLK_UP:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_UP}));
                        case SDLK_DOWN:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_DOWN}));
                        case SDLK_LEFT:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_LEFT}));
                        case SDLK_RIGHT:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_RIGHT}));
                        case SDLK_RETURN:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_ENTER}));
                        case SDLK_SPACE:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_SPACE}));
                        case SDLK_y:
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_Y}));
                            _last_event = 0;
                        case SDLK_u:
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_U}));
                            _last_event = 0;
                        case SDLK_i:
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_I}));
                            _last_event = 0;
                        case SDLK_o:
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_O}));
                            _last_event = 0;
                        case SDLK_r:
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_R}));
                            _last_event = 0;
                        case SDLK_m:
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_M}));
                            _last_event = 0;
                        default:
                            return nullptr;
                    }
            }
            else
                return getCurrentEvent();
        }
        return nullptr;
    }

    float SDL2::getTimeElapsed()
    {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(end - _time_elapsed).count();
    }

    void SDL2::resetTimer()
    {
        _time_elapsed = std::chrono::steady_clock::now();
    }

    void SDL2::render(Matrix matrix)
    {
        std::string str;
        SDL_RenderClear(_render);
        for (std::size_t i = 0; i < matrix.getRows() ; ++i) {
            for (std::size_t j = 0; j < matrix.getCols() - 1; ++j) {
                std::string str;
                str = matrix(i, j);
                setProp(matrix(i, j));
                SDL_Surface *text = TTF_RenderText_Blended(_font, str.c_str(), _color);
                if (text == nullptr)
                    throw ErrorManager("failed to create a SDL Surface");
                SDL_Texture *texture = SDL_CreateTextureFromSurface(_render, text);
                if (text == nullptr)
                    throw ErrorManager("failed to create a SDL Texture");
                SDL_Rect position;
                SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
                position.x = 600 / 2 - ((matrix.getCols() / 2) - j) * position.w;
                position.y = 600 / 2 - ((matrix.getRows() / 2) - i) * position.h ;
                SDL_FreeSurface(text);
                SDL_SetRenderDrawColor(_render, 0, 0, 0, 255);
                SDL_RenderCopy(_render, texture, nullptr, &position);
                SDL_DestroyTexture(texture);
            }
        }
        SDL_RenderPresent(_render);
    }

    void SDL2::setProp(char c)
    {
        std::string str;
        std::vector<int> color;

        str = c;
        _color.r = 255;
        _color.g = 255;
        _color.b = 255;
        for (std::size_t i = 0; i < _props.size(); ++i) {
            PropertyList *tmp = dynamic_cast<PropertyList *>(_props[i].get());
            if (tmp && tmp->getSymbol() == c) {
                color = tmp->getOr<std::vector<int>>("D:color", std::vector<int>{255, 255, 255});
                _color.r = color[0];
                _color.g = color[1];
                _color.b = color[2];
            }
            if (tmp && tmp->getSymbol() == 'T')
                _timeout = tmp->getOr<int>("D:timeout", 350);
        }
    }

    void SDL2::render()
    {
        SDL_RenderClear(_render);
        SDL_Surface *text = TTF_RenderText_Blended(_font, "Previous lib: y, Next lib: u", SDL_Color{255, 255, 255, 255});
        if (text == nullptr)
            throw ErrorManager("failed to create a SDL Surface");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(_render, text);
        if (text == nullptr)
            throw ErrorManager("failed to create a SDL Texture");
        SDL_Rect position;
        SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
        position.x = 600 / 2 - position.w / 2;
        position.y = 600 / 2 - position.h / 2;
        SDL_FreeSurface(text);
        SDL_SetRenderDrawColor(_render, 0, 0, 0, 0);
        SDL_RenderCopy(_render, texture, nullptr, &position);
        SDL_DestroyTexture(texture);
        text = TTF_RenderText_Blended(_font, "Previous game: i, Next game: o", SDL_Color{255, 255, 255, 255});
        if (text == nullptr)
            throw ErrorManager("failed to create a SDL Surface");
        texture = SDL_CreateTextureFromSurface(_render, text);
        if (text == nullptr)
            throw ErrorManager("failed to create a SDL Texture");
        SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
        position.x = 600 / 2 - position.w / 2;
        position.y = 600 / 2 - position.h / 2 + 30;
        SDL_FreeSurface(text);
        SDL_SetRenderDrawColor(_render, 0, 0, 0, 0);
        SDL_RenderCopy(_render, texture, nullptr, &position);
        SDL_DestroyTexture(texture);
        SDL_RenderPresent(_render);
    }

    void SDL2::close()
    {
        SDL_DestroyRenderer(_render);
        SDL_DestroyWindow(_win);
        TTF_CloseFont(_font);
        TTF_Quit();
        SDL_Quit();
    }

    void SDL2::init()
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError());
            throw ErrorManager("failed to init SDL");
        }
        if (TTF_Init() < 0) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
            throw ErrorManager("failed to init SDL text extention");
        }
        _win = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
        if (!_win) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
            SDL_Quit();
            throw ErrorManager("failed to create a SDL window");
        }
        _render = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED);
        if (_render == nullptr) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
            SDL_Quit();
            throw ErrorManager("failed to create a SDL renderer");
        }
        _font = TTF_OpenFont("./library/SDL2/LiberationMono.ttf", 15);
        if (_font == nullptr) {
            throw ErrorManager("failed to create a SDL font");
        }
        _time_elapsed = std::chrono::steady_clock::now();
    }
    
    int SDL2::loadProperties(std::vector<std::shared_ptr<Property>> props)
    {
        _props = props;
        return 0;
    }
    
    const std::string SDL2::getName() const 
    {
        return "SDL2";
    }
}

