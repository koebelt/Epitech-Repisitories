/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** init_inventory
*/

#include "inventory.h"

void init_inventory_forth(window_t *window)
{
    init_text(&window->inventory.points, "points :",
    (sfVector2f){0.4, 0.4}, 1);
    init_text(&window->inventory.points_nbr, "1", (sfVector2f){0.6, 0.6}, 1);
    window->inventory.armor_info = 1;
    window->inventory.damage_info = 1;
    window->inventory.attack_speed_info = 1;
    window->inventory.speed_info = 1;
}

void init_inventory_third(window_t *window)
{
    init_text(&window->inventory.stat_speed_nbr, "armor",
    (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.stat_armor_nbr, "armor",
    (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.exp, "exp :", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.exp_nbr, "1", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.slash, "/", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.exp_next_lvl, "100",
    (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.level, "level :", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.level_nbr, "1", (sfVector2f){0.6, 0.6}, 1);
    window->inventory.exp_int = 0;
    window->inventory.exp_cap_int = 10;
    window->inventory.level_int = 1;
    window->inventory.points_int = 0;
    window->inventory.damage_points = 0;
    window->inventory.attack_speed_points = 0;
    window->inventory.speed_points = 0;
    window->inventory.armor_points = 0;
    init_inventory_forth(window);
}

void init_inventory_second(window_t *window)
{
    init_text(&window->inventory.speed_nbr,
    "armor", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.attack_speed_nbr,
    "armor", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.armor_nbr,
    "armor", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.stat_damage, "damage",
    (sfVector2f){0.5, 0.5}, 1);
    init_text(&window->inventory.stat_attack_speed,
    "attack speed", (sfVector2f){0.4, 0.4}, 1);
    init_text(&window->inventory.stat_speed, "speed",
    (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.stat_armor, "armor",
    (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.stat_damage_nbr, "armor",
    (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.stat_attack_speed_nbr, "armor",
    (sfVector2f){0.6, 0.6}, 1);
    init_inventory_third(window);
}

void init_inventory(window_t *window)
{
    window->inventory.open = 0;
    window->inventory.removing = 0;
    init_sprite(&window->inventory.inventory,
    (sprite_info_t){0, 0, 1.2, 0, 0, 0, 0, INVENTORY_TEXT}, window);
    init_sprite(&window->inventory.bin,
    (sprite_info_t){0, 0, 0.1, 0, 0, 0, 0, BIN}, window);
    init_sprite(&window->inventory.bin_temp,
    (sprite_info_t){0, 0, 0.1, 0, 0, 0, 0, BIN}, window);
    init_sprite(&window->inventory.select,
    (sprite_info_t){0, 0, 0.23, 0, 0, 0, 0, SELECT}, window);
    init_sprite(&window->inventory.board,
    (sprite_info_t){0, 0, 1, 0, 0, 0, 0, BOARD}, window);
    init_text(&window->inventory.damage, "damage", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.attack_speed,
    "attack speed", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.speed, "speed", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.armor, "armor", (sfVector2f){0.6, 0.6}, 1);
    init_text(&window->inventory.damage_nbr,
    "armor", (sfVector2f){0.6, 0.6}, 1);
    init_inventory_second(window);
}