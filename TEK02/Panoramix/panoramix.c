/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-panoramix-thomas.koebel
** File description:
** panoramix
*/

#include "panoramix.h"

static void *fn_druid(pano_t *data)
{
    while (data->is_awake == 1) {
        sem_wait(&data->call_refill);
        data->nb_refills--;
        data->dose_remaining = data->pot_size;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware \
I can only make %d more refills after this one.\n", data->nb_refills);
        if (data->nb_refills == 0) {
            printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
            data->is_awake = -1;
        }
        sem_post(&data->has_refilled);
    }
}

void drink_potion(villager_t *data)
{
    pthread_mutex_lock(data->mutex);
    printf("Villager %d: I need a drink... I see %d servings left.\n",
    data->id, *data->dose_remaining);
    if (*data->dose_remaining == 0) {
        printf("Villager %d: Hey Pano wake up! We need more potion.\n",
        data->id);
        sem_post(data->call_refill);
        sem_wait(data->has_refilled);
    }
    *data->dose_remaining -= 1;
    data->can_fignt = 1;
    pthread_mutex_unlock(data->mutex);
}

static void *fn_villagers(villager_t *data)
{
    while (!data->can_die) {
        if (data->nb_fights == 0) {
            printf("Villager %d: I'm going to sleep now.\n", data->id);
            data->can_die = 1;
            continue;
        } if (data->can_fignt == 0) {
            drink_potion(data);
        } else if (data->nb_fights > 0) {
            data->nb_fights -= 1;
            data->can_fignt = 0;
            printf("Villager %d: Take that roman scum! Only %d left.\n",
            data->id, data->nb_fights);
        }
    }
}

void init_villagers(pano_t *main)
{
    for (int i = 0; i < main->nb_villagers; ++i) {
        printf("Villager %d: Going into battle!\n", i);
        main->villagers[i].nb_fights = main->nb_fights;
        main->villagers[i].id = i;
        main->villagers[i].can_fignt = 0;
        main->villagers[i].dose_remaining = &main->dose_remaining;
        main->villagers[i].mutex = &main->mutex;
        main->villagers[i].can_die = 0;
        main->villagers[i].has_refilled = &main->has_refilled;
        main->villagers[i].call_refill = &main->call_refill;
        pthread_create(&main->villagers[i].thread_villager, NULL,
        (void *)fn_villagers, &main->villagers[i]);
    }
    for (int i = 0; i < main->nb_villagers; ++i)
        pthread_join(main->villagers[i].thread_villager, NULL);
}

int main(int argc, char **argv)
{
    pano_t main;

    if (error_management(argc, argv))
        return (84);
    main.nb_villagers = atoi(argv[1]);
    main.pot_size = atoi(argv[2]);
    main.nb_fights = atoi(argv[3]);
    main.nb_refills = atoi(argv[4]);
    main.villagers = malloc(sizeof(villager_t) * main.nb_villagers);
    main.is_awake = 1;
    main.dose_remaining = main.pot_size;
    pthread_mutex_init(&main.mutex, NULL);
    sem_init(&main.call_refill, 1, 0);
    sem_init(&main.has_refilled, 1, 0);
    printf("Druid: I'm ready... but sleepy...\n");
    pthread_create(&main.thread_druid, NULL, (void *)fn_druid, &main);
    init_villagers(&main);
}