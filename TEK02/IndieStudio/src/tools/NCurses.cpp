/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL : Ubuntu]
** File description:
** NCurses
*/

#include "NCurses.hpp"

/**
** @author : Mathieu Suk and Tristan Courty
**
** @brief Class NCurses constructor
**/
istudio::NCurses::NCurses()
{
    initscr();
    _win = newwin(800, 600, 1, 10);
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
}

/**
** @author : Mathieu Suk and Tristan Courty
**
** @brief Class NCurses destructor
**/
istudio::NCurses::~NCurses()
{
    _isOpen = false;
    endwin();
}

/**
** @author : Mathieu Suk and Tristan Courty
**
** @brief Function render: Display the matrix of the map with ncurses
** @param matrix The matrix you want to display
**
** @return void
**/
void istudio::NCurses::render(Matrix matrix)
{
    refresh();
    clear();
    if (int(matrix.getCols()) > COLS || int(matrix.getRows()) > LINES) {
        mvprintw(0, 0, "Your terminal is too small...");
        return;
    }
    for (size_t y = 0; y < matrix.getRows(); y++) {
        for (size_t x = 0; x < matrix.getCols(); x++) {
            attron(COLOR_PAIR(2));
            mvaddch((LINES / 2) - (matrix.getRows() / 2) + y, (COLS / 2) - (matrix.getCols() / 2) + x, matrix(y, x));
            attroff(COLOR_PAIR(2));
        }
    }
    box(stdscr, '|', '-');
}