/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** soldier
*/

#include "../include/include.h"

void add_soldier(soldier_info_t soldier_info, soldiers_t **list,
sfClock **clock)
{
    soldiers_t *element;

    element = malloc(sizeof(*element));
    element->sprite = init_sprite(soldier_info.walk_info);
    element->attack = init_sprite(soldier_info.attack_info);
    element->health = soldier_info.health;
    element->max_health = soldier_info.health;
    element->health_bar = init_sprite(soldier_info.health_bar_info);
    element->damages = soldier_info.damages;
    element->team = soldier_info.team;
    element->cooldown = soldier_info.cooldown;
    element->t_cooldown = sfClock_getElapsedTime(*clock).microseconds /
    1000000.0 - 50;
    element->t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
    element->id = (int)element->t_0;
    element->is_attacking = 0;
    element->next = *list;
    *list = element;
}

void print_soldiers(soldiers_t *list, sfRenderWindow *window, sfClock **clock)
{
    soldiers_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        if (tmp->is_attacking == 0) {
            sfSprite_setPosition(tmp->sprite.sprite, tmp->sprite.pos);
            animate_soldier(tmp, clock, window, &tmp->sprite);
        } else if (tmp->is_attacking == 1) {
            sfSprite_setPosition(tmp->attack.sprite, tmp->sprite.pos);
            animate_soldier(tmp, clock, window, &tmp->attack);
        }
        sfFloatRect rect = sfSprite_getGlobalBounds(tmp->sprite.sprite);
        sfSprite_setPosition(tmp->health_bar.sprite, (sfVector2f){rect.left,
        rect.top - 10});
        animate_health_bar(tmp, window);
        tmp = tmp->next;
    }
}

void delete2(soldiers_t **begin, soldiers_t *prev, soldiers_t *next,
soldiers_t *curent)
{
    if (prev == NULL)
        *begin = next;
    else
        prev->next = next;
    free(curent);
}

void delete_dead_soldiers(soldiers_t **begin)
{
    soldiers_t *prev = NULL;
    soldiers_t *curent = *begin;
    soldiers_t *next;

    while (curent != NULL) {
        next = curent->next;
        if (curent->health <= 0)
            delete2(begin, prev, next, curent);
        else
            prev = curent;
        curent = next;
    }
}