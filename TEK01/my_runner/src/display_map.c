/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** display_map.c
*/

#include "include.h"

void display_map(obstacles_t *obstacles, window_obj_t *window, int v)
{
    disp_obs0(obstacles, &window->window, v);
    disp_obs1(obstacles, &window->window, v);
    disp_obs2(obstacles, &window->window, v);
    disp_obs3(obstacles, &window->window, v);
    disp_obs4(obstacles, &window->window, v);
    disp_obs5(obstacles, &window->window, v);
    disp_obs6(obstacles, &window->window, v);
    disp_obs7(obstacles, &window->window, v);
    disp_obs8(obstacles, &window->window, v);
    disp_obs9(obstacles, &window->window, v, window->clock);
}

void disp_obs0(obstacles_t *obstacles, sfRenderWindow **window, int v)
{
    for (int i = 0; i < obstacles->nbr_of_occurences[0]; ++i) {
        obstacles->obs0[i].pos.x -= v * 0.9;
        sfSprite_setPosition(obstacles->obs0[i].sprite, obstacles->obs0[i].pos);
        if (obstacles->obs0[i].pos.x > 0 - 500 && obstacles->obs0[i].pos.x < 1080)
            sfRenderWindow_drawSprite(*window, obstacles->obs0[i].sprite, NULL);
    }
}

void disp_obs1(obstacles_t *obstacles, sfRenderWindow **window, int v)
{
    for (int i = 0; i < obstacles->nbr_of_occurences[1]; ++i) {
        obstacles->obs1[i].pos.x -= v * 0.9;
        sfSprite_setPosition(obstacles->obs1[i].sprite, obstacles->obs1[i].pos);
        if (obstacles->obs1[i].pos.x > 0 - 500 && obstacles->obs1[i].pos.x < 1080)
            sfRenderWindow_drawSprite(*window, obstacles->obs1[i].sprite, NULL);
    }
}

void disp_obs2(obstacles_t *obstacles, sfRenderWindow **window, int v)
{
    for (int i = 0; i < obstacles->nbr_of_occurences[2]; ++i) {
        obstacles->obs2[i].pos.x -= v * 0.9;
        sfSprite_setPosition(obstacles->obs2[i].sprite, obstacles->obs2[i].pos);
        if (obstacles->obs2[i].pos.x > 0 - 500 && obstacles->obs2[i].pos.x < 1080)
            sfRenderWindow_drawSprite(*window, obstacles->obs2[i].sprite, NULL);
    }
}

void disp_obs3(obstacles_t *obstacles, sfRenderWindow **window, int v)
{
    for (int i = 0; i < obstacles->nbr_of_occurences[3]; ++i) {
        obstacles->obs3[i].pos.x -= v * 0.9;
        sfSprite_setPosition(obstacles->obs3[i].sprite, obstacles->obs3[i].pos);
        if (obstacles->obs3[i].pos.x > 0 - 500 && obstacles->obs3[i].pos.x < 1080)
            sfRenderWindow_drawSprite(*window, obstacles->obs3[i].sprite, NULL);
    }
}

void disp_obs4(obstacles_t *obstacles, sfRenderWindow **window, int v)
{
    for (int i = 0; i < obstacles->nbr_of_occurences[4]; ++i) {
        obstacles->obs4[i].pos.x -= v * 0.9;
        sfSprite_setPosition(obstacles->obs4[i].sprite, obstacles->obs4[i].pos);
        if (obstacles->obs4[i].pos.x > 0 - 500 && obstacles->obs4[i].pos.x < 1080)
            sfRenderWindow_drawSprite(*window, obstacles->obs4[i].sprite, NULL);
    }
}

void disp_obs5(obstacles_t *obstacles, sfRenderWindow **window, int v)
{
    for (int i = 0; i < obstacles->nbr_of_occurences[5]; ++i) {
        obstacles->obs5[i].pos.x -= v * 0.9;
        sfSprite_setPosition(obstacles->obs5[i].sprite, obstacles->obs5[i].pos);
        if (obstacles->obs5[i].pos.x > 0 - 500 && obstacles->obs5[i].pos.x < 1080)
            sfRenderWindow_drawSprite(*window, obstacles->obs5[i].sprite, NULL);
    }
}

void disp_obs6(obstacles_t *obstacles, sfRenderWindow **window, int v)
{
    for (int i = 0; i < obstacles->nbr_of_occurences[6]; ++i) {
        obstacles->obs6[i].pos.x -= v * 0.9;
        sfSprite_setPosition(obstacles->obs6[i].sprite, obstacles->obs6[i].pos);
        if (obstacles->obs6[i].pos.x > 0 - 500 && obstacles->obs6[i].pos.x < 1080)
            sfRenderWindow_drawSprite(*window, obstacles->obs6[i].sprite, NULL);
    }
}

void disp_obs7(obstacles_t *obstacles, sfRenderWindow **window, int v)
{
    for (int i = 0; i < obstacles->nbr_of_occurences[7]; ++i) {
        obstacles->obs7[i].pos.x -= v * 0.9;
        sfSprite_setPosition(obstacles->obs7[i].sprite, obstacles->obs7[i].pos);
        if (obstacles->obs7[i].pos.x > 0 - 500 && obstacles->obs7[i].pos.x < 1080)
            sfRenderWindow_drawSprite(*window, obstacles->obs7[i].sprite, NULL);
    }
}

void disp_obs8(obstacles_t *obstacles, sfRenderWindow **window, int v)
{
    for (int i = 0; i < obstacles->nbr_of_occurences[8]; ++i) {
        obstacles->obs8[i].pos.x -= v * 0.9;
        sfSprite_setPosition(obstacles->obs8[i].sprite, obstacles->obs8[i].pos);
        if (obstacles->obs8[i].pos.x > 0 - 500 && obstacles->obs8[i].pos.x < 1080)
            sfRenderWindow_drawSprite(*window, obstacles->obs8[i].sprite, NULL);
    }
}

void disp_obs9(obstacles_t *obstacles, sfRenderWindow **window, int v, sfClock *clock)
{
    for (int i = 0; i < obstacles->nbr_of_occurences[9]; ++i) {
        sfTime time = sfClock_getElapsedTime(clock);
        float seconds = time.microseconds / 1000000.0 - obstacles->obs9[i].t_0;
        obstacles->obs9[i].pos.x -= v * 0.9;
        sfSprite_setPosition(obstacles->obs9[i].sprite, obstacles->obs9[i].pos);
        if (seconds > 0.10) {
            if (obstacles->obs9[i].rect.left >= 2500)
                obstacles->obs9[i].rect.left = 0;
            else
                obstacles->obs9[i].rect.left += 320;
            obstacles->obs9[i].t_0 = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
        }
        if (obstacles->obs9[i].pos.x > 0 - 500 && obstacles->obs9[i].pos.x < 1080) {
            sfSprite_setTextureRect(obstacles->obs9[i].sprite, obstacles->obs9[i].rect);
            sfRenderWindow_drawSprite(*window, obstacles->obs9[i].sprite, NULL);
        }
    }
}
