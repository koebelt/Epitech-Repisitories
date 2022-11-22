/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** init_bottles1.c
*/

#include "include.h"

void init_wwhine(button_t *wwhine)
{
    wwhine->sprite.sprite = sfSprite_create();
    wwhine->sprite.pos.x = 50;
    wwhine->sprite.pos.y = 400;
    wwhine->sprite.scale.x = 8;
    wwhine->sprite.scale.y = 8;
    wwhine->sprite.texture = sfTexture_createFromFile("ressources/bottle0.png",
    NULL);
    wwhine->sprite.size_text = sfTexture_getSize(wwhine->sprite.texture);
    wwhine->font = sfFont_createFromFile("ressources/BitPap.ttf");
    wwhine->text = sfText_create();
    wwhine->text_pos.x = 350;
    wwhine->text_pos.y = 10;
    sfText_setFont(wwhine->text, wwhine->font);
    sfText_setString(wwhine->text, "No score needed");
    sfText_setCharacterSize(wwhine->text, 50);
    sfText_setColor(wwhine->text, sfWhite);
    sfText_setPosition(wwhine->text, wwhine->text_pos);
    sfSprite_setScale(wwhine->sprite.sprite, wwhine->sprite.scale);
    sfSprite_setTexture(wwhine->sprite.sprite, wwhine->sprite.texture, sfFalse);
}

void init_rwhine(button_t *rwhine)
{
    rwhine->sprite.sprite = sfSprite_create();
    rwhine->sprite.pos.x = 170;
    rwhine->sprite.pos.y = 200;
    rwhine->sprite.scale.x = 8;
    rwhine->sprite.scale.y = 8;
    rwhine->sprite.texture = sfTexture_createFromFile("ressources/bottle1.png",
    NULL);
    rwhine->sprite.size_text = sfTexture_getSize(rwhine->sprite.texture);
    rwhine->font = sfFont_createFromFile("ressources/BitPap.ttf");
    rwhine->text = sfText_create();
    rwhine->text_pos.x = 350;
    rwhine->text_pos.y = 10;
    sfText_setFont(rwhine->text, rwhine->font);
    sfText_setString(rwhine->text, "Score of 10 needed");
    sfText_setCharacterSize(rwhine->text, 50);
    sfText_setColor(rwhine->text, sfWhite);
    sfText_setPosition(rwhine->text, rwhine->text_pos);
    sfSprite_setScale(rwhine->sprite.sprite, rwhine->sprite.scale);
    sfSprite_setTexture(rwhine->sprite.sprite, rwhine->sprite.texture, sfFalse);
}

void init_wiskey(button_t *wiskey)
{
    wiskey->sprite.sprite = sfSprite_create();
    wiskey->sprite.pos.x = 300;
    wiskey->sprite.pos.y = 50;
    wiskey->sprite.scale.x = 8;
    wiskey->sprite.scale.y = 8;
    wiskey->sprite.texture = sfTexture_createFromFile("ressources/bottle2.png",
    NULL);
    wiskey->sprite.size_text = sfTexture_getSize(wiskey->sprite.texture);
    wiskey->font = sfFont_createFromFile("ressources/BitPap.ttf");
    wiskey->text = sfText_create();
    wiskey->text_pos.x = 350;
    wiskey->text_pos.y = 10;
    sfText_setFont(wiskey->text, wiskey->font);
    sfText_setString(wiskey->text, "Score of 30 needed");
    sfText_setCharacterSize(wiskey->text, 50);
    sfText_setColor(wiskey->text, sfWhite);
    sfText_setPosition(wiskey->text, wiskey->text_pos);
    sfSprite_setScale(wiskey->sprite.sprite, wiskey->sprite.scale);
    sfSprite_setTexture(wiskey->sprite.sprite, wiskey->sprite.texture, sfFalse);
}
