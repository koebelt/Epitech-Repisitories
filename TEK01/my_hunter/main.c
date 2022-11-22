/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** main.c
*/

#include "include.h"

void usage(void)
{
    my_putstr("Welcome to DRUNKS REVENGE\n");
    my_putstr("To start a game, click on the top bottle\n");
    my_putstr("To stop a game, press ESCAPE (you will not be able to resume)");
    my_putstr("\nTo change your bottle, click on the bottom bottles\n");
    my_putstr("Have fun playing my game !\n");
}

void move_rect(sfIntRect *rect, int size)
{
    if ((rect->left + rect->width) < size)
        rect->left += rect->width;
    else
        rect->left = 0;
}

void init_window(window_obj_t *window_objects)
{
    init_game(&window_objects->game);
    for (int i = 0; i < 20; ++i)
        window_objects->game.particles.particle_tab[i].rect.left = 0;
    window_objects->game.bottle.rect.left = 0;
    init_menu(&window_objects->menu);
    init_choose_menu(&window_objects->choose);
    window_objects->mode.width = 1080;
    window_objects->mode.height = 720;
    window_objects->mode.bitsPerPixel = 32;
    window_objects->background.r = 67;
    window_objects->background.g = 75;
    window_objects->background.b = 87;
    window_objects->index = 0;
    window_objects->high_score = 0;
}

int main(int ac, char **av)
{
    void (*main_tab[3]) (window_obj_t *) = {menu_play, game_play, choose_play};
    window_obj_t window_objects;

    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
        usage();
    init_window(&window_objects);
    init_save(&window_objects);
    window_objects.window = sfRenderWindow_create(window_objects.mode,
    "Drunks Revenge", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window_objects.window, 60);
    sfRenderWindow_setMouseCursorVisible(window_objects.window, sfFalse);
    while (sfRenderWindow_isOpen(window_objects.window)) {
        (*main_tab[window_objects.index]) (&window_objects);
        sfRenderWindow_display(window_objects.window);
        sfRenderWindow_clear(window_objects.window, window_objects.background);
    }
    write_on_save(&window_objects);
    sfRenderWindow_destroy(window_objects.window);
}
