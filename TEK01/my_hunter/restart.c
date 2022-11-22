/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** reset.c
*/

#include "include.h"

void init_reset(button_t *reset)
{
    reset->sprite.sprite = sfSprite_create();
    reset->sprite.pos.x = 10;
    reset->sprite.pos.y = 10;
    reset->sprite.scale.x = 4;
    reset->sprite.scale.y = 4;
    reset->sprite.texture = sfTexture_createFromFile("ressources/restart.png",
    NULL);
    reset->sprite.size_text = sfTexture_getSize(reset->sprite.texture);
    reset->font = sfFont_createFromFile("ressources/BitPap.ttf");
    reset->text = sfText_create();
    reset->text_pos.x = 100;
    reset->text_pos.y = 300;
    sfText_setFont(reset->text, reset->font);
    sfText_setString(reset->text, "RESET");
    sfText_setCharacterSize(reset->text, 240);
    sfText_setColor(reset->text, sfWhite);
    sfText_setPosition(reset->text, reset->text_pos);
    sfSprite_setScale(reset->sprite.sprite, reset->sprite.scale);
    sfSprite_setTexture(reset->sprite.sprite, reset->sprite.texture, sfFalse);
}

void anim_reset(button_t *reset, sfVector2i mouse_pos,
    sfRenderWindow **window)
{
    if (mouse_pos.x > reset->sprite.pos.x && mouse_pos.x <
    (reset->sprite.pos.x + reset->sprite.size_text.x * reset->sprite.scale.x)
    && mouse_pos.y > reset->sprite.pos.y && mouse_pos.y < (reset->sprite.pos.y
    + reset->sprite.size_text.x * reset->sprite.scale.y))
        sfRenderWindow_drawText(*window, reset->text, NULL);
    sfSprite_setPosition(reset->sprite.sprite, reset->sprite.pos);
    sfRenderWindow_drawSprite(*window, reset->sprite.sprite, NULL);
}
