/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** run_dongeon
*/

#include "dongeon.h"

void dungeon_events(window_t *window)
{
    player_dong_mvnt(&window->dongeon.player, window);
    show_inventory(window);
    show_quest_log(window);
    get_points(window);
}

void animate_death(player_dong_t *player, window_t *window)
{
    if (player->sprite.rect.top != 128) {
        player->sprite.rect.top = 128;
        player->sprite.rect.left = 0;
    }
    animate_sprite_attack(&player->sprite, window, 9, 0.2);
    if (player->sprite.rect.left == 288) {
        window->index = 1;
    }
}

void run_dongeon(window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
    window->dongeon.player.current->sprite.sprite, NULL);
    if (window->dongeon.player.stats.health >= 0)
        sfText_setString(window->dongeon.player.health_nbr.text,
        int_to_str(window->dongeon.player.stats.health));
    else
        sfText_setString(window->dongeon.player.health_nbr.text, "0");
    sfRenderWindow_drawText(window->window,
    window->dongeon.player.health.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->dongeon.player.health_nbr.text, NULL);
    for (int i = 0; i < 4; ++i)
        run_dungeon_start(window, i);
    sfMusic_stop(window->ext.music);
    if (!sfMusic_getStatus(window->dongeon.easy_music))
        sfMusic_play(window->dongeon.easy_music);
    display_miscs(window, window->dongeon.player.current->miscs);
    run_dungeon_mid(window);
}