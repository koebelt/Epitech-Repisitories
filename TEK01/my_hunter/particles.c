/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** particles.c
*/

#include "include.h"

void init_particles_sprites(particles_t *particles, bottle_t *bottle, int i)
{
    particles->particle_tab[i].sprite = sfSprite_create();
    particles->particle_tab[i].pos.x = 500;
    particles->particle_tab[i].pos.y = 300;
    particles->particle_tab[i].scale.x = 8;
    particles->particle_tab[i].scale.y = 8;
    particles->particle_tab[i].rect.top = 0;
    particles->particle_tab[i].rect.width = 1;
    particles->particle_tab[i].rect.height = 1;
    particles->particle_tab[i].texture =
    sfTexture_createFromFile("ressources/particless.png", NULL);
    particles->particle_tab[i].size_text =
    sfTexture_getSize(particles->particle_tab[i].texture);
    sfSprite_setTexture(particles->particle_tab[i].sprite,
    particles->particle_tab[i].texture, sfFalse);
    sfSprite_setTextureRect(particles->particle_tab[i].sprite,
    particles->particle_tab[i].rect);
}

void init_particles(particles_t *particles, bottle_t *bottle)
{
    int angle = 0;

    srand(time(NULL));
    for (int i = 0; i < 20; ++i) {
        angle = rand() % 360;
        particles->particle_tab[i].a = angle * 3.14159265 / 180;
        particles->particle_tab[i].y0 = bottle->pos.y;
        particles->particle_tab[i].x0 = bottle->pos.x;
        particles->particle_tab[i].V0 = rand() % (100 - 20) + 20;
        init_particles_sprites(particles, bottle, i);
    }
}

void explose_particles(particles_t *particles, sfRenderWindow **window,
    sfClock *mvmnt_clock)
{
    sfTime time = sfClock_getElapsedTime(mvmnt_clock);
    float seconds = time.microseconds / 100000.0;
    float g = 9.81;

    for (int i = 0; i < 20; ++i) {
        particles->particle_tab[i].pos.x = cos(particles->particle_tab[i].a) *
        particles->particle_tab[i].V0 * seconds + particles->particle_tab[i].x0;
        particles->particle_tab[i].pos.y = -1 *((0.5 * (-g) * pow(seconds, 2)) +
        sin(particles->particle_tab[i].a) * particles->particle_tab[i].V0 *
        seconds - particles->particle_tab[i].y0);
        sfSprite_setPosition(particles->particle_tab[i].sprite,
        particles->particle_tab[i].pos);
        sfSprite_setScale(particles->particle_tab[i].sprite,
        particles->particle_tab[i].scale);
        sfRenderWindow_drawSprite(*window, particles->particle_tab[i].sprite,
        NULL);
        sfSprite_setTextureRect(particles->particle_tab[i].sprite,
        particles->particle_tab[i].rect);
    }
}
