/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** menu_bottons.c
*/

#include "include.h"

void init_start(button_t *start)
{
    start->sprite.sprite = sfSprite_create();
    start->sprite.pos.x = 600;
    start->sprite.pos.y = 50;
    start->sprite.scale.x = 6;
    start->sprite.scale.y = 6;
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

void anim_start(button_t *start, sfVector2i mouse, sfRenderWindow **window)
{
    sfFloatRect box = sfSprite_getGlobalBounds(start->sprite.sprite);

    if (sfFloatRect_contains(&box, mouse.x, mouse.y))
        sfRenderWindow_drawText(*window, start->text, NULL);
    sfSprite_setPosition(start->sprite.sprite, start->sprite.pos);
    sfRenderWindow_drawSprite(*window, start->sprite.sprite, NULL);
}
