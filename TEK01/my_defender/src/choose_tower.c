/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** choose_tower
*/

#include "../include/include.h"

void init_placement(tower_placement_t *placement, sfVector2f pos, player_t *pl)
{
    placement->background = init_sprite((sprite_info_t){pos.x, pos.y, 1, 0.8,
    0, 0, 0, 0, "assets/game_ui/table_tower.png"});
    placement->archer = init_sprite((sprite_info_t){pos.x + 20, pos.y + 5,
    0.5, 0.5, 0, 80 * (pl->archer_lvl - 1), 112, 80,
    "assets/buildings/archers_sheets.png"});
    placement->wizard = init_sprite((sprite_info_t){pos.x + 80, pos.y + 5,
    0.5, 0.5, 0, 100 * (pl->wizard_lvl - 1), 120, 100,
    "assets/buildings/wizard_tower_sheets.png"});
    placement->inferno = init_sprite((sprite_info_t){pos.x + 150, pos.y + 5,
    0.5, 0.5, 0, 100 * (pl->inferno_lvl - 1), 140, 100,
    "assets/buildings/inferno_sheets.png"});
    placement->eagle = init_sprite((sprite_info_t){pos.x + 220, pos.y + 5,
    0.4, 0.4, 0, 140 * (pl->eagle_lvl - 1), 170, 140,
    "assets/buildings/eagles_sheets.png"});
    placement->tesla = init_sprite((sprite_info_t){pos.x + 296, pos.y + 5,
    0.5, 0.5, 0, 75 * (pl->tesla_lvl - 1), 120, 75,
    "assets/buildings/tesla_sheets.png"});
}

void init_choosing(game_t *game, window_t *window)
{
    init_placement(&game->placement_top, (sfVector2f){320, 280},
    &window->player);
    init_placement(&game->placement_bot, (sfVector2f){320, 700},
    &window->player);
    game->bot = 2;
    game->top = 1;
}

void placement_event(tower_placement_t *pa, sfMouseButtonEvent m, window_t *w,
int p)
{
    archer_placement(pa, m, w, p);
    wizard_placement(pa, m, w, p);
    inferno_placement(pa, m, w, p);
    eagle_placement(pa, m, w, p);
    tesla_placement(pa, m, w, p);
}

void disp_placement(tower_placement_t *placement, window_t *window)
{
    sfRenderWindow_drawSprite(window->window, placement->background.sprite,
    NULL);
    sfRenderWindow_drawSprite(window->window, placement->archer.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, placement->wizard.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, placement->inferno.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, placement->eagle.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, placement->tesla.sprite, NULL);
}

void disp_choosing(game_t *game, window_t *window)
{
    disp_placement(&game->placement_top, window);
    disp_placement(&game->placement_bot, window);
}