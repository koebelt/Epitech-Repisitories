/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** init_layer_part_two.c
*/

#include "include.h"

void init_grass2(layer_t *grass)
{
    for (int i = 0; i < 3; ++i) {
        grass->sprite[i].sprite = sfSprite_create();
        grass->sprite[i].pos.x = 50 * i * 8;
        grass->sprite[i].pos.y = 646;
        grass->sprite[i].scale.x = 5;
        grass->sprite[i].scale.y = 5;
        grass->sprite[i].rect.top = 220;
        grass->sprite[i].rect.left = 133;
        grass->sprite[i].rect.height = 4;
        grass->sprite[i].rect.width = 19;
        grass->sprite[i].texture =
        sfTexture_createFromFile("ressources/sprite.png", NULL);
        sfSprite_setScale(grass->sprite[i].sprite, grass->sprite[i].scale);
        sfSprite_setTexture(grass->sprite[i].sprite, grass->sprite[i].texture,
        sfFalse);
        sfSprite_setTextureRect(grass->sprite[i].sprite, grass->sprite[i].rect);
    }
}

void init_cloud(layer_t *cloud)
{
    for (int i = 0; i < 2; ++i) {
        cloud->sprite[i].sprite = sfSprite_create();
        cloud->sprite[i].pos.x = (rand() % (150 - 50) + 50) * i * 8;
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
        init_cloud_part_two(cloud, i);
    }
}

void init_cloud_part_two(layer_t *cloud, int i)
{
    cloud->sprite[i].texture =
    sfTexture_createFromFile("ressources/sprite.png", NULL);
    sfSprite_setScale(cloud->sprite[i].sprite, cloud->sprite[i].scale);
    sfSprite_setTexture(cloud->sprite[i].sprite, cloud->sprite[i].texture,
    sfFalse);
    sfSprite_setTextureRect(cloud->sprite[i].sprite, cloud->sprite[i].rect);
}

void init_cloud2(layer_t *cloud)
{
    srand(time(NULL));
    for (int i = 0; i < 6; ++i) {
        int random = (rand() % 100);
        cloud->sprite[i].sprite = sfSprite_create();
        cloud->sprite[i].pos.x = (rand() % (150 - 50) + 50) * i * 8;
        cloud->sprite[i].pos.y = (rand() % (500 - 250) + 150);
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
        cloud->sprite[i].texture = sfTexture_createFromFile("ressources/sprite.png", NULL);
        sfSprite_setScale(cloud->sprite[i].sprite, cloud->sprite[i].scale);
        sfSprite_setTexture(cloud->sprite[i].sprite, cloud->sprite[i].texture, sfFalse);
        sfSprite_setTextureRect(cloud->sprite[i].sprite, cloud->sprite[i].rect);
    }
}
