/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** pause
*/

#include "../../include/include.h"

#ifndef PAUSE_H_
#define PAUSE_H_

#define PLAY_BTN "assets/menu/play.png"
#define SETTINGS_BTN "assets/menu/settings.png"
#define BACK_BTN "assets/menu/back.png"
#define MAP "assets/menu/map.png"
#define TABLE_IMG "assets/menu/table.png"

void init_pause(window_t *window);
void run_pause(window_t *window);
void event_pause(window_t *window);

#endif /* !PAUSE_H_ */
