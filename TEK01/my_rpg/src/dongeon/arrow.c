/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** projectile
*/

#include "dongeon.h"

void create_arrow(spell_t **list, window_t *window, monster_t *monster,
float speed)
{
    spell_t *element;

    element = malloc(sizeof(*element));
    init_sprite(&element->sprite, (sprite_info_t){monster->sprite.pos.x,
    monster->sprite.pos.y, 2, 0, 0, 0, 0, "assets/dongeon/arrow.png"}, window);
    element->sprite.scale.x = speed > 0 ? 2 : -2;
    element->sprite.pos.x = speed > 0 ? monster->sprite.pos.x + 50 :
    monster->sprite.pos.x - 50;
    element->sprite.pos.y = monster->sprite.pos.y + 30;
    sfSprite_setPosition(element->sprite.sprite, element->sprite.pos);
    sfSprite_setScale(element->sprite.sprite, element->sprite.scale);
    element->stats = (entity_stats_t){0, monster->stats.damage, speed};
    if (*list != NULL)
        element->id = (*list)->id + 1;
    else
        element->id = 1;
    element->next = *list;
    *list = element;
}

int damage_player_at_range(spell_t *spell, player_dong_t *player,
window_t *window)
{
    sfFloatRect box = sfSprite_getGlobalBounds(spell->sprite.sprite);
    sfFloatRect player_box = sfSprite_getGlobalBounds(player->sprite.sprite);

    if (sfFloatRect_intersects(&player_box, &box, NULL)) {
        player->stats.health -= spell->stats.damage -
        window->inventory.armor_info;
        return (1);
    }
    return (0);
}

void display_arrow(window_t *window, spell_t *spell, monster_t *monster)
{
    spell_t *tmp = spell;

    while (tmp != NULL) {
        if (move_arrow(tmp, monster, &window->dongeon.player, window))
            sfRenderWindow_drawSprite(window->window, tmp->sprite.sprite,
            NULL);
        tmp = tmp->next;
    }
}