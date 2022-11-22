/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** common
*/

#ifndef RESSOURCE_H_
#define RESSOURCE_H_

typedef enum {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
} RessourceType;

typedef struct s_ressource {
    RessourceType type;
    double den;
    int quantity;
    char *name;
} Ressource;

static const Ressource _ressources[7] = {
    {FOOD, 0.5, 0, "food"},
    {LINEMATE, 0.3, 0, "linemate"},
    {DERAUMERE, 0.15, 0, "deraumere"},
    {SIBUR, 0.1, 0, "sibur"},
    {MENDIANE, 0.1, 0, "mendiane"},
    {PHIRAS, 0.08, 0, "phiras"},
    {THYSTAME, 0.05, 0, "thystame"},
};

#endif /* !RESSOURCE_H_ */
