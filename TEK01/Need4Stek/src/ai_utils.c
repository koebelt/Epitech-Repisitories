/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ai_utils
*/

#include "../include/include.h"

char *command(char *cmd)
{
    char *line = NULL;
    char **tab;
    size_t len = 0;

    dprintf(1, cmd);
    getline(&line, &len, stdin);
    tab = my_str_to_tab(line);
    if (!strcmp(tab[tab_len(tab) - 3], "Track Cleared")) {
        command("STOP_SIMULATION\n");
        command("CAR_FORWARD:0\n");
    }
    return (line);
}

int tab_len(char **tab)
{
    int len = 0;

    for (int i = 0; tab[i]; ++i, ++len);
    return (len);
}

float get_single_float(char **raw)
{
    float value = 0.0;
    raw += 3;
    value = atof(raw[0]);

    return (value);
}

float *fill_lidar_data(char **raw)
{
    float *lidar = NULL;
    int len = 0;

    raw += 3;
    for (int i = 0; i < 32; ++i, ++len);
    lidar = malloc(sizeof(float) * len - 1);
    for (int i = 0; i < 32; ++i) {
        lidar[i] = atof(raw[i]);
    }
    return (lidar);
}

void get_lidar(car_t *car)
{
    char *line = NULL;
    char **output = NULL;

    line = command("GET_INFO_LIDAR\n");
    output = my_str_to_tab(line);
    car->lidar = fill_lidar_data(output);
}