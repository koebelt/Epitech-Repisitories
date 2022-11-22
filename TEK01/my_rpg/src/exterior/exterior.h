/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** map
*/

#include "../../include/include.h"
#include "../inventory/inventory.h"

#ifndef MAP_H_
#define MAP_H_

#define MAP_TEXT "assets/map/map3.png"
#define PLAYER_TEXT "assets/wizard/mage_horse.png"
#define PLAYER_SPEED 1.5
#define WALL_COLOR 135797247
#define WATER_COLOR (sfColor){0, 153, 219, 1}
#define NPCS_TEXT "assets/Npcs/Generic_Male.png"
#define SCROLL_TEXT "assets/Quest/quest_scroll.png"
#define EXCL_TEXT "assets/Quest/exclamation_mark.png"
#define QUES_TEXT "assets/Quest/question_mark.png"
#define QUES_COMP_TEXT "assets/Quest/question_mark_complete.png"
#define FONT_PATH "assets/Fonts/Pixellari.ttf"

void init_map(map_t *map, window_t *window);
void run_map(map_t *map, window_t *window);
void init_exterior(window_t *window);
void run_exterior(window_t *window);
void exterior_events(window_t *window);
void init_player_ext(player_ext_t *player, window_t *window);
void animate_player_ext(player_ext_t *player, window_t *window);
void player_ext_mvnt(player_ext_t *player, window_t *window);
void move_player_ext(player_ext_t *player, window_t *window, int x, int y);
void quest_log(window_t *window);
void show_quest_log(window_t *window);
void updating_indicator(quest_t *quest);
void init_first_quest(window_t *window, quest_t *quest);
void init_second_quest(window_t *window, quest_t *quest);
void init_third_quest(window_t *window, quest_t *quest);
void init_fourth_quest(window_t *window, quest_t *quest);
void init_npcs_with_quest(npcs_with_quest_t *npcs, window_t *window);
void init_entrances(map_t *map, window_t *window);
void entrance_events(player_ext_t *player, map_t *map, window_t *window);
void disp_entrances(map_t *map, window_t *window);

#endif /* !MAP_H_ */
