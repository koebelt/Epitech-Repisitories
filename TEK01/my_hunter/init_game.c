/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** init_game.c
*/

#include "include.h"

void init_game_sprites(game_obj_t *game)
{
    init_hunter(&game->hunter);
    init_hand(&game->hand);
    init_crosshair(&game->crosshair);
    init_bottle(&game->bottle);
    set_audio(&game->breaking_bottle, "ressources/Bottle Breakshort.wav");
    set_audio(&game->gun, "ressources/gun.ogg");
    init_health(&game->health_bar);
}

void init_game(game_obj_t *game)
{
    init_game_sprites(game);
    game->music = sfMusic_createFromFile("ressources/music1.wav");
    sfMusic_setLoop(game->music, sfTrue);
    game->score = 0;
    game->health = 11;
    game->mvmnt_clock = sfClock_create();
    game->anim_clock = sfClock_create();
    game->hand_clock = sfClock_create();
    game->bullet_clock = sfClock_create();
    game->font = sfFont_createFromFile("ressources/BitPap.ttf");
    game->text = sfText_create();
    game->text_pos.x = 450;
    game->text_pos.y = 0;
    sfText_setFont(game->text, game->font);
    sfText_setString(game->text, "SCORE");
    sfText_setCharacterSize(game->text, 50);
    sfText_setColor(game->text, sfWhite);
    sfText_setPosition(game->text, game->text_pos);
}
