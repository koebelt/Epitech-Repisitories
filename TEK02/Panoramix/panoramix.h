/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-panoramix-thomas.koebel
** File description:
** panoramix
*/

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_

    #include <pthread.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <semaphore.h>
    #include <string.h>
    #include <ctype.h>

typedef struct
{
    int can_die;
    int id;
    int can_fignt;
    int nb_fights;
    int *dose_remaining;
    pthread_t thread_villager;
    pthread_mutex_t *mutex;
    sem_t *call_refill;
    sem_t *has_refilled;
} villager_t;

typedef struct
{
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
    int dose_remaining;
    pthread_t thread_druid;
    villager_t *villagers;
    pthread_mutex_t mutex;
    sem_t call_refill;
    sem_t has_refilled;
    int is_awake;
} pano_t;

int error_management(int ac, char **av);

#endif /* !PANORAMIX_H_ */
