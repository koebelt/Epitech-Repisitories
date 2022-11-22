/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** exterior
*/

#include "exterior.h"

void init_exterior(window_t *window)
{
    init_map(&window->ext.map, window);
    init_player_ext(&window->ext.player, window);
    init_npcs_with_quest(&window->ext.npcs, window);
    init_first_quest(window, &window->ext.npcs.first);
    init_second_quest(window, &window->ext.npcs.second);
    init_third_quest(window, &window->ext.npcs.third);
    init_fourth_quest(window, &window->ext.npcs.fourth);
    init_sprite(&window->ext.npc.guard,
    (sprite_info_t){1090, 615, 0.45, 800, 0, 80, 120, NPCS_TEXT}, window);
    init_sprite(&window->ext.npc.farmer,
    (sprite_info_t){1057, 810, 0.45, 320, 0, 80, 120, NPCS_TEXT}, window);
    window->ext.view.size = (sfFloatRect){0, 0, window->mode.width,
    window->mode.height};
    window->ext.view.view = sfView_createFromRect(window->ext.view.size);
    sfView_setCenter(window->ext.view.view, window->ext.player.sprite.pos);
    init_entrances(&window->ext.map, window);
    music_set_audio(&window->ext.music, "assets/musics/overworld.ogg",
    window->music_volume);
}

void exterior_events(window_t *window)
{
    player_ext_mvnt(&window->ext.player, window);
    player_interact(window, &window->ext.npcs.first);
    player_interact(window, &window->ext.npcs.second);
    player_interact(window, &window->ext.npcs.third);
    player_interact(window, &window->ext.npcs.fourth);
    show_inventory(window);
    show_quest_log(window);
    get_points(window);
    entrance_events(&window->ext.player, &window->ext.map, window);
}

void second_run_exterior(window_t *window)
{
    draw_npcs(window);
    draw_indicators(window, &window->ext.npcs.first);
    draw_indicators(window, &window->ext.npcs.second);
    if (window->ext.npcs.first.done == 1 &&
    window->ext.npcs.second.done == 1) {
        draw_indicators(window, &window->ext.npcs.third);
        draw_indicators(window, &window->ext.npcs.fourth);
    }
    disp_entrances(&window->ext.map, window);
    animate_player_ext(&window->ext.player, window);
    updating_indicator(&window->ext.npcs.first);
    updating_indicator(&window->ext.npcs.second);
    updating_indicator(&window->ext.npcs.third);
    updating_indicator(&window->ext.npcs.fourth);
    quest_log(window);
    inventory(window);
    handle_click_inventory(window);
    window->view_center = sfView_getCenter(window->ext.view.view);
}

void take_quest(window_t *window)
{
    if (window->ext.npcs.first.now == window->ext.npcs.first.obj)
        window->ext.npcs.first.taken = 2;
    if (window->ext.npcs.second.now == window->ext.npcs.second.obj)
        window->ext.npcs.second.taken = 2;
    if (window->ext.npcs.third.now == window->ext.npcs.third.obj)
        window->ext.npcs.third.taken = 2;
    if (window->ext.npcs.fourth.now == window->ext.npcs.fourth.obj)
        window->ext.npcs.fourth.taken = 2;
}

void run_exterior(window_t *window)
{
    sfMusic_stop(window->dongeon.easy_music);
    sfMusic_stop(window->menu.music);
    if (!sfMusic_getStatus(window->ext.music))
        sfMusic_play(window->ext.music);
    window->color = WATER_COLOR;
    run_map(&window->ext.map, window);
    update_quest(&window->ext.npcs.first, "Explorer la grotte ");
    update_quest(&window->ext.npcs.second, "Tuer des squelettes ! ");
    update_quest(&window->ext.npcs.third, "Eliminer quelques monstres ! ");
    update_quest(&window->ext.npcs.fourth,
    "En decouvrir plus sur les donjons ");
    take_quest(window);
    second_run_exterior(window);
    sfView_setCenter(window->ext.view.view, window->ext.player.sprite.pos);
    sfRenderWindow_setView(window->window, window->ext.view.view);
}