/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** choose_tower2
*/

#include "../include/include.h"

void tesla_placement(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p)
{
    sfFloatRect tesla_box = sfSprite_getGlobalBounds(pa->tesla.sprite);

    if (sfFloatRect_contains(&tesla_box, m.x, m.y) && w->game.top != 5 &&
    w->game.bot != 5 && w->player.tesla_lvl > 0) {
        init_building((p ? &w->game.allies.tower_1 : &w->game.allies.tower_2),
        (building_info_t){TESLA_HEALTH, TESLA_COOLDOWN, TESLA_DAMAGE,
        TESLA_RANGE, (sprite_info_t){(p ? ALLY_POS_TOWER_1_X :
        ALLY_POS_TOWER_2_X), (p ? ALLY_POS_TOWER_1_Y : ALLY_POS_TOWER_2_Y), 1,
        1, 0, 0, 120, 75, TESLA}, w->player.tesla_lvl, BLUE_HEALTH,
        TESLA_PROJ}, &w->clock);
    if (p)
            w->game.top = 5;
        else
            w->game.bot = 5;
    }
}

void eagle_placement(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p)
{
    sfFloatRect eagle_box = sfSprite_getGlobalBounds(pa->eagle.sprite);

    if (sfFloatRect_contains(&eagle_box, m.x, m.y) && w->game.top != 4 &&
    w->game.bot != 4 && w->player.eagle_lvl > 0) {
        init_building((p ? &w->game.allies.tower_1 : &w->game.allies.tower_2),
        (building_info_t){EAGLES_HEALTH, EAGLES_COOLDOWN, EAGLES_DAMAGE,
        EAGLES_RANGE, (sprite_info_t){(p ? ALLY_POS_TOWER_1_X :
        ALLY_POS_TOWER_2_X), (p ? ALLY_POS_TOWER_1_Y : ALLY_POS_TOWER_2_Y),
        1, 1, 0, 0, 170, 140, EAGLES}, w->player.eagle_lvl, BLUE_HEALTH,
        EAGLE_PROJ}, &w->clock);
    if (p)
            w->game.top = 4;
        else
            w->game.bot = 4;
    }
}

void inferno_placement(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p)
{
    sfFloatRect inferno_box = sfSprite_getGlobalBounds(pa->inferno.sprite);

    if (sfFloatRect_contains(&inferno_box, m.x, m.y) && w->game.top != 3 &&
    w->game.bot != 3 && w->player.inferno_lvl > 0) {
        init_building((p ? &w->game.allies.tower_1 : &w->game.allies.tower_2),
        (building_info_t){INFERNO_HEALTH, INFERNO_COOLDOWN, INFERNO_DAMAGE,
        INFERNO_RANGE, (sprite_info_t){(p ? ALLY_POS_TOWER_1_X :
        ALLY_POS_TOWER_2_X), (p ? ALLY_POS_TOWER_1_Y : ALLY_POS_TOWER_2_Y), 1,
        1, 0, 0, 140, 100, INFERNO}, w->player.inferno_lvl, BLUE_HEALTH,
        INFERNO_PROJ}, &w->clock);
    if (p)
            w->game.top = 3;
        else
            w->game.bot = 3;
    }
}

void wizard_placement(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p)
{
    sfFloatRect wizard_box = sfSprite_getGlobalBounds(pa->wizard.sprite);

    if (sfFloatRect_contains(&wizard_box, m.x, m.y) && w->game.top != 2 &&
    w->game.bot != 2) {
        init_building((p ? &w->game.allies.tower_1 : &w->game.allies.tower_2),
        (building_info_t){WIZARD_HEALTH, WIZARD_COOLDOWN, WIZARD_DAMAGE,
        WIZARD_RANGE, (sprite_info_t){(p ? ALLY_POS_TOWER_1_X :
        ALLY_POS_TOWER_2_X), (p ? ALLY_POS_TOWER_1_Y : ALLY_POS_TOWER_2_Y), 1,
        1, 0, 0, 120, 100, WIZARD}, w->player.wizard_lvl, BLUE_HEALTH,
        WIZARD_PROJ}, &w->clock);
    if (p)
            w->game.top = 2;
        else
            w->game.bot = 2;
    }
}

void archer_placement(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p)
{
    sfFloatRect archer_box = sfSprite_getGlobalBounds(pa->archer.sprite);

    if (sfFloatRect_contains(&archer_box, m.x, m.y) && w->game.top != 1 &&
    w->game.bot != 1) {
        init_building((p ? &w->game.allies.tower_1 : &w->game.allies.tower_2),
        (building_info_t){ARCHERS_HEALTH, ARCHERS_COOLDOWN, ARCHERS_DAMAGE,
        ARCHERS_RANGE, (sprite_info_t){(p ? ALLY_POS_TOWER_1_X :
        ALLY_POS_TOWER_2_X), (p ? ALLY_POS_TOWER_1_Y : ALLY_POS_TOWER_2_Y), 1,
        1, 0, 0, 112, 80, ARCHERS}, w->player.archer_lvl, BLUE_HEALTH,
        ARROW_PROJ}, &w->clock);
        if (p)
            w->game.top = 1;
        else
            w->game.bot = 1;
    }
}