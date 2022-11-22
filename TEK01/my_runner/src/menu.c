/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** menu.c
*/

#include "include.h"

int menu_mouse_event(menu_obj_t *menu, sfMouseButtonEvent mouse,
    window_obj_t *window)
{
    sfFloatRect start_box = sfSprite_getGlobalBounds(menu->start.sprite.sprite);
    sfFloatRect quit_box = sfSprite_getGlobalBounds(menu->quit.sprite.sprite);
    sfFloatRect reset_box = sfSprite_getGlobalBounds(menu->reset.sprite.sprite);
    sfFloatRect left_box = sfSprite_getGlobalBounds(menu->left.sprite.sprite);
    sfFloatRect right_box = sfSprite_getGlobalBounds(menu->right.sprite.sprite);

    if (sfFloatRect_contains(&start_box, mouse.x, mouse.y))
        return (1);
    if (sfFloatRect_contains(&quit_box, mouse.x, mouse.y)) {
        sfRenderWindow_close(window->window);
        return (0);
    }
    if (sfFloatRect_contains(&reset_box, mouse.x, mouse.y)) {
        for (int i = 0; i < 3; ++i)
            window->high_score[i] = "0";
        return (0);
    }
    if (sfFloatRect_contains(&left_box, mouse.x, mouse.y)) {
        if (menu->map_index == 1)
            menu->map_index = 3;
        else
            menu->map_index -= 1;
        return (0);
    }
    if (sfFloatRect_contains(&right_box, mouse.x, mouse.y)) {
        if (menu->map_index == 3)
            menu->map_index = 1;
        else
            menu->map_index += 1;
        return (0);
    }
    return (0);
}

int analyse_menu_events(window_obj_t *window)
{
    int menu_changed = 0;
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed) {
        menu_changed = menu_mouse_event(&window->menu,
        window->event.mouseButton, window);
        if (menu_changed) {
            window->game.map = my_strcat("map",
            my_int_to_str(window->menu.map_index));
            init_game(&window->game, &window->clock, window);
            window->index = menu_changed;
        }
    }
}

void init_menu(menu_obj_t *menu, sfClock **clock, window_obj_t *window)
{
    menu->music = sfMusic_createFromFile("ressources/menu.wav");
    sfMusic_setLoop(menu->music, sfTrue);
    sfMusic_setVolume(menu->music, 20.0);
    init_game_layer(&window->game.background);
    init_hero(&window->game.hero.sprite, clock);
    init_start(&menu->start);
    init_reset(&menu->reset);
    init_quit(&menu->quit);
    init_left(&menu->left);
    init_right(&menu->right);
    init_map_txt(&menu->map_txt, &menu->map_percentage, &menu->map_index);
}

void display_hero_menu(window_obj_t *window)
{
    window->game.hero.sprite.pos.y = 505;
    anim_hero(&window->game.hero, &window->clock, &window->window);
    window->game.background.velocity = 5;
    sfRenderWindow_drawSprite(window->window,
    window->game.hero.sprite.sprite, NULL);
}

void menu(window_obj_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        analyse_menu_events(window);
    }
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    sfMusic_stop(window->game.music);
    if (!sfMusic_getStatus(window->menu.music))
        sfMusic_play(window->menu.music);
    disp_background(window);
    display_hero_menu(window);
    anim_start(&window->menu.start, mouse, &window->window);
    anim_reset(&window->menu.reset, mouse, &window->window);
    anim_quit(&window->menu.quit, mouse, &window->window);
    sfRenderWindow_drawSprite(window->window, window->menu.left.sprite.sprite,
    NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.right.sprite.sprite,
    NULL);
    anim_map_text(&window->menu, *window);
}
