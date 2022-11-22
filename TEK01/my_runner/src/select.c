/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** select.c
*/

#include "include.h"

void init_left(button_t *left)
{
    left->sprite.sprite = sfSprite_create();
    left->sprite.pos.x = 625;
    left->sprite.pos.y = 450;
    left->sprite.scale.x = 4;
    left->sprite.scale.y = 4;
    left->sprite.texture = sfTexture_createFromFile("ressources/left.png",
    NULL);
    sfSprite_setPosition(left->sprite.sprite, left->sprite.pos);
    sfSprite_setScale(left->sprite.sprite, left->sprite.scale);
    sfSprite_setTexture(left->sprite.sprite, left->sprite.texture, sfFalse);
}

void init_right(button_t *right)
{
    right->sprite.sprite = sfSprite_create();
    right->sprite.pos.x = 875;
    right->sprite.pos.y = 450;
    right->sprite.scale.x = 4;
    right->sprite.scale.y = 4;
    right->sprite.texture = sfTexture_createFromFile("ressources/right.png",
    NULL);
    sfSprite_setPosition(right->sprite.sprite, right->sprite.pos);
    sfSprite_setScale(right->sprite.sprite, right->sprite.scale);
    sfSprite_setTexture(right->sprite.sprite, right->sprite.texture, sfFalse);
}

void init_map_txt(text_t *map_txt, text_t *map_percentage,int *map_index)
{
    *map_index = 1;
    map_txt->font = sfFont_createFromFile("ressources/BitPap.ttf");
    map_txt->text = sfText_create();
    map_txt->pos.x = 700;
    map_txt->pos.y = 440;
    sfText_setFont(map_txt->text, map_txt->font);
    sfText_setString(map_txt->text, "Map 1");
    sfText_setCharacterSize(map_txt->text, 80);
    sfText_setColor(map_txt->text, sfWhite);
    sfText_setPosition(map_txt->text, map_txt->pos);
    map_percentage->text = sfText_create();
    map_percentage->pos.x = 740;
    map_percentage->pos.y = 530;
    sfText_setFont(map_percentage->text, map_txt->font);
    sfText_setString(map_percentage->text, "%0");
    sfText_setCharacterSize(map_percentage->text, 40);
    sfText_setColor(map_percentage->text, sfWhite);
    sfText_setPosition(map_percentage->text, map_percentage->pos);
}

void anim_map_text(menu_obj_t *menu, window_obj_t window)
{
    sfText_setString(menu->map_txt.text, my_strcat("Map ",
    my_int_to_str(menu->map_index)));
    sfRenderWindow_drawText(window.window, menu->map_txt.text, NULL);
    sfText_setString(menu->map_percentage.text,
    my_strcat(window.high_score[menu->map_index - 1], "%"));
    sfRenderWindow_drawText(window.window, menu->map_percentage.text, NULL);
}
