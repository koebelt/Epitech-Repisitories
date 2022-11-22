/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** level_selection3
*/

#include "../include/include.h"

void init_levels6(level_select_t *levels, sfClock **clock)
{
    init_level(&levels->levels[4],
    (level_info_t){ 5, 6,
    (sprite_info_t){890, 570, 1, 1, 0, 700, 175, 175,
    "assets/button_level_sheet.png"},
    (sprite_info_t){0, -160, 0.85, 0.85, 0, 0, 0, 0, MAP_5},
    (building_info_t){HDV_HEALTH, 0, 0, 0, (sprite_info_t){ENEMY_POS_HDV_X,
    ENEMY_POS_HDV_Y, 1, 1, 0, 0, 110, 120, HDV}, 6, RED_HEALTH},
    (building_info_t){WIZARD_HEALTH, WIZARD_COOLDOWN, WIZARD_DAMAGE,
    WIZARD_RANGE, (sprite_info_t){ENEMY_POS_TOWER_1_X, ENEMY_POS_TOWER_1_Y, 1,
    1, 0, 0, 120, 100, WIZARD}, 5, RED_HEALTH, WIZARD_PROJ},
    (building_info_t){TESLA_HEALTH, TESLA_COOLDOWN, TESLA_DAMAGE, TESLA_RANGE,
    (sprite_info_t){ENEMY_POS_TOWER_2_X, ENEMY_POS_TOWER_2_Y, 1, 1, 0, 0, 120,
    75, TESLA}, 5, RED_HEALTH, TESLA_PROJ}, 100
    }, clock);
}

void init_levels7(level_select_t *levels, sfClock **clock)
{
    init_level(&levels->levels[5],
    (level_info_t){ 6, 6,
    (sprite_info_t){1240, 570, 1, 1, 0, 875, 175, 175,
    "assets/button_level_sheet.png"},
    (sprite_info_t){0, -160, 0.85, 0.85, 0, 0, 0, 0, MAP_5},
    (building_info_t){HDV_HEALTH, 0, 0, 0, (sprite_info_t){ENEMY_POS_HDV_X,
    ENEMY_POS_HDV_Y, 1, 1, 0, 0, 110, 120, HDV}, 7, RED_HEALTH},
    (building_info_t){WIZARD_HEALTH, WIZARD_COOLDOWN, WIZARD_DAMAGE,
    WIZARD_RANGE, (sprite_info_t){ENEMY_POS_TOWER_1_X, ENEMY_POS_TOWER_1_Y, 1,
    1, 0, 0, 140, 100, WIZARD}, 6, RED_HEALTH, WIZARD_PROJ},
    (building_info_t){EAGLES_HEALTH, EAGLES_COOLDOWN, EAGLES_DAMAGE,
    EAGLES_RANGE, (sprite_info_t){ENEMY_POS_TOWER_2_X, ENEMY_POS_TOWER_2_Y, 1,
    1, 0, 0, 170, 140, EAGLES}, 1, RED_HEALTH, EAGLE_PROJ}, 200
    }, clock);
}

void init_levels(level_select_t *levels, sfClock **clock)
{
    levels->background = init_sprite((sprite_info_t){0, 0, 1, 1, 0, 0, 1080,
    1920, BG});
    levels->menu = init_sprite((sprite_info_t){500, 200, 1, 1, 0, 0, 0, 0,
    "assets/menu/table_levels.png"});
    levels->exit = init_sprite((sprite_info_t){1380, 160, 1, 1, 0, 0, 0, 0,
    "assets/menu/setting_cl.png"});
    init_levels2(levels, clock);
    init_levels3(levels, clock);
    init_levels4(levels, clock);
    init_levels5(levels, clock);
    init_levels6(levels, clock);
    init_levels7(levels, clock);
}

int level_picked(sfMouseButtonEvent mouse, level_t *level, window_t *window)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(level->icon.sprite);

    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        window->level = *level;
        init_game(&window->game, &window->clock, window);
        window->index = 2;
        return (1);
    }
    return (0);
}