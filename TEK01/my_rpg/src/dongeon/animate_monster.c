/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** animate_monster
*/

#include "dongeon.h"

void animation(monster_t *monster, int nbr)
{
    if (monster->sprite.rect.left >= nbr * monster->sprite.rect.width) {
        monster->attacking = 0;
        monster->sprite.rect.left = 0;
    }
}

void animate_spear(monster_t *monster, window_t *window)
{
    if (monster->walking && !monster->attacking)
        animate_sprite(&monster->sprite, window, 9);
    else if (monster->attacking) {
        animate_sprite(&monster->sprite, window, 13);
        animation(monster, 12);
    } else {
        monster->sprite.rect.top = 0;
        animate_sprite(&monster->sprite, window, 4);
    }
}

void animate_skull(monster_t *monster, window_t *window)
{
    if (monster->walking && !monster->attacking)
        animate_sprite(&monster->sprite, window, 7);
    else if (monster->attacking) {
        animate_sprite(&monster->sprite, window, 24);
        animation(monster, 23);
    } else {
        monster->sprite.rect.top = 0;
        animate_sprite(&monster->sprite, window, 7);
    }
}

void animate_archer(monster_t *monster, window_t *window)
{
    if (monster->walking && !monster->attacking)
        animate_sprite(&monster->sprite, window, 9);
    else if (monster->attacking) {
        animate_sprite(&monster->sprite, window, 10);
        animation(monster, 9);
    } else {
        monster->sprite.rect.top = 0;
        animate_sprite(&monster->sprite, window, 4);
    }
    display_arrow(window, monster->spell, monster);
}