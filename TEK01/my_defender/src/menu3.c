/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** menu
*/

#include "../include/include.h"

int menu_mouse_event2(menu_t *menu, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect end_box = sfSprite_getGlobalBounds(menu->exit.sprite);
    sfFloatRect music_on_box = sfSprite_getGlobalBounds(menu->music_on.sprite);

    if (sfFloatRect_contains(&end_box, mouse.x, mouse.y))
        sfRenderWindow_close(window->window);
    else if (sfFloatRect_contains(&music_on_box, mouse.x, mouse.y)) {
        sfSprite_setPosition(menu->music_off.sprite, (sfVector2f){40, 40});
        sfSprite_setPosition(menu->music_on.sprite, (sfVector2f){-300, -300});
        menu->music_bar.rect.width = 0;
        sfSprite_setTextureRect(menu->music_bar.sprite, menu->music_bar.rect);
        window->music_volume = 0;
    } else
        menu_mouse_event3(menu, mouse, window);
}

int menu_mouse_event3(menu_t *menu, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect music_off_box =
    sfSprite_getGlobalBounds(menu->music_off.sprite);
    sfFloatRect sound_on_box = sfSprite_getGlobalBounds(menu->sound_on.sprite);

    if (sfFloatRect_contains(&music_off_box, mouse.x, mouse.y)) {
        sfSprite_setPosition(menu->music_off.sprite, (sfVector2f){-300, -300});
        sfSprite_setPosition(menu->music_on.sprite, (sfVector2f){40, 40});
        menu->music_bar.rect.width = 106;
        sfSprite_setTextureRect(menu->music_bar.sprite, menu->music_bar.rect);
        window->music_volume = 50;
    } else if (sfFloatRect_contains(&sound_on_box, mouse.x, mouse.y)) {
        sfSprite_setPosition(menu->sound_off.sprite, (sfVector2f){200, 40});
        sfSprite_setPosition(menu->sound_on.sprite, (sfVector2f){-600, -600});
        menu->sound_bar.rect.width = 0;
        sfSprite_setTextureRect(menu->sound_bar.sprite, menu->sound_bar.rect);
        window->sound_volume = 0;
    } else
        menu_mouse_event4(menu, mouse, window);
}

int menu_mouse_event4(menu_t *menu, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect sound_off_box =
    sfSprite_getGlobalBounds(menu->sound_off.sprite);

    if (sfFloatRect_contains(&sound_off_box, mouse.x, mouse.y)) {
        sfSprite_setPosition(menu->sound_off.sprite, (sfVector2f){-600, -600});
        sfSprite_setPosition(menu->sound_on.sprite, (sfVector2f){200, 40});
        menu->sound_bar.rect.width = 106;
        sfSprite_setTextureRect(menu->sound_bar.sprite, menu->sound_bar.rect);
        window->sound_volume = 50;
    } else
        menu_mouse_event5(menu, mouse, window);
}

int menu_mouse_event5(menu_t *menu, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect set_box = sfSprite_getGlobalBounds(menu->setting_button.sprite);

    if (sfFloatRect_contains(&set_box, mouse.x, mouse.y)) {
        sfSprite_setPosition(menu->setting_menu.sprite, (sfVector2f){470, 200});
        sfSprite_setPosition(menu->setting_close.sprite,
        (sfVector2f){1350, 180});
        sfSprite_setPosition(menu->setting_plus1.sprite,
        (sfVector2f){838, 438});
        sfSprite_setPosition(menu->setting_minus1.sprite,
        (sfVector2f){544, 438});
        sfSprite_setPosition(menu->setting_plus2.sprite,
        (sfVector2f){838, 617});
        sfSprite_setPosition(menu->setting_minus2.sprite,
        (sfVector2f){544, 617});
        sfSprite_setPosition(menu->music_bar.sprite, (sfVector2f){610, 442});
        sfSprite_setPosition(menu->sound_bar.sprite, (sfVector2f){610, 618});
        sfSprite_setPosition(menu->play.sprite, (sfVector2f){0, -3000});
        sfSprite_setPosition(menu->exit.sprite, (sfVector2f){0, -3000});
    } else
        menu_mouse_event6(menu, mouse, window);
}

int menu_mouse_event6(menu_t *menu, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect close_b = sfSprite_getGlobalBounds(menu->setting_close.sprite);

    if (sfFloatRect_contains(&close_b, mouse.x, mouse.y)) {
        sfSprite_setPosition(menu->setting_menu.sprite,
        (sfVector2f){470, -2000});
        sfSprite_setPosition(menu->setting_close.sprite,
        (sfVector2f){1350, -2000});
        sfSprite_setPosition(menu->setting_plus1.sprite,
        (sfVector2f){838, -2000});
        sfSprite_setPosition(menu->setting_minus1.sprite,
        (sfVector2f){544, -2000});
        sfSprite_setPosition(menu->setting_plus2.sprite,
        (sfVector2f){838, -2000});
        sfSprite_setPosition(menu->setting_minus2.sprite,
        (sfVector2f){544, -2000});
        sfSprite_setPosition(menu->music_bar.sprite, (sfVector2f){610, -2000});
        sfSprite_setPosition(menu->sound_bar.sprite, (sfVector2f){610, -2000});
        sfSprite_setPosition(menu->play.sprite, (sfVector2f){850, 500});
        sfSprite_setPosition(menu->exit.sprite, (sfVector2f){800, 770});
    } else
        menu_mouse_event7(menu, mouse, window);
}