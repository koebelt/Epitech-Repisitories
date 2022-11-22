/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** menu2
*/

#include "../include/include.h"

void init_menu2(menu_t *menu, window_t *window)
{
    menu->background = init_sprite((sprite_info_t){0, 0, 1, 1, 0, 0, 1080, 1920,
    BG});
    menu->banner = init_sprite((sprite_info_t){685, 40, 1.2, 1.2, 0, 0, 300,
    450, "assets/menu/rd_banner.png"});
    menu->play = init_sprite((sprite_info_t){850, 500, 0.65, 0.65, 0, 0, 329,
    331, "assets/menu/button_play.png"});
    menu->exit = init_sprite((sprite_info_t){790, 770, 1, 1, 0, 0, 175, 330,
    "assets/menu/button_exit.png"});
    menu->how_to_play = init_sprite((sprite_info_t){1550, 770, 1, 1, 0, 0, 175,
    330, "assets/menu/button_how_to_play.png"});
    menu->music_on = init_sprite((sprite_info_t){40, 40, 0.8, 0.8, 0, 0, 175,
    176, "assets/menu/button_music.png"});
    menu->sound_on = init_sprite((sprite_info_t){200, 40, 0.8, 0.8, 0, 0, 175,
    176, "assets/menu/button_sound.png"});
    menu->music_off = init_sprite((sprite_info_t){-300, -300, 0.8, 0.8, 0, 0,
    175, 176, "assets/menu/button_music_off.png"});
    menu->sound_off = init_sprite((sprite_info_t){-600, -600, 0.8, 0.8, 0, 0,
    175, 176, "assets/menu/button_sound_off.png"});
    menu->setting_button = init_sprite((sprite_info_t){1740, 40, 0.8, 0.8, 0, 0,
    175, 176, "assets/menu/button_settings.png"});
}

void init_menu3(menu_t *menu, window_t *window)
{
    menu->setting_minus2 = init_sprite((sprite_info_t){544, -2000, 0.8, 0.8, 0,
    0, 62, 62, "assets/menu/button_minus.png"});
    menu->music_bar = init_sprite((sprite_info_t){610, -2000, 1, 1, 0, 0, 35,
    106, "assets/menu/bar.png"});
    menu->sound_bar = init_sprite((sprite_info_t){610, -2000, 1, 1, 0, 0, 35,
    106, "assets/menu/bar.png"});
    menu->shop_button = init_sprite((sprite_info_t){50, 770, 1, 1, 0, 0, 175,
    330, "assets/menu/button_shop.png"});

    music_set_audio(&menu->music, "assets/music/menu.ogg",
    window->music_volume);
}

void init_menu(menu_t *menu, window_t *window)
{
    init_menu2(menu, window);
    menu->setting_menu = init_sprite((sprite_info_t){470, -2000, 1, 1, 0, 0,
    627, 966, "assets/menu/setting_menu.png"});
    menu->setting_close = init_sprite((sprite_info_t){1350, -2000, 1, 1, 0, 0,
    104, 104, "assets/menu/setting_cl.png"});
    menu->setting_plus1 = init_sprite((sprite_info_t){838, -2000, 0.8, 0.8, 0,
    0, 62, 62, "assets/menu/button_plus.png"});
    menu->setting_minus1 = init_sprite((sprite_info_t){544, -2000, 0.8, 0.8, 0,
    0, 62, 62, "assets/menu/button_minus.png"});
    menu->setting_plus2 = init_sprite((sprite_info_t){838, -2000, 0.8, 0.8, 0,
    0, 62, 62, "assets/menu/button_plus.png"});
    init_menu3(menu, window);
}

void menu2(window_t *window)
{
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.play);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.setting_button);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.music_on);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.sound_on);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.music_off);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.sound_off);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.exit);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.setting_close);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.setting_plus1);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.setting_minus1);
}

void menu3(window_t *window)
{
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.setting_plus2);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.setting_minus2);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.shop_button);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->menu.how_to_play);
    sfRenderWindow_drawSprite(window->window, window->menu.background.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.banner.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.play.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.music_on.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.music_off.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window,
    window->menu.setting_button.sprite, sfFalse);
}