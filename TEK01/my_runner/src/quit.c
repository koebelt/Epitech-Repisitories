/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** quit.c
*/

#include "include.h"

void init_quit(button_t *quit)
{
    quit->sprite.sprite = sfSprite_create();
    quit->sprite.pos.x = 1000;
    quit->sprite.pos.y = 10;
    quit->sprite.scale.x = 4;
    quit->sprite.scale.y = 4;
    quit->sprite.texture = sfTexture_createFromFile("ressources/quit.png",
    NULL);
    quit->sprite.size_text = sfTexture_getSize(quit->sprite.texture);
    quit->font = sfFont_createFromFile("ressources/BitPap.ttf");
    quit->text = sfText_create();
    quit->text_pos.x = 100;
    quit->text_pos.y = 300;
    sfText_setFont(quit->text, quit->font);
    sfText_setString(quit->text, "QUIT");
    sfText_setCharacterSize(quit->text, 240);
    sfText_setColor(quit->text, sfWhite);
    sfText_setPosition(quit->text, quit->text_pos);
    sfSprite_setScale(quit->sprite.sprite, quit->sprite.scale);
    sfSprite_setTexture(quit->sprite.sprite, quit->sprite.texture, sfFalse);
}

void anim_quit(button_t *quit, sfVector2i mouse,
    sfRenderWindow **window)
{
    sfFloatRect box = sfSprite_getGlobalBounds(quit->sprite.sprite);

    if (sfFloatRect_contains(&box, mouse.x, mouse.y))
        sfRenderWindow_drawText(*window, quit->text, NULL);
    sfSprite_setPosition(quit->sprite.sprite, quit->sprite.pos);
    sfRenderWindow_drawSprite(*window, quit->sprite.sprite, NULL);
}
