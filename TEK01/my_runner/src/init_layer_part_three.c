/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** init_layer_part_three.c
*/

#include "include.h"

void init_ground(sprite_t *ground)
{
    ground->sprite = sfSprite_create();
    ground->pos.x = 0;
    ground->pos.y = 650;
    ground->scale.x = 12;
    ground->scale.y = 12;
    ground->texture = sfTexture_createFromFile("ressources/ground.png", NULL);
    sfSprite_setPosition(ground->sprite, ground->pos);
    sfSprite_setScale(ground->sprite, ground->scale);
    sfSprite_setTexture(ground->sprite, ground->texture, sfFalse);
}

void init_moon(sprite_t *moon)
{
    moon->sprite = sfSprite_create();
    moon->pos.x = 100;
    moon->pos.y = 100;
    moon->scale.x = 7;
    moon->scale.y = 7;
    moon->rect.top = 0;
    moon->rect.left = 448;
    moon->rect.height = 64;
    moon->rect.width = 64;
    moon->texture = sfTexture_createFromFile("ressources/sprite.png", NULL);
    sfSprite_setPosition(moon->sprite, moon->pos);
    sfSprite_setScale(moon->sprite, moon->scale);
    sfSprite_setTexture(moon->sprite, moon->texture, sfFalse);
    sfSprite_setTextureRect(moon->sprite,moon->rect);
}
