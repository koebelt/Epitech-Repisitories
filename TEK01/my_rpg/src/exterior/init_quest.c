/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** init_quest
*/

#include "exterior.h"

void init_fourth_quest(window_t *window, quest_t *quest)
{
    init_quest(window, &window->ext.npcs.fourth,
    (quest_info_t){0, 0.8, 1, FONT_PATH},
    "En decouvrir plus sur les donjons ");
    quest->question_mark_complete.t_0 = 0.0;
    init_sprite(&quest->question_mark_complete,
    (sprite_info_t){1035, -1035, 0.02, 0, 0, 1200, 2100, QUES_COMP_TEXT},
    window);
    quest->question_mark.t_0 = 0.0;
    init_sprite(&quest->question_mark,
    (sprite_info_t){1035, -1035, 0.02, 0, 0, 1200, 2100, QUES_TEXT}, window);
    quest->exclamation_mark.t_0 = 0.0;
    init_sprite(&quest->exclamation_mark,
    (sprite_info_t){1017, 585, 0.07, 0, 0, 900, 500, EXCL_TEXT}, window);
    quest->npj.t_0 = 0.0;
    init_sprite(&quest->npj, (sprite_info_t){1030, 615, 0.45, 560, 0, 80, 120,
    NPCS_TEXT}, window);
}

void init_third_quest(window_t *window, quest_t *quest)
{
    init_quest(window, &window->ext.npcs.third,
    (quest_info_t){40, 0.8, 5, FONT_PATH}, "Eliminer quelques monstres ! ");
    quest->question_mark_complete.t_0 = 0.0;
    init_sprite(&quest->question_mark_complete,
    (sprite_info_t){1315, -615, 0.02, 0, 0, 1200, 2100, QUES_COMP_TEXT},
    window);
    quest->question_mark.t_0 = 0.0;
    init_sprite(&quest->question_mark,
    (sprite_info_t){1315, -615, 0.02, 0, 0, 1200, 2100, QUES_TEXT}, window);
    quest->exclamation_mark.t_0 = 0.0;
    init_sprite(&quest->exclamation_mark,
    (sprite_info_t){1297, 1005, 0.07, 0, 0, 900, 500, EXCL_TEXT}, window);
    quest->npj.t_0 = 0.0;
    init_sprite(&quest->npj,
    (sprite_info_t){1310, 1035, 0.45, 800, 480, 80, 120, NPCS_TEXT}, window);
}

void init_second_quest(window_t *window, quest_t *quest)
{
    init_quest(window, &window->ext.npcs.second,
    (quest_info_t){40, 0.8, 5, FONT_PATH}, "Tuer des squelettes ! ");
    quest->question_mark_complete.t_0 = 0.0;
    init_sprite(&quest->question_mark_complete,
    (sprite_info_t){1305, -885, 0.02, 0, 0, 1200, 2100, QUES_COMP_TEXT},
    window);
    quest->question_mark.t_0 = 0.0;
    init_sprite(&quest->question_mark,
    (sprite_info_t){1305, -885, 0.02, 0, 0, 1200, 2100, QUES_TEXT}, window);
    quest->exclamation_mark.t_0 = 0.0;
    init_sprite(&quest->exclamation_mark,
    (sprite_info_t){1287, 735, 0.07, 0, 0, 900, 500, EXCL_TEXT}, window);
    quest->npj.t_0 = 0.0;
    init_sprite(&quest->npj,
    (sprite_info_t){1300, 765, 0.45, 320, 480, 80, 120, NPCS_TEXT}, window);
}

void init_first_quest(window_t *window, quest_t *quest)
{
    init_quest(window, &window->ext.npcs.first,
    (quest_info_t){0, 0.8, 1, FONT_PATH}, "Explorer la grotte ");
    quest->question_mark_complete.t_0 = 0.0;
    init_sprite(&quest->question_mark_complete,
    (sprite_info_t){1195, -800, 0.02, 0, 0, 1200, 2100, QUES_COMP_TEXT},
    window);
    quest->question_mark.t_0 = 0.0;
    init_sprite(&quest->question_mark,
    (sprite_info_t){1195, -800, 0.02, 0, 0, 1200, 2100, QUES_TEXT}, window);
    quest->exclamation_mark.t_0 = 0.0;
    init_sprite(&quest->exclamation_mark,
    (sprite_info_t){1177, 820, 0.07, 0, 0, 900, 500, EXCL_TEXT}, window);
    quest->npj.t_0 = 0.0;
    init_sprite(&quest->npj,
    (sprite_info_t){1190, 850, 0.45, 560, 480, 80, 120, NPCS_TEXT}, window);
}