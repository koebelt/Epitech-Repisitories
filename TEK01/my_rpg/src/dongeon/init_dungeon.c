/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** init_dungeon
*/

#include "dongeon.h"

void init_dungeon_two(window_t *window)
{
    window->dongeon.player.health_nbr.pos.x = 250;
    window->dongeon.player.health_nbr.pos.y = 200;
    sfText_setPosition(window->dongeon.player.health.text,
    window->dongeon.player.health.pos);
    sfText_setPosition(window->dongeon.player.health_nbr.text,
    window->dongeon.player.health_nbr.pos);
}

void init_dungeon(window_t *window)
{
    window->dongeon.player.stats.health = 350;
    window->dongeon.entrance = NULL;
    window->dongeon.list = NULL;
    load_random_dongeon(window, &window->dongeon);
    window->dongeon.player.current = window->dongeon.entrance;
    init_player_dong(&window->dongeon.player, window);
    music_set_audio(&window->dongeon.easy_music, EASY_MUSIC,
    window->music_volume);
    init_text(&window->dongeon.player.health, "health :", (sfVector2f){1, 1},
    1);
    init_text(&window->dongeon.player.health_nbr, "1", (sfVector2f){1, 1}, 1);
    sfText_setColor(window->dongeon.player.health.text, sfRed);
    sfText_setColor(window->dongeon.player.health_nbr.text, sfRed);
    window->dongeon.view.size = (sfFloatRect){0, 0, window->mode.width,
    window->mode.height};
    window->dongeon.view.view =
    sfView_createFromRect(window->dongeon.view.size);
    window->dongeon.player.health.pos.x = 100;
    window->dongeon.player.health.pos.y = 200;
    init_dungeon_two(window);
}