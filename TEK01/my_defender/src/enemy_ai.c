/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** enemy_ia
*/

#include "../include/include.h"

void init_ai(window_t *window)
{
    window->game.ai.choosed = -1;
}

int ai_place_monster(window_t *window)
{
    soldier_info_t info;

    if (window->game.ai.choosed == -1) {
        window->game.ai.choosed = rand() % window->level.cards;
    }

    if (window->level.enemies.energy.value >=
    window->game.ig_ui.cards[window->game.ai.choosed].cost + rand() % 3) {
        info = window->game.ig_ui.cards[window->game.ai.choosed].info;
        info.walk_info.pos_x = 1500;
        info.walk_info.pos_y = rand() % (800 - 400) + 400;
        info.health_bar_info.path_text = "assets/game_ui/bar_4.png";
        add_soldier(info, &window->level.enemies.soldiers, &window->clock);
        window->level.enemies.energy.value -=
        window->game.ig_ui.cards[window->game.ai.choosed].cost;
        window->game.ai.choosed = -1;
    }
}