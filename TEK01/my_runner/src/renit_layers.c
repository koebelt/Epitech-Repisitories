/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** renit_layers.c
*/

#include "include.h"

void renit_cloud(layer_t *cloud, int i)
{
    cloud->sprite[i].sprite = sfSprite_create();
    cloud->sprite[i].pos.x = (rand() % (1380 - 1080) + 1080);
    cloud->sprite[i].pos.y = (rand() % (300 - 50) + 50);
    cloud->sprite[i].scale.x = 5;
    cloud->sprite[i].scale.y = 5;
    if (rand() % 100 < 50) {
        cloud->sprite[i].rect.top = 208;
        cloud->sprite[i].rect.left = 441;
        cloud->sprite[i].rect.height = 32;
        cloud->sprite[i].rect.width = 71;
    } else {
        cloud->sprite[i].rect.top = 224;
        cloud->sprite[i].rect.left = 401;
        cloud->sprite[i].rect.height = 16;
        cloud->sprite[i].rect.width = 30;
    }
    cloud->sprite[i].texture =
    sfTexture_createFromFile("ressources/sprite.png", NULL);
    sfSprite_setScale(cloud->sprite[i].sprite, cloud->sprite[i].scale);
    sfSprite_setTexture(cloud->sprite[i].sprite, cloud->sprite[i].texture,
    sfFalse);
    sfSprite_setTextureRect(cloud->sprite[i].sprite, cloud->sprite[i].rect);

}

void renit_cloud2(layer_t *cloud, int i)
{
    int random = (rand() % 100);
    cloud->sprite[i].sprite = sfSprite_create();
    cloud->sprite[i].pos.x = (rand() % (1100 - 1080) + 1080);
    cloud->sprite[i].pos.y = (rand() % (500 - 300) + 300);
    cloud->sprite[i].scale.x = 7;
    cloud->sprite[i].scale.y = 7;
    if (random < 20) {
        cloud->sprite[i].rect.top = 213;
        cloud->sprite[i].rect.left = 359;
        cloud->sprite[i].rect.height = 7;
        cloud->sprite[i].rect.width = 18;
    } else if (random < 40) {
        cloud->sprite[i].rect.top = 217;
        cloud->sprite[i].rect.left = 338;
        cloud->sprite[i].rect.height = 4;
        cloud->sprite[i].rect.width = 8;
    } else if (random < 60) {
        cloud->sprite[i].rect.top = 232;
        cloud->sprite[i].rect.left = 264;
        cloud->sprite[i].rect.height = 6;
        cloud->sprite[i].rect.width = 20;
    } else if (random < 80) {
        cloud->sprite[i].rect.top = 215;
        cloud->sprite[i].rect.left = 291;
        cloud->sprite[i].rect.height = 5;
        cloud->sprite[i].rect.width = 12;
    } else {
        cloud->sprite[i].rect.top = 229;
        cloud->sprite[i].rect.left = 249;
        cloud->sprite[i].rect.height = 16;
        cloud->sprite[i].rect.width = 14;
    }
    cloud->sprite[i].texture = sfTexture_createFromFile("ressources/sprite.png",
    NULL);
    sfSprite_setScale(cloud->sprite[i].sprite, cloud->sprite[i].scale);
    sfSprite_setTexture(cloud->sprite[i].sprite, cloud->sprite[i].texture,
    sfFalse);
    sfSprite_setTextureRect(cloud->sprite[i].sprite, cloud->sprite[i].rect);

}
