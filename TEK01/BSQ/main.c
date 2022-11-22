/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** main fonction for BSQ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

char *read_file(char const *filepath)
{
    struct stat var;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &var);
    int ret;
    char *buffer = malloc(sizeof(char) * (var.st_size));

    ret = read(fd, buffer, var.st_size);
    buffer[ret] = '\0';
    return (buffer);
}

int main(int ac, char **av)
{
    char **tab = my_str_to_word_array(read_file(av[1]));

    find(tab);
    for (int i = 1; tab[i]; ++i) {
        write(1, tab[i], my_strlen(tab[i]));
        my_putchar('\n');
    }
}
