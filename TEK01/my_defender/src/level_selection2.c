/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** level_selection2
*/

#include "../include/include.h"

void init_level(level_t *level, level_info_t info, sfClock **clock)
{
    level->level = info.level;
    level->icon = init_sprite(info.icon);
    init_building(&level->enemies.hdv, info.hdv, clock);
    init_building(&level->enemies.tower_1, info.tower_1, clock);
    init_building(&level->enemies.tower_2, info.tower_2, clock);
    level->cards = info.cards;
    level->background = init_sprite(info.background);
    level->enemies.soldiers = NULL;
    level->gold = info.gold;
}

void init_levels2(level_select_t *levels, sfClock **clock)
{
    init_level(&levels->levels[0],
    (level_info_t){ 1, 3,
    (sprite_info_t){550, 360, 1, 1, 0, 0, 175, 175,
    "assets/button_level_sheet.png"},
    (sprite_info_t){0, -160, 0.85, 0.85, 0, 0, 0, 0, MAP_1},
    (building_info_t){HDV_HEALTH, 0, 0, 0,
    (sprite_info_t){ENEMY_POS_HDV_X, ENEMY_POS_HDV_Y, 1, 1, 0, 0, 110, 120, HDV}
    , 1, RED_HEALTH},
    (building_info_t){ARCHERS_HEALTH, ARCHERS_COOLDOWN, ARCHERS_DAMAGE,
    ARCHERS_RANGE, (sprite_info_t){ENEMY_POS_TOWER_1_X, ENEMY_POS_TOWER_1_Y, 1,
    1, 0, 0, 112, 80, ARCHERS}, 1, RED_HEALTH, ARROW_PROJ},
    (building_info_t){ARCHERS_HEALTH, ARCHERS_COOLDOWN, ARCHERS_DAMAGE,
    ARCHERS_RANGE, (sprite_info_t){ENEMY_POS_TOWER_2_X, ENEMY_POS_TOWER_2_Y, 1,
    1, 0, 0, 112, 80, ARCHERS}, 2, RED_HEALTH, ARROW_PROJ}, 5
    }, clock);
}

void init_levels3(level_select_t *levels, sfClock **clock)
{
    init_level(&levels->levels[1],
    (level_info_t){ 2, 4,
    (sprite_info_t){890, 360, 1, 1, 0, 175, 175, 175,
    "assets/button_level_sheet.png"},
    (sprite_info_t){0, -160, 0.85, 0.85, 0, 0, 0, 0, MAP_1},
    (building_info_t){HDV_HEALTH, 0, 0, 0, (sprite_info_t){ENEMY_POS_HDV_X,
    ENEMY_POS_HDV_Y, 1, 1, 0, 0, 110, 120, HDV}, 3, RED_HEALTH},
    (building_info_t){ARCHERS_HEALTH, ARCHERS_COOLDOWN, ARCHERS_DAMAGE,
    ARCHERS_RANGE, (sprite_info_t){ENEMY_POS_TOWER_1_X, ENEMY_POS_TOWER_1_Y, 1,
    1, 0, 0, 112, 80, ARCHERS}, 3, RED_HEALTH, ARROW_PROJ},
    (building_info_t){WIZARD_HEALTH, WIZARD_COOLDOWN, WIZARD_DAMAGE,
    WIZARD_RANGE, (sprite_info_t){ENEMY_POS_TOWER_2_X, ENEMY_POS_TOWER_2_Y, 1,
    1, 0, 0, 120, 100, WIZARD}, 2, RED_HEALTH, WIZARD_PROJ}, 15
    }, clock);
}

void init_levels4(level_select_t *levels, sfClock **clock)
{
    init_level(&levels->levels[2],
    (level_info_t){ 3, 5,
    (sprite_info_t){1240, 360, 1, 1, 0, 350, 175, 175,
    "assets/button_level_sheet.png"},
    (sprite_info_t){0, -160, 0.85, 0.85, 0, 0, 0, 0, MAP_2},
    (building_info_t){HDV_HEALTH, 0, 0, 0, (sprite_info_t){ENEMY_POS_HDV_X,
    ENEMY_POS_HDV_Y, 1, 1, 0, 0, 110, 120, HDV}, 5, RED_HEALTH},
    (building_info_t){INFERNO_HEALTH, INFERNO_COOLDOWN, INFERNO_DAMAGE,
    INFERNO_RANGE, (sprite_info_t){ENEMY_POS_TOWER_1_X, ENEMY_POS_TOWER_1_Y, 1,
    1, 0, 0, 140, 100, INFERNO}, 1, RED_HEALTH, INFERNO_PROJ},
    (building_info_t){TESLA_HEALTH, TESLA_COOLDOWN, TESLA_DAMAGE, TESLA_RANGE,
    (sprite_info_t){ENEMY_POS_TOWER_2_X, ENEMY_POS_TOWER_2_Y, 1, 1, 0, 0, 120,
    75, TESLA}, 3, RED_HEALTH, TESLA_PROJ}, 40
    }, clock);
}

void init_levels5(level_select_t *levels, sfClock **clock)
{
    init_level(&levels->levels[3],
    (level_info_t){ 4, 5,
    (sprite_info_t){550, 570, 1, 1, 0, 525, 175, 175,
    "assets/button_level_sheet.png"},
    (sprite_info_t){0, -160, 0.85, 0.85, 0, 0, 0, 0, MAP_5},
    (building_info_t){HDV_HEALTH, 0, 0, 0, (sprite_info_t){ENEMY_POS_HDV_X,
    ENEMY_POS_HDV_Y, 1, 1, 0, 0, 110, 120, HDV}, 6, RED_HEALTH},
    (building_info_t){INFERNO_HEALTH, INFERNO_COOLDOWN, INFERNO_DAMAGE,
    INFERNO_RANGE, (sprite_info_t){ENEMY_POS_TOWER_1_X, ENEMY_POS_TOWER_1_Y, 1,
    1, 0, 0, 140, 100, INFERNO}, 2, RED_HEALTH, INFERNO_PROJ},
    (building_info_t){TESLA_HEALTH, TESLA_COOLDOWN, TESLA_DAMAGE, TESLA_RANGE,
    (sprite_info_t){ENEMY_POS_TOWER_2_X, ENEMY_POS_TOWER_2_Y, 1, 1, 0, 0, 120,
    75, TESLA}, 4, RED_HEALTH, TESLA_PROJ}, 70
    }, clock);
}