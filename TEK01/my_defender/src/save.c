/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** save
*/

#include "../include/include.h"

char *open_file_in_buffer(char const *filepath)
{
    struct stat var;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &var);
    int ret;
    char *buffer = NULL;

    buffer = malloc(sizeof(char) * (var.st_size + 1));
    while ((ret = read(fd, buffer, var.st_size)) > 0 && buffer[0] != '\0')
        buffer[ret] = '\0';
    close(fd);
    return (buffer);
}

void load_save(player_t *player)
{
    char *raw_data = open_file_in_buffer("save/player_data.txt");
    char **arranged_data = my_str_to_word_array(raw_data);

    player->gold = my_getnbr(arranged_data[0]);
    player->hdv_lvl = my_getnbr(arranged_data[1]);
    player->archer_lvl = my_getnbr(arranged_data[2]);
    player->wizard_lvl = my_getnbr(arranged_data[3]);
    player->inferno_lvl = my_getnbr(arranged_data[4]);
    player->eagle_lvl = my_getnbr(arranged_data[5]);
    player->tesla_lvl = my_getnbr(arranged_data[6]);
}

void write_on_save(char *to_save)
{
    FILE * stream;

    stream = fopen("save/player_data.txt", "w");
    fwrite(to_save, 1, sizeof(char) * my_strlen(to_save), stream);
    fclose(stream);
}

void prepare_save(player_t *player)
{
    char *to_save = my_strcat(my_int_to_str(player->gold), ";");

    to_save = my_strcat(to_save, my_strcat(my_int_to_str(player->hdv_lvl),
    ";"));
    to_save = my_strcat(to_save, my_strcat(my_int_to_str(player->archer_lvl),
    ";"));
    to_save = my_strcat(to_save, my_strcat(my_int_to_str(player->wizard_lvl),
    ";"));
    to_save = my_strcat(to_save, my_strcat(my_int_to_str(player->inferno_lvl),
    ";"));
    to_save = my_strcat(to_save, my_strcat(my_int_to_str(player->eagle_lvl),
    ";"));
    to_save = my_strcat(to_save, my_strcat(my_int_to_str(player->tesla_lvl),
    "\0"));
    write_on_save(to_save);
}