/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** death.c
*/

#include "include.h"

void init_particles_sprites(hero_t *hero, int i)
{
    hero->death_particles[i].sprite.sprite = sfSprite_create();
    hero->death_particles[i].sprite.pos.x = 0;
    hero->death_particles[i].sprite.pos.y = 0;
    hero->death_particles[i].sprite.scale.x = 8;
    hero->death_particles[i].sprite.scale.y = 8;
    hero->death_particles[i].sprite.texture =
    sfTexture_createFromFile("ressources/blood.png", NULL);
    sfSprite_setTexture(hero->death_particles[i].sprite.sprite,
    hero->death_particles[i].sprite.texture, sfFalse);
}

void init_death(hero_t *hero, sfClock *clock, sfSound *death,
    window_obj_t *window)
{
    int angle = 0;

    hero->time_0 = sfClock_getElapsedTime(clock).microseconds / 100000.0;
    srand(time(NULL));
    for (int i = 0; i < 80; ++i) {
        angle = rand() % 360;
        hero->death_particles[i].a = angle * 3.14159265 / 180;
        hero->death_particles[i].y0 = hero->sprite.pos.y + 100;
        hero->death_particles[i].x0 = hero->sprite.pos.x + 70;
        hero->death_particles[i].V0 = rand() % (65 - 5) + 5;
        init_particles_sprites(hero, i);
    }
    if (window->game.percent > my_getnbr(
    window->high_score[window->menu.map_index - 1]))
        window->high_score[window->menu.map_index - 1] =
        my_int_to_str(window->game.percent);
    sfSound_play(death);
}

int death_particles(hero_t *hero, sfRenderWindow **window, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 100000.0 - hero->time_0;
    float g = 9.81;

    for (int i = 0; i < 80; ++i) {
        hero->death_particles[i].sprite.pos.x = cos(hero->death_particles[i].a)
        * hero->death_particles[i].V0 * seconds + hero->death_particles[i].x0;
        hero->death_particles[i].sprite.pos.y = -1 *((0.5 * (-g) *
        pow(seconds, 2)) + sin(hero->death_particles[i].a) *
        hero->death_particles[i].V0 * seconds - hero->death_particles[i].y0);
        sfSprite_setPosition(hero->death_particles[i].sprite.sprite,
        hero->death_particles[i].sprite.pos);
        sfSprite_setScale(hero->death_particles[i].sprite.sprite,
        hero->death_particles[i].sprite.scale);
        sfRenderWindow_drawSprite(*window,
        hero->death_particles[i].sprite.sprite, NULL);
    }
    if (seconds > 10)
        return (1);
}
