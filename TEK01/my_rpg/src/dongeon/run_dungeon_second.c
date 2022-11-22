/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** run_dungeon
*/

#include "dongeon.h"

void run_dungeon_start(window_t *window, int i)
{
    if (window->dongeon.player.current->doors[i].pos.x != -1) {
        if (window->dongeon.player.current->monsters == NULL);
        else
            sfRenderWindow_drawSprite(window->window,
            window->dongeon.player.current->doors[i].sprite.sprite, NULL);
    } else
        sfRenderWindow_drawSprite(window->window,
        window->dongeon.player.current->doors[i].sprite.sprite, NULL);
}

void run_dungeon_mid(window_t *window)
{
    if (window->dongeon.player.stats.health > 0)
        animate_player_dong(&window->dongeon.player, window);
    else
        animate_death(&window->dongeon.player, window);
    player_dong_door_collision(&window->dongeon.player);
    display_monsters(window);
    display_projectile(window);
    quest_log(window);
    inventory(window);
    handle_click_inventory(window);
    window->color = (sfColor) {20, 11, 40, 1};
    sfRenderWindow_setView(window->window, window->dongeon.view.view);
    window->view_center = sfView_getCenter(window->dongeon.view.view);
}