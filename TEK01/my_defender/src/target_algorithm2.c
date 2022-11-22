/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** target_algorithm2
*/

#include "../include/include.h"

int inflict_damage_on_buildings(soldiers_t *attacant, team_t *target,
sfFloatRect attacant_box)
{
    sfFloatRect hdv = sfSprite_getGlobalBounds(target->hdv.sprite.sprite);
    sfFloatRect tower_1 =
    sfSprite_getGlobalBounds(target->tower_1.sprite.sprite);
    sfFloatRect tower_2 =
    sfSprite_getGlobalBounds(target->tower_2.sprite.sprite);

    if (sfFloatRect_intersects(&attacant_box, &hdv, NULL) &&
    target->hdv.health > 0) {
        target->hdv.health -= attacant->damages;
        return (1);
    } if (sfFloatRect_intersects(&attacant_box, &tower_1, NULL) &&
    target->tower_1.health > 0) {
        target->tower_1.health -= attacant->damages;
        return (1);
    } if (sfFloatRect_intersects(&attacant_box, &tower_2, NULL) &&
    target->tower_2.health > 0) {
        target->tower_2.health -= attacant->damages;
        return (1);
    }
    return (0);
}

int inflict_damage(soldiers_t *attacant, team_t *target)
{
    sfFloatRect attacant_box =
    sfSprite_getGlobalBounds(attacant->sprite.sprite);
    soldiers_t *tmp_target = target->soldiers;
    sfFloatRect soldier_box;

    if (inflict_damage_on_buildings(attacant, target, attacant_box))
        return (0);
    while (tmp_target != NULL) {
        soldier_box = sfSprite_getGlobalBounds(tmp_target->sprite.sprite);
        if (sfFloatRect_intersects(&attacant_box, &soldier_box, NULL)) {
            tmp_target->health -= attacant->damages;
            return (0);
        }
        tmp_target = tmp_target->next;
    }
    return (0);
}

void attack(soldiers_t *attacant, team_t *target, sfClock **clock)
{
    sfTime time = sfClock_getElapsedTime(*clock);
    float seconds = time.microseconds / 1000000.0 - attacant->t_cooldown;

    attacant->is_attacking = 1;
    if (seconds >= attacant->cooldown) {
        inflict_damage(attacant, target);
        attacant->t_cooldown = sfClock_getElapsedTime(*clock).microseconds /
        1000000.0;
    }
}

void soldier_action(soldiers_t *attacant, team_t *target, sfVector2f closest,
sfClock **clock)
{
    if (is_at_range(attacant, target)) {
        attack(attacant, target, clock);
    } else {
        attacant->is_attacking = 0;
        move_to_closest(attacant, closest);
    }
}