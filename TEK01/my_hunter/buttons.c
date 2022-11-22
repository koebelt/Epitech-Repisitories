/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** buttons.c
*/

#include "include.h"

void init_start(button_t *start)
{
    start->sprite.sprite = sfSprite_create();
    start->sprite.pos.x = 600;
    start->sprite.pos.y = 50;
    start->sprite.scale.x = 8;
    start->sprite.scale.y = 8;
    start->sprite.texture = sfTexture_createFromFile("ressources/start.png",
    NULL);
    start->sprite.size_text = sfTexture_getSize(start->sprite.texture);
    start->font = sfFont_createFromFile("ressources/BitPap.ttf");
    start->text = sfText_create();
    start->text_pos.x = 100;
    start->text_pos.y = 300;
    sfText_setFont(start->text, start->font);
    sfText_setString(start->text, "START");
    sfText_setCharacterSize(start->text, 240);
    sfText_setColor(start->text, sfWhite);
    sfText_setPosition(start->text, start->text_pos);
    sfSprite_setScale(start->sprite.sprite, start->sprite.scale);
    sfSprite_setTexture(start->sprite.sprite, start->sprite.texture, sfFalse);
}

void anim_start(button_t *start, sfVector2i mouse_pos, sfRenderWindow **window)
{
    if (mouse_pos.x > start->sprite.pos.x && mouse_pos.x < (start->sprite.pos.x
    + start->sprite.size_text.x * start->sprite.scale.x) && mouse_pos.y >
    start->sprite.pos.y && mouse_pos.y < (start->sprite.pos.y +
    start->sprite.size_text.x * start->sprite.scale.y))
        sfRenderWindow_drawText(*window, start->text, NULL);
    sfSprite_setPosition(start->sprite.sprite, start->sprite.pos);
    sfRenderWindow_drawSprite(*window, start->sprite.sprite, NULL);
}

void init_choose(button_t *choose)
{
    choose->sprite.sprite = sfSprite_create();
    choose->sprite.pos.x = 600;
    choose->sprite.pos.y = 310;
    choose->sprite.scale.x = 8;
    choose->sprite.scale.y = 8;
    choose->sprite.texture = sfTexture_createFromFile("ressources/choose.png",
    NULL);
    choose->sprite.size_text = sfTexture_getSize(choose->sprite.texture);
    choose->font = sfFont_createFromFile("ressources/BitPap.ttf");
    choose->text = sfText_create();
    choose->text_pos.x = 100;
    choose->text_pos.y = 300;
    sfText_setFont(choose->text, choose->font);
    sfText_setString(choose->text, "CHOOSE");
    sfText_setCharacterSize(choose->text, 240);
    sfText_setColor(choose->text, sfWhite);
    sfText_setPosition(choose->text, choose->text_pos);
    sfSprite_setScale(choose->sprite.sprite, choose->sprite.scale);
    sfSprite_setTexture(choose->sprite.sprite, choose->sprite.texture, sfFalse);
}
void anim_choose(button_t *choose, sfVector2i mouse_pos,
    sfRenderWindow **window)
{
    if (mouse_pos.x > choose->sprite.pos.x && mouse_pos.x <
    (choose->sprite.pos.x + choose->sprite.size_text.x * choose->sprite.scale.x)
    && mouse_pos.y > choose->sprite.pos.y && mouse_pos.y < (choose->sprite.pos.y
    + choose->sprite.size_text.x * choose->sprite.scale.y))
        sfRenderWindow_drawText(*window, choose->text, NULL);
    sfSprite_setPosition(choose->sprite.sprite, choose->sprite.pos);
    sfRenderWindow_drawSprite(*window, choose->sprite.sprite, NULL);
}
