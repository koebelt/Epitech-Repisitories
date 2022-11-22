/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** init_bottles2.c
*/

#include "include.h"

void init_bwhine(button_t *bwhine)
{
    bwhine->sprite.sprite = sfSprite_create();
    bwhine->sprite.pos.x = 650;
    bwhine->sprite.pos.y = 50;
    bwhine->sprite.scale.x = 8;
    bwhine->sprite.scale.y = 8;
    bwhine->sprite.texture = sfTexture_createFromFile("ressources/bottle3.png",
    NULL);
    bwhine->sprite.size_text = sfTexture_getSize(bwhine->sprite.texture);
    bwhine->font = sfFont_createFromFile("ressources/BitPap.ttf");
    bwhine->text = sfText_create();
    bwhine->text_pos.x = 350;
    bwhine->text_pos.y = 10;
    sfText_setFont(bwhine->text, bwhine->font);
    sfText_setString(bwhine->text, "Score of 50 needed");
    sfText_setCharacterSize(bwhine->text, 50);
    sfText_setColor(bwhine->text, sfWhite);
    sfText_setPosition(bwhine->text, bwhine->text_pos);
    sfSprite_setScale(bwhine->sprite.sprite, bwhine->sprite.scale);
    sfSprite_setTexture(bwhine->sprite.sprite, bwhine->sprite.texture, sfFalse);
}

void init_gwhine(button_t *gwhine)
{
    gwhine->sprite.sprite = sfSprite_create();
    gwhine->sprite.pos.x = 780;
    gwhine->sprite.pos.y = 200;
    gwhine->sprite.scale.x = 8;
    gwhine->sprite.scale.y = 8;
    gwhine->sprite.texture = sfTexture_createFromFile("ressources/bottle4.png",
    NULL);
    gwhine->sprite.size_text = sfTexture_getSize(gwhine->sprite.texture);
    gwhine->font = sfFont_createFromFile("ressources/BitPap.ttf");
    gwhine->text = sfText_create();
    gwhine->text_pos.x = 350;
    gwhine->text_pos.y = 10;
    sfText_setFont(gwhine->text, gwhine->font);
    sfText_setString(gwhine->text, "Score of 75 needed");
    sfText_setCharacterSize(gwhine->text, 50);
    sfText_setColor(gwhine->text, sfWhite);
    sfText_setPosition(gwhine->text, gwhine->text_pos);
    sfSprite_setScale(gwhine->sprite.sprite, gwhine->sprite.scale);
    sfSprite_setTexture(gwhine->sprite.sprite, gwhine->sprite.texture, sfFalse);
}

void init_champagne(button_t *champagne)
{
    champagne->sprite.sprite = sfSprite_create();
    champagne->sprite.pos.x = 900;
    champagne->sprite.pos.y = 400;
    champagne->sprite.scale.x = 8;
    champagne->sprite.scale.y = 8;
    champagne->sprite.texture = sfTexture_createFromFile(
    "ressources/bottle5.png", NULL);
    champagne->sprite.size_text = sfTexture_getSize(champagne->sprite.texture);
    champagne->font = sfFont_createFromFile("ressources/BitPap.ttf");
    champagne->text = sfText_create();
    champagne->text_pos.x = 350;
    champagne->text_pos.y = 10;
    sfText_setFont(champagne->text, champagne->font);
    sfText_setString(champagne->text, "Score of 100 needed");
    sfText_setCharacterSize(champagne->text, 50);
    sfText_setColor(champagne->text, sfWhite);
    sfText_setPosition(champagne->text, champagne->text_pos);
    sfSprite_setScale(champagne->sprite.sprite, champagne->sprite.scale);
    sfSprite_setTexture(champagne->sprite.sprite, champagne->sprite.texture,
    sfFalse);
}
