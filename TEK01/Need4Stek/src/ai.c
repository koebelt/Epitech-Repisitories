/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** ai
*/

#include "../include/include.h"

void steer_car_next(car_t *car, int *furthest_pos)
{
    if (car->lidar[0] < 450)
        *furthest_pos += 8;
    else if (car->lidar[31] < 450)
        *furthest_pos -= 8;
    if ((car->lidar[15] + car->lidar[16]) / 2 < 400) {
        if (car->lidar[0] > car->lidar[31])
            *furthest_pos -= 50;
        else
            *furthest_pos += 50;
    }
    *furthest_pos -= 15;
    abs(*furthest_pos) <= 1 ? *furthest_pos = 0 : 0;
}

void steer_car(car_t *car)
{
    int furthest_pos = 0;
    float furthest = 0;
    float angle = 0;
    char buf[256];
    char *full_command = NULL;

    for (int i = 3; i < 29; ++i) {
        if (car->lidar[i] > furthest) {
            furthest = car->lidar[i];
            furthest_pos = i;
        }
    }
    steer_car_next(car, &furthest_pos);
    if (abs(furthest_pos) < 12)
        angle = -0.0125 * furthest_pos;
    else
        angle = -0.015 * furthest_pos;
    gcvt(angle, 2, buf);
    full_command = my_strcat(my_strcat("WHEELS_DIR:", buf), "\n");
    command(full_command);
}

void get_wheels(car_t *car)
{
    char *line = NULL;
    char **output = NULL;

    line = command("GET_CURRENT_WHEELS\n");
    output = my_str_to_tab(line);
    car->wheels = get_single_float(output);
}

void handle_speed(car_t *car)
{
    float moy_center = (car->lidar[15] + car->lidar[16]) / 2;
    int c = moy_center / 150;

    switch (c) {
        case 0: command("CAR_FORWARD:0.015\n");
            break;
        case 1: command("CAR_FORWARD:0.02\n");
            break;
        case 2: command("CAR_FORWARD:0.05\n");
            break;
        case 3: command("CAR_FORWARD:0.1\n");
            break;
        case 4: command("CAR_FORWARD:0.15\n");
            break;
        case 5: command("CAR_FORWARD:0.2\n");
            break;
        case 6: command("CAR_FORWARD:0.3\n");
            break;
        default: command("CAR_FORWARD:0.4\n");
    }
}

int main(void)
{
    car_t car = {0.0, 0.0, NULL};

    command("START_SIMULATION\n");
    command("CAR_FORWARD:0.5\n");
    while (1) {
        get_wheels(&car);
        get_lidar(&car);
        steer_car(&car);
        handle_speed(&car);
    }
    command("STOP_SIMULATION\n");
}