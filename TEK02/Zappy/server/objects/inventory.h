/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #define _GNU_SOURCE

    #include <sys/queue.h>
    #include "../system/object.h"
    #include "../includes/prerequisite.h"
    #include "./ressource.h"
    #include <stdio.h>

typedef struct {
    Class   base;
    Ressource ressource[7];
} InventoryClass;

void inventory_ctor(InventoryClass *this, va_list *args);
void inventory_dtor(InventoryClass *this);
char *inventory_str(InventoryClass *obj);

char *inventory_display(InventoryClass *this);

static const InventoryClass _inventorydescription = {
    (Class) {
        .__size__ = sizeof(InventoryClass),
        .__name__ = "Inventory",
        .__ctor__ = (ctor_t)&inventory_ctor,
        .__dtor__ = (dtor_t)&inventory_dtor,
        .__str__ = (to_string_t)&inventory_str,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL,
        .__functions__ = {
            inventory_display
        }
    },
    .ressource = {0}
};

static const Class *Inventory = (const Class *)&_inventorydescription;

#define Inventroy_display(o) ((char *(*)(InventoryClass *)) \
find(o, 0))(o)

#endif /* !INVENTORY_H_ */
