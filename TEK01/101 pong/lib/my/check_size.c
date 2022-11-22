/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-finalstumper-taha-idriss.elakramine
** File description:
** check_size
*/

#include <unistd.h>
#include "my.h"
#include <stdlib.h>

unsigned char check_size(long x, long y)
{
    if (x < 1 || y < 1 || !are_valid_ints(x, y)) {
        write(2, "Invalid size\n", 13);
        return (1);
    }
    return (0);
}