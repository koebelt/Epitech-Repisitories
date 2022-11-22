/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** target_algorithm
*/

#include "../include/include.h"

int is_closest(sfVector2f pos, sfVector2f v1, sfVector2f v2)
{
    float range_1 = sqrtf(pow(pos.x - v1.x, 2) + pow(pos.y - v1.y, 2));
    float range_2 = sqrtf(pow(pos.x - v2.x, 2) + pow(pos.y - v2.y, 2));

    if (range_1 > range_2)
        return (0);
    else
        return (1);
}

sfVector2f change_closest(sfVector2f pos, sfVector2f prev_closest,
sfVector2f to_compare, int exists)
{
    if (exists <= 0)
        return (prev_closest);
    else if (is_closest(pos, prev_closest, to_compare))
        return (prev_closest);
    else
        return (to_compare);
}

void soldier_target(soldiers_t *attacant, team_t *target, sfClock **clock)
{
    soldiers_t *tmp_attacant = attacant;
    soldiers_t *tmp_target  = target->soldiers;
    sfVector2f closest = {4000, 4000};

    while (tmp_attacant != NULL) {
        closest = change_closest(tmp_attacant->sprite.pos, closest,
        target->hdv.sprite.pos, target->hdv.health);
        closest = change_closest(tmp_attacant->sprite.pos, closest,
        target->tower_1.sprite.pos, target->tower_1.health);
        closest = change_closest(tmp_attacant->sprite.pos, closest,
        target->tower_2.sprite.pos, target->tower_2.health);
        while (tmp_target != NULL) {
            closest = change_closest(tmp_attacant->sprite.pos, closest,
            tmp_target->sprite.pos, 1);
            tmp_target = tmp_target->next;
        }
        soldier_action(tmp_attacant, target, closest, clock);
        tmp_attacant = tmp_attacant->next;
    }
}