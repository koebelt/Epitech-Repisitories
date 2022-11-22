/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** target_algorithm3
*/

#include "../include/include.h"

int is_building_at_range(soldiers_t *attacant, team_t *target)
{
    sfFloatRect attacant_box =
    sfSprite_getGlobalBounds(attacant->sprite.sprite);
    sfFloatRect hdv = sfSprite_getGlobalBounds(target->hdv.sprite.sprite);
    sfFloatRect tower_1 =
    sfSprite_getGlobalBounds(target->tower_1.sprite.sprite);
    sfFloatRect tower_2 =
    sfSprite_getGlobalBounds(target->tower_2.sprite.sprite);

    if ((sfFloatRect_intersects(&attacant_box, &hdv, NULL) &&
    target->hdv.health > 0) ||
    (sfFloatRect_intersects(&attacant_box, &tower_1, NULL) &&
    target->tower_1.health > 0) ||
    (sfFloatRect_intersects(&attacant_box, &tower_2, NULL) &&
    target->tower_2.health > 0))
        return (1);
    return (0);
}

int is_at_range(soldiers_t *attacant, team_t *target)
{
    sfFloatRect attacant_box =
    sfSprite_getGlobalBounds(attacant->sprite.sprite);
    soldiers_t *tmp_target = target->soldiers;
    sfFloatRect soldier_box;

    if (is_building_at_range(attacant, target))
        return (1);
    while (tmp_target != NULL) {
        soldier_box = sfSprite_getGlobalBounds(tmp_target->sprite.sprite);
        if (sfFloatRect_intersects(&attacant_box, &soldier_box, NULL))
            return (1);
        tmp_target = tmp_target->next;
    }
    return (0);
}

void move_to_closest(soldiers_t *attacant, sfVector2f closest)
{
    sfVector2f tmp = {closest.x - attacant->sprite.pos.x, closest.y -
    attacant->sprite.pos.y};

    for (int i = 0; tmp.x > 1 || tmp.x < -1; tmp.x = tmp.x / 1.1, tmp.y =
    tmp.y / 1.1);
    for (int i = 0; tmp.y > 1 || tmp.y < -1; tmp.x = tmp.x / 1.1, tmp.y =
    tmp.y / 1.1);
    attacant->sprite.pos.x += tmp.x;
    attacant->sprite.pos.y += tmp.y;
    if (tmp.x < 0 && attacant->sprite.scale.x > 0) {
        attacant->sprite.scale.x *= -1;
        attacant->attack.scale.x *= -1;
    } else if (tmp.x > 0 && attacant->sprite.scale.x < 0) {
        attacant->sprite.scale.x *= -1;
        attacant->attack.scale.x *= -1;
    }

    sfSprite_setScale(attacant->sprite.sprite, attacant->sprite.scale);
    sfSprite_setScale(attacant->attack.sprite, attacant->attack.scale);
}