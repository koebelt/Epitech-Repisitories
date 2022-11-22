/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** prerequisite
*/

#ifndef PREREQUISITE_H_
    #define PREREQUISITE_H_

    #include <stdarg.h>
    #include <string.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <netdb.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <regex.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <errno.h>
    #include <uuid/uuid.h>

    #define READ_SIZE 2048

char *itoa(long long nb);
char *my_strcat(char *dest, char *src);
char **concat_words(char *str, char *separator);

#endif /* !PREREQUISITE_H_ */
