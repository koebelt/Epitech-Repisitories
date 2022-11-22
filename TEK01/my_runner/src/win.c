/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** win.c
*/

#include "include.h"

void init_return_button(button_t *win)
{
    win->sprite.sprite = sfSprite_create();
    win->sprite.pos.x = 500;
    win->sprite.pos.y = 500;
    win->sprite.scale.x = 4;
    win->sprite.scale.y = 4;
    win->sprite.texture = sfTexture_createFromFile("ressources/quit.png",
    NULL);
    win->sprite.size_text = sfTexture_getSize(win->sprite.texture);
    win->font = sfFont_createFromFile("ressources/BitPap.ttf");
    win->text = sfText_create();
    win->text_pos.x = 400;
    win->text_pos.y = 400;
    sfText_setFont(win->text, win->font);
    sfText_setString(win->text, "Return to menu");
    sfText_setCharacterSize(win->text, 50);
    sfText_setColor(win->text, sfWhite);
    sfText_setPosition(win->text, win->text_pos);
    sfSprite_setScale(win->sprite.sprite, win->sprite.scale);
    sfSprite_setTexture(win->sprite.sprite, win->sprite.texture, sfFalse);
}

void init_win(win_obj_t *win, window_obj_t *window)
{
    win->win_txt.font = sfFont_createFromFile("ressources/BitPap.ttf");
    win->win_txt.text = sfText_create();
    win->win_txt.pos.x = 200;
    win->win_txt.pos.y = 200;
    sfText_setFont(win->win_txt.text, win->win_txt.font);
    sfText_setString(win->win_txt.text, "You've passed this level!");
    sfText_setCharacterSize(win->win_txt.text, 80);
    sfText_setColor(win->win_txt.text, sfWhite);
    sfText_setPosition(win->win_txt.text, win->win_txt.pos);
    init_return_button(&win->menu_button);
}

int analyse_win_events(win_obj_t *win, window_obj_t *window)
{
    sfFloatRect return_box =
    sfSprite_getGlobalBounds(win->menu_button.sprite.sprite);

    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        window->index = 0;
        init_menu(&window->menu, &window->clock, window);
    }
    if (sfFloatRect_contains(&return_box, window->event.mouseButton.x,
    window->event.mouseButton.y)) {
        window->index = 0;
        init_menu(&window->menu, &window->clock, window);
    }
}

void anim_win_button(button_t *win, sfVector2i mouse,
    sfRenderWindow **window)
{
    sfFloatRect box = sfSprite_getGlobalBounds(win->sprite.sprite);

    if (sfFloatRect_contains(&box, mouse.x, mouse.y))
        sfRenderWindow_drawText(*window, win->text, NULL);
    sfSprite_setPosition(win->sprite.sprite, win->sprite.pos);
    sfRenderWindow_drawSprite(*window, win->sprite.sprite, NULL);
}

void win(window_obj_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        analyse_win_events(&window->win, window);
    }
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    anim_win_button(&window->win.menu_button, mouse, &window->window);
    sfRenderWindow_drawText(window->window, window->win.win_txt.text, NULL);
}
