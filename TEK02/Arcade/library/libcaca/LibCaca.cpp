/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** LibCaca
*/

#include "LibCaca.hpp"

namespace arcade {

    LibCaca::LibCaca()
    {
        _dp = nullptr;
        _cv = nullptr;
    }

    LibCaca::~LibCaca()
    {
    }

    bool LibCaca::isOpen()
    {
        if (_last_event == CACA_KEY_BACKSPACE || _quit)
            return false;
        else
            return true;
    }

    std::shared_ptr<arcade::Event> LibCaca::getCurrentEvent()
    {
        caca_event_t ev;

        if (caca_get_event(_dp, CACA_EVENT_ANY, &ev, _timeout)) {
            if (caca_get_event_type(&ev) & CACA_EVENT_QUIT) {
                _quit = true;
                return nullptr;
            }
            _last_event = ev.data.key.ch;
            if (caca_get_event_type(&ev) & CACA_EVENT_KEY_PRESS || caca_get_event_type(&ev) & CACA_EVENT_KEY_RELEASE) {
                if (caca_get_event_type(&ev) & CACA_EVENT_KEY_PRESS)
                    switch (_last_event) {
                        case CACA_KEY_DOWN:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_DOWN}));
                        case CACA_KEY_UP:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_UP}));
                        case CACA_KEY_LEFT:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_LEFT}));
                        case CACA_KEY_RIGHT:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_RIGHT}));
                        case CACA_KEY_RETURN:
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_ENTER}));
                        case ' ':
                            _last_event = 0;
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_SPACE}));
                        case 'y':
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_Y}));
                            _last_event = 0;
                        case 'u':
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_U}));
                            _last_event = 0;
                        case 'i':
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_I}));
                            _last_event = 0;
                        case 'o':
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_O}));
                            _last_event = 0;
                        case 'r':
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_R}));
                            _last_event = 0;
                        case 'm':
                            return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_M}));
                            _last_event = 0;
                        default:
                            return nullptr;
                    }
            } else
                    return getCurrentEvent();
        }
        return nullptr;
    }

    float LibCaca::getTimeElapsed()
    {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(end - _time_elapsed).count();
    }

    void LibCaca::resetTimer()
    {
        _time_elapsed = std::chrono::steady_clock::now();
    }

    void LibCaca::render(Matrix matrix)
    {
        caca_clear_canvas(_cv);
        for (std::size_t i = 0; i < matrix.getRows() ; ++i) {
            for (std::size_t j = 0; j < matrix.getCols(); ++j) {
                caca_unset_attr(_cv, CACA_ITALICS);
                setProp(matrix(i, j));
                caca_put_char(_cv, (caca_get_canvas_width(_cv) / 2) - (matrix.getCols() / 2) + j, (caca_get_canvas_height(_cv) / 2) - (matrix.getRows() / 2) + i, matrix(i, j));
                caca_set_color_ansi(_cv, CACA_WHITE, CACA_BLACK);
            }
        }
        caca_refresh_display(_dp);
    }

    void LibCaca::setProp(char c) {
        for (std::size_t i = 0; i < _props.size(); ++i) {
            PropertyList *tmp = dynamic_cast<PropertyList *>(_props[i].get());
            if (tmp && tmp->getSymbol() == c) {
                caca_set_color_ansi(_cv, (tmp->getOr<int>("C:color", 15)), CACA_BLACK);
            }
            if (tmp && tmp->getSymbol() == 'T')
                _timeout = tmp->getOr<int>("C:timeout", 350000);
        }
        //caca_set_display_title(_dp, dynamic_cast<PropertyBasic *>(_props[0].get())->getElement<std::string>().c_str());
    }

    void LibCaca::render()
    {
        caca_clear_canvas(_cv);
        caca_printf(_cv, (caca_get_canvas_width(_cv) / 2) - (29 / 2), (caca_get_canvas_height(_cv) / 2), "Previous lib: y, Next lib: u");
        caca_printf(_cv, (caca_get_canvas_width(_cv) / 2) - (31 / 2), (caca_get_canvas_height(_cv) / 2) + 2, "Previous game: i, Next game: o");
        caca_refresh_display(_dp);
    }

    void LibCaca::close()
    {
        if (_cv)
            caca_free_canvas(_cv);
        if (_dp)
            caca_free_display(_dp);
    }
    
    void LibCaca::init()
    {
        _dp = caca_create_display(NULL);
        if (!_dp)
            throw ErrorManager("Failed to create a caca display");
        _cv = caca_get_canvas(_dp);
        caca_set_display_title(_dp, "LibCaca");
        caca_set_color_ansi(_cv, CACA_WHITE, CACA_BLACK);
        _time_elapsed = std::chrono::steady_clock::now();
    }
    
    int LibCaca::loadProperties(std::vector<std::shared_ptr<Property>> props)
    {
        _props = props;
        return 0;
    }
    
    const std::string LibCaca::getName() const 
    {
        return "libcaca";
    }
}

