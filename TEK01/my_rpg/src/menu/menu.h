/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** menu
*/

#include "../../include/include.h"

#ifndef MENU_H_
#define MENU_H_
#define PLAY_BTN "assets/menu/play.png"
#define SETTINGS_BTN "assets/menu/settings.png"
#define BACK_BTN "assets/menu/back.png"
#define MAP "assets/menu/map.png"
#define MUSIC_BTN "assets/menu/button_music.png"
#define MUSIC_OFF_BTN "assets/menu/button_music_off.png"
#define TABLE_IMG "assets/menu/table.png"
#define MINUS_BTN "assets/menu/button_minus.png"
#define PLUS_BTN "assets/menu/button_plus.png"
#define LOAD_BAR "assets/menu/load_bar.png"
#define MUSIC_TITLE "assets/menu/music.png"
#define DISPLAY_TITLE "assets/menu/display.png"
#define HOW_TO_PLAY "assets/menu/howtoplay.png"
#define HTP_BTN "assets/menu/howtoplaybutton.png"

void run_menu(window_t *window);
void event_menu(window_t *window);
void init_menu(window_t *window);
void init_settings(window_t *window);
void run_settings(window_t *window);
void event_settings(window_t *window);
void run_videostg(window_t *window);
void init_videostg(window_t *window);
void event_videostg(window_t *window);
void music_bar_actualise(window_t *window);
void sound_bar_actualise(window_t *window);
void run_howtoplay(window_t *window);
void event_howtoplay(window_t *window);
void init_howtoplay(window_t *window);

#endif /* !MENU_H_ */
