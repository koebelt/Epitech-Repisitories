/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** choose_index.c
*/

#include "include.h"

int analyse_choose_events(window_obj_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed) {
        sfSound_play(window->game.gun);
        window->choose.crosshair.shooting = 2;
        return(choose_mouse_click(window->event.mouseButton, &window->choose));
    }
    if(sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        window->index = 0;
    return (0);
}

void change_index3(window_obj_t *window, int bottle_index)
{
    if (bottle_index == 5 && window->high_score >= 75) {
        window->index = 0;
        window->game.bottle.rect.left = 60;
        sfSound_play(window->game.breaking_bottle);
        sfSprite_setTextureRect(window->game.bottle.sprite,
        window->game.bottle.rect);
        for (int i = 0; i < 20; ++i)
            window->game.particles.particle_tab[i].rect.left = 4;
    }
    if (bottle_index == 6 && window->high_score >= 100) {
        window->index = 0;
        window->game.bottle.rect.left = 75;
        sfSound_play(window->game.breaking_bottle);
        sfSprite_setTextureRect(window->game.bottle.sprite,
        window->game.bottle.rect);
        for (int i = 0; i < 20; ++i)
            window->game.particles.particle_tab[i].rect.left = 5;
    }
}

void change_index2(window_obj_t *window, int bottle_index)
{
    if (bottle_index == 3 && window->high_score >= 30) {
        window->index = 0;
        window->game.bottle.rect.left = 30;
        sfSound_play(window->game.breaking_bottle);
        sfSprite_setTextureRect(window->game.bottle.sprite,
        window->game.bottle.rect);
        for (int i = 0; i < 20; ++i)
            window->game.particles.particle_tab[i].rect.left = 2;
    }
    if (bottle_index == 4 && window->high_score >= 50) {
        window->index = 0;
        window->game.bottle.rect.left = 45;
        sfSound_play(window->game.breaking_bottle);
        sfSprite_setTextureRect(window->game.bottle.sprite,
        window->game.bottle.rect);
        for (int i = 0; i < 20; ++i)
            window->game.particles.particle_tab[i].rect.left = 3;
    } else
        change_index3(window, bottle_index);
}

void change_index(window_obj_t *window, int bottle_index)
{
    if (bottle_index == 1) {
        window->index = 0;
        window->game.bottle.rect.left = 0;
        sfSound_play(window->game.breaking_bottle);
        sfSprite_setTextureRect(window->game.bottle.sprite,
        window->game.bottle.rect);
        for (int i = 0; i < 20; ++i)
            window->game.particles.particle_tab[i].rect.left = 0;
    }
    if (bottle_index == 2 && window->high_score >= 10) {
        window->index = 0;
        window->game.bottle.rect.left = 15;
        sfSound_play(window->game.breaking_bottle);
        sfSprite_setTextureRect(window->game.bottle.sprite,
        window->game.bottle.rect);
        for (int i = 0; i < 20; ++i)
            window->game.particles.particle_tab[i].rect.left = 1;
    } else
        change_index2(window, bottle_index);
}
