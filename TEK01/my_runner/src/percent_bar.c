/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** percent_bar.c
*/

#include "include.h"

void init_percent(game_obj_t *game)
{
    game->initial_space = game->obstacles.obs9[0].pos.x -
    game->hero.sprite.pos.x;
    game->percent = 0;
    game->percent_txt.font = sfFont_createFromFile("ressources/BitPap.ttf");
    game->percent_txt.text = sfText_create();
    game->percent_txt.pos.x = 500;
    game->percent_txt.pos.y = 75;
    sfText_setFont(game->percent_txt.text, game->percent_txt.font);
    sfText_setString(game->percent_txt.text, "%0");
    sfText_setCharacterSize(game->percent_txt.text, 60);
    sfText_setColor(game->percent_txt.text, sfWhite);
    sfText_setPosition(game->percent_txt.text, game->percent_txt.pos);
    game->bar.rect = sfRectangleShape_create();
    game->bar.size.x = 0;
    game->bar.size.y = 20;
    game->bar.pos.x = 400;
    game->bar.pos.y = 50;
    sfRectangleShape_setSize(game->bar.rect, game->bar.size);
    sfRectangleShape_setPosition(game->bar.rect, game->bar.pos);
}

void anim_percent(game_obj_t *game, sfRenderWindow **window)
{
    int space = game->obstacles.obs9[0].pos.x - game->hero.sprite.pos.x;

    game->percent = 100 - (space * 100 / game->initial_space);
    game->bar.size.x = game->percent * 3;
    sfText_setString(game->percent_txt.text,
    my_strcat(my_int_to_str(game->percent), "%"));
    sfRectangleShape_setSize(game->bar.rect, game->bar.size);
    sfRenderWindow_drawText(*window, game->percent_txt.text, NULL);
    sfRenderWindow_drawRectangleShape(*window, game->bar.rect, NULL);
}
