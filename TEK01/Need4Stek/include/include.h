/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-thomas.koebel
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

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
#include <string.h>
#include <time.h>

typedef struct car {
    float speed;
    float wheels;
    float *lidar;
} car_t;

char **my_str_to_tab(char const *str);
char *my_strcat(char *dest, char *src);
char *command(char *cmd);
int tab_len(char **tab);
float get_single_float(char **raw);
float *fill_lidar_data(char **raw);
void get_lidar(car_t *car);

#endif /* !INCLUDE_H_ */