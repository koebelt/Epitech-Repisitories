/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** get_level_and_stats
*/

#include "inventory.h"

void add_stats(window_t *window, item_t *temp)
{
    while (temp != NULL) {
        if (temp->equiped == 1) {
            window->inventory.damage_info += temp->stats.damage;
            window->inventory.attack_speed_info += temp->stats.attack_speed;
            window->inventory.speed_info += temp->stats.speed;
            window->inventory.armor_info += temp->stats.armor;
        }
        temp = temp->next;
    }
}

void get_stats(window_t *window)
{
    item_t *temp = window->item;

    window->inventory.damage_info = 1 + window->inventory.damage_points;
    window->inventory.attack_speed_info =
    1 + window->inventory.attack_speed_points;
    window->inventory.speed_info = 1 + window->inventory.speed_points;
    window->inventory.armor_info = 1 + window->inventory.armor_points;
    add_stats(window, temp);
    sfText_setString(window->inventory.stat_damage_nbr.text,
    int_to_str(window->inventory.damage_info));
    sfText_setString(window->inventory.stat_attack_speed_nbr.text,
    int_to_str(window->inventory.attack_speed_info));
    sfText_setString(window->inventory.stat_speed_nbr.text,
    int_to_str(window->inventory.speed_info));
    sfText_setString(window->inventory.stat_armor_nbr.text,
    int_to_str(window->inventory.armor_info));
}

void get_level(window_t * window)
{
    if (window->inventory.exp_int >= window->inventory.exp_cap_int) {
        window->inventory.exp_int -= window->inventory.exp_cap_int;
        window->inventory.exp_cap_int *= 1.5;
        window->inventory.level_int += 1;
        window->inventory.points_int += 1;
    }
    sfText_setString(window->inventory.exp_nbr.text,
    int_to_str(window->inventory.exp_int));
    sfText_setString(window->inventory.exp_next_lvl.text,
    int_to_str(window->inventory.exp_cap_int));
    sfText_setString(window->inventory.level_nbr.text,
    int_to_str(window->inventory.level_int));
}