/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** game.c
*/

#include "include.h"

int analyse_game_events(window_obj_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        window->index = 0;
        init_menu(&window->menu, &window->clock, window);
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue &&
    !window->game.hero.is_jumping && !window->game.hero.is_dead &&
    !window->game.hero.is_falling) {
        window->game.hero.is_jumping = 1;
        sfSound_play(window->game.jump);
        init_jump(&window->game.hero, &window->clock);
    }
}

void init_game(game_obj_t *game, sfClock **clock, window_obj_t *window)
{
    init_game_layer(&game->background);
    init_hero(&game->hero.sprite, clock);
    set_audio(&game->jump, "ressources/jump.wav");
    set_audio(&game->death, "ressources/death.wav");
    game->music = sfMusic_createFromFile("ressources/game.wav");
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_setVolume(game->music, 20.0);
    game->hero.is_jumping = 0;
    game->hero.is_falling = 0;
    game->hero.is_dead = 0;
    game->t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
    game->background.velocity = 5;
    game->background.background_color.r = 193;
    game->background.background_color.g = 215;
    game->background.background_color.b = 220;
    init_obstacles(&game->obstacles);
    load_map(game->map, window);
    init_percent(game);
}

void display_hero(window_obj_t *window)
{
    if (!window->game.hero.is_dead) {
        if (window->game.hero.is_jumping && !window->game.hero.is_falling)
            anim_jump(&window->game.hero, window, &window->game.obstacles);
        if (!window->game.hero.is_jumping && !window->game.hero.is_falling)
            anim_hero(&window->game.hero, &window->clock, &window->window);
        compute_collisions(&window->game.hero, &window->game.obstacles, window);
        if (!window->game.hero.is_jumping)
            sfRenderWindow_drawSprite(window->window,
            window->game.hero.sprite.sprite, NULL);
    } else if (death_particles(&window->game.hero, &window->window,
        window->clock)) {
        renit_game(&window->game, &window->clock, window);
    }
}

void disp_background(window_obj_t *window)
{
    sfRenderWindow_drawSprite(window->window,
    window->game.background.moon.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->game.background.ground.sprite, NULL);
    calc_layers(&window->game.background, &window->window);
    calc_layers_part_two(&window->game.background, &window->window);
    calc_layers_part_three(&window->game.background, &window->window);
    calc_layers_part_four(&window->game.background, &window->window);
}

void game(window_obj_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        analyse_game_events(window);
    }
    sfMusic_stop(window->menu.music);
    if (!sfMusic_getStatus(window->game.music))
        sfMusic_play(window->game.music);
    disp_background(window);
    display_map(&window->game.obstacles, window,
    window->game.background.velocity);
    display_hero(window);
    anim_percent(&window->game, &window->window);
}
