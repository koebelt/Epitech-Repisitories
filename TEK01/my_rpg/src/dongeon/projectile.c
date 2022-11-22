/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** projectile
*/

#include "dongeon.h"

int damage_enemies_at_range(spell_t *spell, monster_t *monster,
window_t *window)
{
    sfFloatRect box = sfSprite_getGlobalBounds(spell->sprite.sprite);
    sfFloatRect monster_box;
    monster_t *tmp = monster;

    while (tmp != NULL) {
        monster_box = sfSprite_getGlobalBounds(tmp->sprite.sprite);
        if (sfFloatRect_intersects(&monster_box, &box, NULL)) {
            tmp->stats.health -= spell->stats.damage + (100 *
            (window->inventory.damage_info / 10));
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

int is_wall_collision_projectile_mid(sfFloatRect rect, float scale, int i,
sfImage *img)
{
    float rect_left = rect.left / scale;
    float rect_width = rect.width / scale;

    for (float j = rect_left; j < (rect_left + rect_width); ++j) {
        if (sfColor_toInteger(sfImage_getPixel(img, j, i)) ==
        sfColor_toInteger(sfRed)) {
            return (0);
        }
    }
    return (1);
}

int is_wall_collision_projectile(sfFloatRect rect, sfImage *img, float scale)
{
    float rect_top = rect.top / scale;
    float rect_height = rect.height / scale;

    for (float i = rect_top; i < (rect_top + rect_height); i++)
        if (is_wall_collision_projectile_mid(rect, scale, i, img) == 0)
            return (0);
    return (1);
}

void display_projectile(window_t *window)
{
    spell_t *tmp = window->dongeon.player.spell;

    while (tmp != NULL) {
        if (move_projectile(tmp, &window->dongeon.player, window))
            animate_sprite(&tmp->sprite, window, 15);
        tmp = tmp->next;
    }
}