/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** settings
*/

#include "menu.h"

void init_settings(window_t *window)
{
    init_sprite(&window->menu.settings.bg, (sprite_info_t)
    {0, 0, 1, 0, 0, 1940, 720, MAP}, window);
    init_sprite(&window->menu.settings.back, (sprite_info_t)
    {10, 650, 1, 0, 0, 192, 48, BACK_BTN}, window);
    init_sprite(&window->menu.settings.music_title, (sprite_info_t)
    {400, 120, 0.4, 0, 0, 500, 200, MUSIC_TITLE}, window);
    init_sprite(&window->menu.settings.display_title, (sprite_info_t)
    {700, 120, 0.3, 0, 0, 500, 200, DISPLAY_TITLE}, window);
    init_sprite(&window->menu.settings.music, (sprite_info_t)
    {350, 250, 0.5, 0, 0, 176, 175, MUSIC_BTN}, window);
    init_sprite(&window->menu.settings.table, (sprite_info_t)
    {300, 100, 0.7, 0, 0, 966, 627, TABLE_IMG}, window);
    init_sprite(&window->menu.settings.music_bar, (sprite_info_t)
    {350, 350, 0.5, 0, 0, 1132, 71, LOAD_BAR}, window);
    init_sprite(&window->menu.settings.minus_btn, (sprite_info_t)
    {400, 400, 0.7, 0, 0, 62, 60, MINUS_BTN}, window);
    init_sprite(&window->menu.settings.plus_btn, (sprite_info_t)
    {350, 400, 0.7, 0, 0, 62, 60, PLUS_BTN}, window);
}

void init_videostg(window_t *window)
{
    init_sprite(&window->menu.settings.videosettings.bg, (sprite_info_t)
    {0, 0, 1, 0, 0, 1940, 720, MAP}, window);
    init_sprite(&window->menu.settings.videosettings.music_title,
    (sprite_info_t){400, 120, 0.3, 0, 0, 500, 200, MUSIC_TITLE}, window);
    init_sprite(&window->menu.settings.videosettings.display_title,
    (sprite_info_t){700, 120, 0.4, 0, 0, 500, 200, DISPLAY_TITLE}, window);
    init_sprite(&window->menu.settings.videosettings.table, (sprite_info_t)
    {300, 100, 0.7, 0, 0, 966, 627, TABLE_IMG}, window);
    init_sprite(&window->menu.settings.videosettings.back, (sprite_info_t)
    {10, 650, 1, 0, 0, 192, 48, BACK_BTN}, window);
    init_sprite(&window->menu.settings.videosettings.sound, (sprite_info_t)
    {350, 250, 0.5, 0, 0, 176, 175, MUSIC_BTN}, window);
    init_sprite(&window->menu.settings.videosettings.sound_bar, (sprite_info_t)
    {350, 350, 0.5, 0, 0, 1132, 71, LOAD_BAR}, window);
    init_sprite(&window->menu.settings.videosettings.minus_btn, (sprite_info_t)
    {400, 400, 0.7, 0, 0, 62, 60, MINUS_BTN}, window);
    init_sprite(&window->menu.settings.videosettings.plus_btn, (sprite_info_t)
    {350, 400, 0.7, 0, 0, 62, 60, PLUS_BTN}, window);
}

void run_videostg(window_t *window)
{
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .videosettings.bg.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .videosettings.table.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .videosettings.music_title.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .videosettings.display_title.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .videosettings.back.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .videosettings.sound.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .videosettings.sound_bar.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .videosettings.minus_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .videosettings.plus_btn.sprite, NULL);
    load_bar(&window->menu.settings.videosettings.sound_bar,
    window->sound_volume);
}

void run_settings(window_t *window)
{
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .bg.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .table.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .music.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .music_title.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .display_title.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .music_bar.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .minus_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .plus_btn.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.settings
    .back.sprite, NULL);
    load_bar(&window->menu.settings.music_bar, window->music_volume);
}