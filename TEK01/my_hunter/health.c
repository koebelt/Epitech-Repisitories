/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** health.c
*/

#include "include.h"

void init_health(sprite_t *health_bar)
{
    health_bar->sprite = sfSprite_create();
    health_bar->pos.x = 300;
    health_bar->pos.y = 70;
    health_bar->scale.x = 4;
    health_bar->scale.y = 4;
    health_bar->rect.top = 0;
    health_bar->rect.left = 0;
    health_bar->rect.width = 111;
    health_bar->rect.height = 8;
    health_bar->shooting = 0;
    health_bar->texture = sfTexture_createFromFile("ressources/health.png",
    NULL);
    health_bar->size_text = sfTexture_getSize(health_bar->texture);
    sfSprite_setTexture(health_bar->sprite, health_bar->texture, sfFalse);
}

void disp_health(game_obj_t *game, sfRenderWindow **window)
{
    game->health_bar.rect.top = 8 * (11 - game->health);
    sfSprite_setScale(game->health_bar.sprite, game->health_bar.scale);
    sfSprite_setPosition(game->health_bar.sprite, game->health_bar.pos);
    sfSprite_setTextureRect(game->health_bar.sprite, game->health_bar.rect);
    sfRenderWindow_drawSprite(*window, game->health_bar.sprite, NULL);
}
