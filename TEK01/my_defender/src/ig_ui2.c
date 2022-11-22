/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** ig_ui2
*/

#include "../include/include.h"

void init_card(card_t *card, sprite_info_t info, int cost,
soldier_info_t soldier_info)
{
    card->sprite = init_sprite(info);
    card->cost = cost;
    card->is_moved = 0;
    card->info = soldier_info;
}

void init_ig_ui2(ig_ui_t *ig_ui)
{
    init_card(&ig_ui->cards[1], (sprite_info_t){410, 865, 0.9, 0.9, 0, 0, 0, 0,
    "assets/game_ui/icone_skeleton.png"}, 2,
    (soldier_info_t){SKELETON_HEALTH, SKELETON_DAMAGE, 1, 3.50,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 139, SKELETON_WALK} ,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 173, SKELETON_ATTACK},
    BLUE_HEALTH});
    init_card(&ig_ui->cards[2], (sprite_info_t){610, 865, 0.9, 0.9, 0, 0, 0, 0,
    "assets/game_ui/icone_cyclop.png"}, 3,
    (soldier_info_t){CYCLOP_HEALTH, CYCLOP_DAMAGE, 1, 3.50,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 158, CYCLOP_WALK} ,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 188, CYCLOP_ATTACK},
    BLUE_HEALTH});
}

void init_ig_ui3(ig_ui_t *ig_ui)
{
    init_card(&ig_ui->cards[3], (sprite_info_t){810, 865, 0.9, 0.9, 0, 0, 0, 0,
    "assets/game_ui/icone_elemental.png"}, 4,
    (soldier_info_t){ELEMENTAL_HEALTH, ELEMENTAL_DAMAGE, 1, 3.50,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 114, ELEMENTAL_FLY} ,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 236, ELEMENTAL_ATTACK},
    BLUE_HEALTH});
    init_card(&ig_ui->cards[4], (sprite_info_t){1010, 865, 0.9, 0.9, 0, 0, 0, 0,
    "assets/game_ui/icone_golem.png"}, 5,
    (soldier_info_t){GOLEM_HEALTH, GOLEM_DAMAGE, 1, 3.50,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 141, GOLEM_WALK} ,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 202, GOLEM_ATTACK},
    BLUE_HEALTH});
    init_card(&ig_ui->cards[5], (sprite_info_t){1210, 865, 0.9, 0.9, 0, 0, 0, 0,
    "assets/game_ui/icone_minotaur.png"}, 7,
    (soldier_info_t){MINOTAUR_HEALTH, MINOTAUR_DAMAGE, 1, 3.50,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 186, MINOTAUR_WALK} ,
    (sprite_info_t){0, 0, 0.7, 0.7, 0, 0, 150, 181, MINOTAUR_ATTACK},
    BLUE_HEALTH});
}

void init_ig_ui(ig_ui_t *ig_ui)
{
    ig_ui->card_support = init_sprite((sprite_info_t){50, 900, 0.9, 1, 0, 0, 0,
    0, "assets/game_ui/table_down.png"});
    ig_ui->play_level = init_sprite((sprite_info_t){1600, 850, 1, 1, 0, 0, 176,
    176, "assets/game_ui/button_start.png"});
    ig_ui->pause_level = init_sprite((sprite_info_t){1600, 850, 1, 1, 0, 0, 176,
    176, "assets/game_ui/button_pause.png"});
    init_card(&ig_ui->cards[0], (sprite_info_t){210, 865, 0.9, 0.9, 0, 0, 0, 0,
    "assets/game_ui/icone_goblin.png"}, 1,
    (soldier_info_t){GOBLIN_HEALTH, GOBLIN_DAMAGE, 1, 3.50,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 133, GOBLIN_WALK} ,
    (sprite_info_t){0, 0, 0.5, 0.5, 0, 0, 150, 134, GOBLIN_ATTACK},
    BLUE_HEALTH});
    init_ig_ui2(ig_ui);
    init_ig_ui3(ig_ui);
}