/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** init_menu.c
*/

#include "include.h"

void init_menu_sprites(menu_obj_t *menu)
{
    init_hunter(&menu->hunter);
    menu->hunter.pos.x = 10;
    menu->hunter.pos.y = 500;
    menu->hunter.scale.x = 10;
    menu->hunter.scale.y = 10;
    init_hand(&menu->hand);
    menu->hand.pos.x = 10;
    menu->hand.pos.y = 590;
    menu->hand.scale.x = 10;
    menu->hand.scale.y = 10;
    init_crosshair(&menu->crosshair);
    init_start(&menu->start);
    init_choose(&menu->choose);
    init_reset(&menu->restart);
}

void init_menu(menu_obj_t *menu)
{
    menu->music = sfMusic_createFromFile("ressources/menu music.wav");
    sfMusic_setLoop(menu->music, sfTrue);
    init_menu_sprites(menu);
    menu->font = sfFont_createFromFile("ressources/BitPap.ttf");
    menu->text = sfText_create();
    menu->text_pos.x = 800;
    menu->text_pos.y = 650;
    sfText_setFont(menu->text, menu->font);
    sfText_setString(menu->text, "HIGH SCORE:");
    sfText_setCharacterSize(menu->text, 50);
    sfText_setColor(menu->text, sfWhite);
    sfText_setPosition(menu->text, menu->text_pos);
    sfSprite_setScale(menu->hand.sprite, menu->hand.scale);
    sfSprite_setScale(menu->hand.sprite, menu->hand.scale);

    menu->hand_clock = sfClock_create();
    menu->anim_clock = sfClock_create();
}
