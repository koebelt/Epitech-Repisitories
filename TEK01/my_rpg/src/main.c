/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** main
*/

#include "../include/include.h"

int usage(void)
{
    write(1, "MY RPG\n", 8);
    write(1, "USAGE\n", 7);
    write(1, "\t-h Display usage\n\n", 20);
    write(1, "USER INTERACTIONS\n", 19);
    write(1, "\tLEFT CLICK  select an object\n", 31);
    write(1, "\tESCAPE  pause or return to previous menu\n", 43);
    return (0);
}

void init_window_second(window_t *window)
{
    init_exterior(window);
    create_tab(window);
    init_inventory(window);
    init_dungeon(window);
    init_videostg(window);
    init_pause(window);
    init_howtoplay(window);
}

void init_window(window_t *window)
{
    window->clock = sfClock_create();
    window->mode.width = 1240;
    window->mode.height = 720;
    window->mode.bitsPerPixel = 32;
    window->music_volume = 20;
    window->sound_volume = 50;
    window->index = 0;
    window->color = WATER_COLOR;
    window->window = sfRenderWindow_create(window->mode,
    "My RPG", sfClose, NULL);
    window->menu.settings.music_status = 1;
    window->menu.settings.videosettings.sound_status = 1;
    sfRenderWindow_setPosition(window->window, (sfVector2i){0, 0});
    sfRenderWindow_setIcon(window->window, 420, 420, sfImage_getPixelsPtr(
    sfImage_createFromFile("assets/menu/dungeon_quest.png")));
    sfRenderWindow_setFramerateLimit(window->window, 60);
    init_menu(window);
    init_settings(window);
    init_window_second(window);
}

void events(window_t *window, void (*event_fcn) (window_t *))
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->index == GAME_ID || window->index == DONGEONS_ID)
        if (window->event.type == sfEvtKeyPressed && window->event.key.code ==
        sfKeyEscape) {
            window->stackg = window->index;
            window->index = PAUSE_ID;
        }
    (*event_fcn) (window);
}

int main(int ac, char **av)
{
    void (*scene_tab[7]) (window_t *) = {run_menu, run_exterior, run_settings,
    run_dongeon, run_videostg, run_pause, run_howtoplay};
    void (*events_tab[7]) (window_t *) = {event_menu, exterior_events,
    event_settings, dungeon_events, event_videostg, event_pause,
    event_howtoplay};
    window_t window;

    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
        return (usage());
    randomize();
    init_window(&window);
    while (sfRenderWindow_isOpen(window.window)) {
        while (sfRenderWindow_pollEvent(window.window, &window.event))
            events(&window, (*events_tab[window.index]));
        window.mouse = sfMouse_getPositionRenderWindow(window.window);
        (*scene_tab[window.index]) (&window);
        sfRenderWindow_display(window.window);
        sfRenderWindow_clear(window.window, window.color);
    }
    sfRenderWindow_destroy(window.window);
}