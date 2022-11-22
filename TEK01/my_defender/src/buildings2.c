/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** buildings2
*/

#include "../include/include.h"

int intersects(circle_t circle, sfFloatRect rect)
{
    float circle_distance_x = abs(circle.pos.x  + circle.radius - rect.left);
    float circle_distance_y = abs(circle.pos.y  + circle.radius - rect.top);
    float cornerDistance_sq = pow((circle_distance_x - rect.width/2), 2) +
    pow((circle_distance_y - rect.height/2), 2);

    if ((circle_distance_x > (rect.width/2 + circle.radius)) ||
    (circle_distance_y > (rect.height/2 + circle.radius)))
        return (0);
    else if (circle_distance_x <= (rect.width/2) ||
    (circle_distance_y <= (rect.height/2)) ||
    (cornerDistance_sq <= pow(circle.radius, 2)))
        return (1);
    else
        return (0);
}

void display_buildings(game_t *game, window_t *window)
{
    display_building(&game->allies.hdv, window, 0);
    display_building(&game->allies.tower_1, window,
    window->level.enemies.soldiers);
    display_building(&game->allies.tower_2, window,
    window->level.enemies.soldiers);

    display_building(&window->level.enemies.hdv, window, 0);
    display_building(&window->level.enemies.tower_1,
    window, game->allies.soldiers);
    display_building(&window->level.enemies.tower_2, window,
    game->allies.soldiers);
}