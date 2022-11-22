/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** create_and_destroy_spell
*/

#include "dongeon.h"

void create_spell(spell_t **list, window_t *window, player_dong_t *player,
float speed)
{
    spell_t *element = malloc(sizeof(*element));

    init_sprite(&element->sprite, (sprite_info_t){player->sprite.pos.x,
    player->sprite.pos.y, 2, 0, 0, 16, 16, "assets/dongeon/fireball.png"},
    window);
    element->sprite.scale.x = speed > 0 ? 2 : -2;
    element->sprite.pos.x = speed > 0 ? player->sprite.pos.x + 50 :
    player->sprite.pos.x - 50;
    element->sprite.pos.y = player->sprite.pos.y + 23;
    sfSprite_setPosition(element->sprite.sprite, element->sprite.pos);
    sfSprite_setScale(element->sprite.sprite, element->sprite.scale);
    element->stats = (entity_stats_t){0, player->stats.damage, speed};
    if (*list != NULL) {
        element->id = (*list)->id + 1;
        element->next = *list;
    } else {
        element->id = 1;
        element->next = NULL;
    }
    *list = element;
}

void delete_spell_2(spell_t **begin, spell_t *prev, spell_t *next,
spell_t *curent)
{
    if (prev == NULL)
        *begin = next;
    else
        prev->next = next;
    free(curent);
}

void delete_used_spell(spell_t **begin, int id)
{
    spell_t *prev = NULL;
    spell_t *curent = *begin;
    spell_t *next;

    while (curent != NULL) {
        next = curent->next;
        if (curent->id == id) {
            delete_spell_2(begin, prev, next, curent);
            return;
        } else
            prev = curent;
        curent = next;
    }
}