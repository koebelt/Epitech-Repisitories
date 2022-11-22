/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** game.c
*/

#include "include.h"

int game_mouse_click(sfMouseButtonEvent mouse_pos, bottle_t *bottle,
    sfRenderWindow **window)
{
    int width = bottle->rect.width;
    int height = bottle->rect.height;

    if (mouse_pos.x >= (bottle->pos.x - width * 4) && mouse_pos.x <=
    (bottle->pos.x + width * 4) && mouse_pos.y >= (bottle->pos.y - height * 4)
    && mouse_pos.y <= (bottle->pos.y + height * 4) && !bottle->breaked) {
        return (2);
    }
    return (0);
}

int analyse_game_events(window_obj_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed) {
        sfSound_play(window->game.gun);
        window->game.crosshair.shooting = 2;
        return(game_mouse_click(window->event.mouseButton, &window->game.bottle,
        &window->window));
    }
    if(sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        window->index = 0;
    return (0);
}

void game_events(window_obj_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)){
        if (analyse_game_events(window)) {
            window->game.particle_clock = sfClock_create();
            sfSound_play(window->game.breaking_bottle);
            init_particles(&window->game.particles, &window->game.bottle);
            window->game.bottle.breaked = 1;
            window->game.score += 1;
        }
    }
}

void game_play(window_obj_t *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);

    game_events(window);
    if (window->game.bottle.pos.y > 730) {
        if (!window->game.bottle.breaked)
            --window->game.health;
        window->game.bottle.breaked = 0;
        init_bottle(&window->game.bottle);
        sfClock_restart(window->game.mvmnt_clock);
    }
    if (window->game.crosshair.shooting)
        window->game.hand.shooting = 3;
    disp_game(window, mouse);
    if (window->game.bottle.breaked == 1)
        explose_particles(&window->game.particles, &window->window,
        window->game.particle_clock);
    window->high_score = window->high_score < window->game.score ?
    window->game.score : window->high_score;
    if (window->game.health == 0) {
        window->index = 0;
        window->game.health = 11;
    }
}
