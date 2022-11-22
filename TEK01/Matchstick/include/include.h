/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-thomas.koebel
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define IS_CTRL_D if (getline(&line, &len, stdin) == -1) return (-1);

int	my_getnbr(char const *str);
char *my_int_to_str(int num);
int my_int_len(int n);
int my_strlen(char const *str);
void ai_play(char **tab, int limit);
int is_good_line(char *line, int lines);
int get_matches(char **tab, int limit, int matches_line);
int is_decimal(char *line);
void print_game(char **tab, int size);
int get_good_input(char **tab, int limit, int lines);
char **create_board(int lines);
int find_tab_size(int lines);
int is_possible_move(char **tab, int *nb);
int count_matches(char **tab);

#endif /* !INCLUDE_H_ */