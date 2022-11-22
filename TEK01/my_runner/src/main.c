/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** main.c
*/

#include "include.h"

void usage(void)
{
    my_putstr("My Runner\n");
    my_putstr("USAGE\n");
    my_putstr("\t-h Display usage\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\tSPACE  Jump\n");
    my_putstr("\tESCAPE  Return to menu\n");
}

void init_window(window_obj_t *window)
{
    window->clock = sfClock_create();
    window->game.map = "map1";
    init_game(&window->game, &window->clock, window);
    init_menu(&window->menu, &window->clock, window);
    init_win(&window->win, window);
    window->mode.width = 1080;
    window->mode.height = 720;
    window->mode.bitsPerPixel = 32;
    window->index = 0;
    load_save(window);
}

int main(int ac, char **av)
{
    void (*main_tab[3]) (window_obj_t *) = {menu, game, win};
    window_obj_t window;

    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
        usage();
    init_window(&window);
    window.window = sfRenderWindow_create(window.mode,
    "My Runner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window.window, 60);
    while (sfRenderWindow_isOpen(window.window)) {
        (*main_tab[window.index]) (&window);
        sfRenderWindow_display(window.window);
        sfRenderWindow_clear(window.window,
        window.game.background.background_color);
    }
    write_on_save(&window);
    sfRenderWindow_destroy(window.window);
}
