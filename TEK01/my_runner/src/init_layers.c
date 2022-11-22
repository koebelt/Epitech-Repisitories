/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** init_layers.c
*/

#include "include.h"

void init_game_layer(background_t *background)
{
    init_dune(&background->layers[0]);
    init_mount(&background->layers[1]);
    init_ground(&background->ground);
    init_moon(&background->moon);
    init_ground_layer(&background->layers[2]);
    init_grass(&background->layers[3]);
    init_grass2(&background->layers[4]);
    init_cloud(&background->layers[5]);
    init_cloud2(&background->layers[6]);
}

void init_dune(layer_t *dune)
{
    for (int i = 0; i < 3; ++i) {
        dune->sprite[i].sprite = sfSprite_create();
        dune->sprite[i].pos.x = 192 * i * 8;
        dune->sprite[i].pos.y = 500;
        dune->sprite[i].scale.x = 8;
        dune->sprite[i].scale.y = 8;
        dune->sprite[i].rect.top = 139;
        dune->sprite[i].rect.left = 320;
        dune->sprite[i].rect.height = 21;
        dune->sprite[i].rect.width = 192;
        dune->sprite[i].texture =
        sfTexture_createFromFile("ressources/sprite.png", NULL);
        sfSprite_setScale(dune->sprite[i].sprite, dune->sprite[i].scale);
        sfSprite_setTexture(dune->sprite[i].sprite, dune->sprite[i].texture,
        sfFalse);
        sfSprite_setTextureRect(dune->sprite[i].sprite, dune->sprite[i].rect);
    }
}

void init_mount(layer_t *mount)
{
    for (int i = 0; i < 3; ++i) {
        mount->sprite[i].sprite = sfSprite_create();
        mount->sprite[i].pos.x = 200 * i * 8;
        mount->sprite[i].pos.y = 350;
        mount->sprite[i].scale.x = 8;
        mount->sprite[i].scale.y = 8;
        mount->sprite[i].rect.top = 173;
        mount->sprite[i].rect.left = 288;
        mount->sprite[i].rect.height = 35;
        mount->sprite[i].rect.width = 127;
        mount->sprite[i].texture =
        sfTexture_createFromFile("ressources/sprite.png", NULL);
        sfSprite_setScale(mount->sprite[i].sprite, mount->sprite[i].scale);
        sfSprite_setTexture(mount->sprite[i].sprite, mount->sprite[i].texture,
        sfFalse);
        sfSprite_setTextureRect(mount->sprite[i].sprite, mount->sprite[i].rect);
    }
}

void init_ground_layer(layer_t *ground)
{
    for (int i = 0; i < 3; ++i) {
        ground->sprite[i].sprite = sfSprite_create();
        ground->sprite[i].pos.x = 208 * i * 8;
        ground->sprite[i].pos.y = 666;
        ground->sprite[i].scale.x = 8;
        ground->sprite[i].scale.y = 8;
        ground->sprite[i].rect.top = 112;
        ground->sprite[i].rect.left = 304;
        ground->sprite[i].rect.height = 5;
        ground->sprite[i].rect.width = 208;
        ground->sprite[i].texture =
        sfTexture_createFromFile("ressources/sprite.png", NULL);
        sfSprite_setScale(ground->sprite[i].sprite, ground->sprite[i].scale);
        sfSprite_setTexture(ground->sprite[i].sprite, ground->sprite[i].texture,
        sfFalse);
        sfSprite_setTextureRect(ground->sprite[i].sprite,
        ground->sprite[i].rect);
    }
}

void init_grass(layer_t *grass)
{
    for (int i = 0; i < 3; ++i) {
        grass->sprite[i].sprite = sfSprite_create();
        grass->sprite[i].pos.x = 85 * i * 8;
        grass->sprite[i].pos.y = 636;
        grass->sprite[i].scale.x = 5;
        grass->sprite[i].scale.y = 5;
        grass->sprite[i].rect.top = 218;
        grass->sprite[i].rect.left = 165;
        grass->sprite[i].rect.height = 6;
        grass->sprite[i].rect.width = 45;
        grass->sprite[i].texture =
        sfTexture_createFromFile("ressources/sprite.png", NULL);
        sfSprite_setScale(grass->sprite[i].sprite, grass->sprite[i].scale);
        sfSprite_setTexture(grass->sprite[i].sprite, grass->sprite[i].texture,
        sfFalse);
        sfSprite_setTextureRect(grass->sprite[i].sprite, grass->sprite[i].rect);
    }
}
