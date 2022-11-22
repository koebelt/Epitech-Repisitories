/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-thomas.koebel
** File description:
** include.h
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <sys/sysmacros.h>
#include <errno.h>

#ifndef INCLUDE_H_
#define INCLUDE_H_

void my_putchar(char);
char *my_strcat(char *, char *);
int my_printf(char *, ...);
int my_strlen(char *);
void disp_folder(char *);
void disp_folders(char *, int, char **);
int base_disp(int , char **);
int file_exists(const char *);
int folder_exists(const char *);
char *get_name(char *);
void disp_long_folder(char *);
void long_disp(char *, int);
void long_disp_many(int, char **);
char *get_user(struct stat);
char *get_group(struct stat);
int my_nbr_len(int);

#endif /* INCLUDE_H_ */
