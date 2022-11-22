/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** display_monsters
*/

#include "dongeon.h"

void display_monsters_two(window_t *window, monster_t *tmp)
{
    switch (tmp->type) {
        case 0:
            animate_archer(tmp, window);
            break;
        case 1:
            animate_spear(tmp, window);
            break;
        case 2:
            animate_skull(tmp, window);
            break;
    }
}

void display_monsters(window_t *window)
{
    monster_t *tmp = window->dongeon.player.current->monsters;
    sfFloatRect box = sfSprite_getGlobalBounds(
    window->dongeon.player.sprite.sprite);
    float prev_left = 0;

    while (tmp != NULL) {
        prev_left = tmp->sprite.rect.left;
        display_monsters_two(window, tmp);
        if (!sfFloatRect_intersects(&box, &tmp->attack_range, NULL) &&
        !tmp->attacking)
            move_monster(&window->dongeon.player, tmp);
        else
            monster_attack(tmp, &window->dongeon.player, window, prev_left);
        tmp = tmp->next;
    }
    delete_used_monster(&window->dongeon.player.current->monsters, window);
}