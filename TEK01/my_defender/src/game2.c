/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** game2
*/

#include "../include/include.h"

void init_game2(game_t *game, sfClock **clock, window_t *window)
{
    init_building(&game->allies.tower_1, (building_info_t){ARCHERS_HEALTH,
    ARCHERS_COOLDOWN, ARCHERS_DAMAGE, WIZARD_RANGE,
    (sprite_info_t){ALLY_POS_TOWER_1_X, ALLY_POS_TOWER_1_Y, 1, 1, 0, 0, 112,
    80, ARCHERS}, window->player.archer_lvl, (sprite_info_t){0, 0, 0.2, 0.2, 0,
    0, 34, 327, "assets/game_ui/bar_2.png"}, ARROW_PROJ}, clock);
    init_building(&game->allies.tower_2, (building_info_t){WIZARD_HEALTH,
    WIZARD_COOLDOWN, WIZARD_DAMAGE, WIZARD_RANGE,
    (sprite_info_t){ALLY_POS_TOWER_2_X, ALLY_POS_TOWER_2_Y, 1, 1, 0, 0, 120,
    100, WIZARD}, window->player.wizard_lvl, (sprite_info_t){0, 0, 0.2, 0.2, 0,
    0, 34, 327, "assets/game_ui/bar_2.png"}, WIZARD_PROJ}, clock);
    init_energy(&game->allies.energy, clock);
    init_energy(&window->level.enemies.energy, clock);
}

int init_game(game_t *game, sfClock **clock, window_t *window)
{
    char *music_path[3] = {"assets/music/game_1.ogg", "assets/music/game_2.ogg",
    "assets/music/game_3.ogg"};

    game->allies.soldiers = NULL;
    game->has_started = 0;
    randomize();
    init_building(&game->allies.hdv, (building_info_t){HDV_HEALTH, 0, 0, 0,
    (sprite_info_t){ALLY_POS_HDV_X, ALLY_POS_HDV_Y, 1, 1, 0, 0, 110, 120, HDV},
    window->player.hdv_lvl, (sprite_info_t){0, 0, 0.2, 0.2, 0, 0, 34, 327,
    "assets/game_ui/bar_2.png"}, 0}, clock);
    init_game2(game, clock, window);

    init_ai(window);
    init_ig_ui(&game->ig_ui);
    init_choosing(game, window);
    music_set_audio(&game->music, music_path[rand() % (3 - 1)],
    window->music_volume);
}

void card_picked(game_t *game, sfMouseButtonEvent mouse, card_t *card)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(card->sprite.sprite);

    if (sfFloatRect_contains(&rect, mouse.x, mouse.y) &&
    game->allies.energy.value >= card->cost)
        card->is_moved = 1;
}

void card_released(game_t *game, sfMouseButtonEvent mouse,
window_t *window, card_t *card)
{
    if (card->is_moved) {
        card->is_moved = 0;
        game->allies.energy.value -= card->cost;
        card->info.walk_info.pos_x = mouse.x;
        card->info.walk_info.pos_y = mouse.y;
        add_soldier(card->info, &game->allies.soldiers, &window->clock);
    }
}

int game_mouse_event(game_t *game, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect pause_box =
    sfSprite_getGlobalBounds(window->game.ig_ui.pause_level.sprite);
    sfFloatRect play_box =
    sfSprite_getGlobalBounds(window->game.ig_ui.play_level.sprite);

    sfSound_play(window->click);
    for (int i = 0; i < window->level.cards; i++)
        card_picked(game, mouse, &game->ig_ui.cards[i]);
    if (sfFloatRect_contains(&pause_box, mouse.x, mouse.y) &&
    window->game.has_started) {
        window->index = 3;
    }
    if (sfFloatRect_contains(&play_box, mouse.x, mouse.y) &&
    !window->game.has_started) {
        window->game.has_started = 1;
    }
    if (!game->has_started) {
        placement_event(&game->placement_top, mouse, window, 1);
        placement_event(&game->placement_bot, mouse, window, 0);
    }
}