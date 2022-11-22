/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

namespace arcade {

    Ncurses::Ncurses()
    {
        //std::cout << "\033[?1003h" << std::endl;
        
    }

    Ncurses::~Ncurses()
    {
    }

    bool Ncurses::isOpen()
    {
        if (_last_event == KEY_BACKSPACE)
            return false;
        else
            return true;
    }

    std::shared_ptr<arcade::Event> Ncurses::getCurrentEvent()
    {
        _last_event = wgetch(stdscr);

        if (_last_event != ERR) {
            switch (_last_event) {
                case KEY_DOWN:
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_DOWN}));
                case KEY_UP:
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_UP}));
                case KEY_LEFT:
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_LEFT}));
                case KEY_RIGHT:
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_RIGHT}));
                case KEY_ENTER:
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_ENTER}));
                case ' ':
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_SPACE}));
                case 'y':
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_Y}));
                case 'u':
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_U}));
                case 'i':
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_I}));
                case 'o':
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_O}));
                case 'r':
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_R}));
                case 'm':
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {Event::AKEY_M}));
                default:
                    return std::make_shared<arcade::Event>(Event(Event::AKEY_PRESS, {_last_event}));
            }
        }
        return nullptr;
    }

    float Ncurses::getTimeElapsed()
    {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(end - _time_elapsed).count();
    }

    void Ncurses::resetTimer()
    {
        _time_elapsed = std::chrono::steady_clock::now();
    }

    void Ncurses::render(Matrix matrix)
    {
        clear();
        if (matrix.getCols() > (std::size_t)COLS || matrix.getRows() > (std::size_t)LINES) {
            mvprintw((LINES / 2), (COLS / 2) - (27 / 2), "Your terminal is too small");
            mvprintw((LINES / 2) + 1, (COLS / 2) - (18 / 2), "please enlarge it");
        } else {
            for (std::size_t i = 0; i < matrix.getRows() ; ++i) {
                for (std::size_t j = 0; j < matrix.getCols(); ++j) {
                        setProp(matrix(i, j));
                        mvaddch((LINES / 2) - (matrix.getRows() / 2) + i, (COLS / 2) - (matrix.getCols() / 2) + j, matrix(i, j));
                        attron(COLOR_PAIR(1));
                }
            }
        }
        refresh();
    }

    void Ncurses::setProp(char c) {
        for (std::size_t i = 0; i < _props.size(); ++i) {
            PropertyList *tmp = dynamic_cast<PropertyList *>(_props[i].get());
            if (tmp && tmp->getSymbol() == c) {
                attron(COLOR_PAIR(tmp->getOr<int>("N:color", 1)));
            }
            if (tmp && tmp->getSymbol() == 'T') {
                timeout(tmp->getOr<int>("N:timeout", 350));
            }
        }
    }

    void Ncurses::render()
    {
        clear();
        mvprintw((LINES / 2), (COLS / 2) - (29 / 2), "Previous lib: y, Next lib: u");
        mvprintw((LINES / 2) + 3, (COLS / 2) - (31 / 2), "Previous game: i, Next game: o");
        mvprintw((LINES / 2) + 6, (COLS / 2) - (18 / 2), "Backspace to quit");
        refresh();
    }

    void Ncurses::close()
    {
        endwin();
    }
    
    void Ncurses::init()
    {
        initscr();
        keypad(stdscr, TRUE);
        noecho();
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_YELLOW, COLOR_BLACK);

        timeout(117);
        _time_elapsed = std::chrono::steady_clock::now();
    }
    
    int Ncurses::loadProperties(std::vector<std::shared_ptr<Property>> props)
    {
        _props = props;
        return 0;
    }
    
    const std::string Ncurses::getName() const 
    {
        return "ncurses";
    }
}
