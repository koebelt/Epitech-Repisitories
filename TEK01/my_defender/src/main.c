/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** main
*/

#include "../include/include.h"

int usage(void)
{
    my_putstr("MY DEFENDER\n");
    my_putstr("USAGE\n");
    my_putstr("\t-h Display usage\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\tLEFT CLICK  select an object\n");
    my_putstr("\tESCAPE  pause or return to previous menu\n");
    return (0);
}

void destroy_game(window_t *window)
{
    prepare_save(&window->player);
    sfMusic_destroy(window->menu.music);
    sfMusic_destroy(window->game.music);
    sfSound_destroy(window->click);
    sfSound_destroy(window->loose_menu.loose_sound);
    sfSound_destroy(window->win_menu.win_sound);
    sfRenderWindow_destroy(window->window);
}

void init_window2(window_t *window)
{
    init_menu(&window->menu, window);
    init_game(&window->game, &window->clock, window);
    init_pause(&window->pause);
    init_levels(&window->level_select, &window->clock);
    init_win_menu(&window->win_menu, window);
    init_loose_menu(&window->loose_menu, window);
    init_player(&window->player);
    init_shop(&window->shop, window);
    init_how_to_play(&window->how_to_play, window);
    sfSound_play(window->click);
}

void init_window(window_t *window)
{
    window->clock = sfClock_create();
    window->mode.width = 1920;
    window->mode.height = 1080;
    window->mode.bitsPerPixel = 32;
    window->music_volume = 50;
    window->sound_volume = 50;
    window->index = 0;
    window->cursor = init_sprite((sprite_info_t){0, 0, 0.7, 0.7, 0, 0, 80, 50,
    "assets/cursor.png"});
    sound_set_audio(&window->click, "assets/music/click.ogg",
    window->sound_volume);
    window->window = sfRenderWindow_create(window->mode,
    "My Defender", sfClose, NULL);
    sfRenderWindow_setPosition(window->window, (sfVector2i){0, 0});
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    init_window2(window);
}

int main(int ac, char **av)
{
    void (*main_tab[8]) (window_t *) = {menu, level_select, game, pause_game,
    win_menu, loose_menu, shop, how_to_play};
    window_t window;
    sfVector2i mouse;

    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
        return (usage());
    init_window(&window);
    while (sfRenderWindow_isOpen(window.window)) {
        window.mouse = sfMouse_getPositionRenderWindow(window.window);
        (*main_tab[window.index]) (&window);
        sfSprite_setPosition(window.cursor.sprite, (sfVector2f){window.mouse.x,
        window.mouse.y});
        sfRenderWindow_drawSprite(window.window, window.cursor.sprite, sfFalse);
        sfRenderWindow_display(window.window);
        sfRenderWindow_clear(window.window, sfBlack);
    }
    destroy_game(&window);
}