/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-thomas.koebel
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <curses.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <malloc.h>
#include <sys/sysmacros.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/wait.h>
#include <signal.h>

typedef struct pos {
    int x;
    int y;
} pos_t;

char **read_map(char const *path);
char **my_str_to_word_array(char const *str, char *separators);
int is_in_str(char c, char *str);
int my_strlen(char const *str);
void mv_left(char **map, int key, pos_t p_pos);
void mv_right(char **map, int key, pos_t p_pos);
void mv_up(char **map, int key, pos_t p_pos);
void mv_down(char **map, int key, pos_t p_pos);
int process_key(char **map, char **backup_map, int key, pos_t p_pos);
int my_strcmp(char const *s1, char const *s2);
void print_map(char **map);
void put_o_in_map(char **map, char **backup_map);
pos_t get_p_pos(char **map);
void reset_map(char **map, char **backup_map);
int is_boxes_stucked(char **map, char **backup_map);
int is_win(char **map, char **backup_map);

#endif /* !INCLUDE_H_ */
