/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-thomas.koebel
** File description:
** main
*/

#include "../include/include.h"


void good_term(char **map)
{
    int map_len = 0;
    int i = 0;

    for (i = 0; map[i]; ++i)
        my_strlen(map[i]) > map_len ? map_len = my_strlen(map[i]) : 0;
    clear();
    mvprintw((LINES / 2), (COLS / 2) - (27 / 2),
    "Your terminal is too small");
    mvprintw((LINES / 2) + 1, (COLS / 2) - (18 / 2),
    "please enlarge it");
    refresh();
    while (map_len > COLS || i > LINES)
        refresh();
}

int main_loop(char **map, char **backup_map)
{
    pos_t p_pos;
    int key = 0;
    int win = 0;

    while (1) {
        good_term(map);
        clear();
        put_o_in_map(map, backup_map);
        print_map(map);
        key = getch();
        p_pos = get_p_pos(map);
        win = process_key(map, backup_map, key, p_pos);
        print_map(map);
        if (is_boxes_stucked(map, backup_map))
            return (1);
        refresh();
        if (win == 1) 
            return (0);
    }
}

int usage(void)
{
    write(1, "UGAGE\n", 7);
    write(1, "\t./my_sokoban map\n", 19);
    write(1, "DESCRIPTION\n", 13);
    write(1, "\tmap file representing the warehouse map, containing ‘#’ \
for walls, ‘P’ for the player, ‘X’ for boxes and ‘O’ for storage \
locations.\n", 148);
    return (0);
}

int main(int ac, char **av)
{
    char **map = NULL;
    char **backup_map = NULL;
    int ret = 0;
    WINDOW *window;

    if (ac != 2)
        return (84);
    if (my_strcmp(av[1], "-h") == 0)
        return (usage());
    map = read_map(av[1]);
    backup_map = read_map(av[1]);
    if (map == NULL || backup_map == NULL)
        return (84);
    window = initscr();
    keypad(window, TRUE);
    ret = main_loop(map, backup_map);
    getch();
    endwin();
    return (ret);
}