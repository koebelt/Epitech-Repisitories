/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** team
*/

#include "./inventory.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Constructor for Inventory Class
** @param this (InventoryClass*): Pointer on class
** @param args (va_list*): list of argument given by new
**
** @return Nothing
**/
void inventory_ctor(InventoryClass *this, va_list *args)
{
    memcpy(&this->ressource, &_ressources, sizeof(Ressource) * 7);
    this->ressource[FOOD].quantity = 10;
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Destructor for Inventory Class
** @param this (InventoryClass*): Pointer on class
**
** @return Nothing
**/
void inventory_dtor(InventoryClass *this)
{
    memset(&this->ressource, 0, sizeof(Ressource) * 7);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Str function for Inventory Class
** @param this (InventoryClass*): Pointer on class
**
** @return Desired Inventory has string
**/
char *inventory_str(InventoryClass *this)
{
    char *buffer = NULL;

    asprintf(&buffer, "%d %d %d %d %d %d %d",
        this->ressource[0].quantity,
        this->ressource[1].quantity,
        this->ressource[2].quantity,
        this->ressource[3].quantity,
        this->ressource[4].quantity,
        this->ressource[5].quantity,
        this->ressource[6].quantity
    );
    return (buffer);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Display function for Inventory Class
** @param this (InventoryClass*): Pointer on class
**
** @return String corresponding to the display
**/
char *inventory_display(InventoryClass *this)
{
    char *buffer = NULL;

    asprintf(&buffer, "[%s %d, %s %d, %s %d, %s %d, %s %d, %s %d, %s %d]",
        this->ressource[0].name,
        this->ressource[0].quantity,
        this->ressource[1].name,
        this->ressource[1].quantity,
        this->ressource[2].name,
        this->ressource[2].quantity,
        this->ressource[3].name,
        this->ressource[3].quantity,
        this->ressource[4].name,
        this->ressource[4].quantity,
        this->ressource[5].name,
        this->ressource[5].quantity,
        this->ressource[6].name,
        this->ressource[6].quantity
    );
    return (buffer);
}