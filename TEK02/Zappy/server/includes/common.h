/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** common
*/

#ifndef COMMON_H_
    #define COMMON_H_

typedef enum {
    IA_USER,
    GUI_USER,
    ALL
} Permission;

char **concat_words(char *str, char *separator);
int number_of_words(char *str, char *separator);

#endif /* !COMMON_H_ */
