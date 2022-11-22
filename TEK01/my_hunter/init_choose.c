/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** init_choose.c
*/

#include "include.h"

void init_bottles(choose_bottles_t *bottles)
{
    init_wwhine(&bottles->bottle0);
    init_rwhine(&bottles->bottle1);
    init_wiskey(&bottles->bottle2);
    init_bwhine(&bottles->bottle3);
    init_gwhine(&bottles->bottle4);
    init_champagne(&bottles->bottle5);
}

void init_choose_sprites(choose_obj_t *choose)
{
    init_hunter(&choose->hunter);
    choose->hunter.pos.x = 500;
    choose->hunter.pos.y = 500;
    choose->hunter.scale.x = 10;
    choose->hunter.scale.y = 10;
    init_hand(&choose->hand);
    choose->hand.pos.x = 500;
    choose->hand.pos.y = 590;
    choose->hand.scale.x = 10;
    choose->hand.scale.y = 10;
    init_crosshair(&choose->crosshair);
}

void init_choose_menu(choose_obj_t *choose)
{
    init_choose_sprites(choose);
    choose->font = sfFont_createFromFile("ressources/BitPap.ttf");
    choose->text = sfText_create();
    choose->text_pos.x = 800;
    choose->text_pos.y = 650;
    sfText_setFont(choose->text, choose->font);
    sfText_setString(choose->text, "HIGH SCORE:");
    sfText_setCharacterSize(choose->text, 50);
    sfText_setColor(choose->text, sfWhite);
    sfText_setPosition(choose->text, choose->text_pos);
    sfSprite_setScale(choose->hand.sprite, choose->hand.scale);
    sfSprite_setScale(choose->hand.sprite, choose->hand.scale);
    init_bottles(&choose->bottles);
    choose->bottle_index = 1;
    choose->hand_clock = sfClock_create();
    choose->anim_clock = sfClock_create();
}
