/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thibaut.ruscher
** File description:
** convert_big_endian
*/

#include "../include/header.h"

uint64_t convert_big_endian_tall(uint64_t number)
{
    return (((number & 0xff00000000000000) >> 56) |
    ((number & 0x00ff000000000000) >> 40) |
    ((number & 0x0000ff0000000000) >> 24) |
    ((number & 0x000000ff00000000) >> 8) |
    ((number & 0x00000000ff000000) << 8) |
    ((number & 0x0000000000ff0000) << 24) |
    ((number & 0x000000000000ff00) << 40) |
    ((number & 0x00000000000000ff) << 56));
}

uint32_t convert_big_endian_small(uint32_t number)
{
    return (
        ((number & 0x000000ff) << 24) |
        ((number & 0x0000ff00) << 8) |
        ((number & 0x00ff0000) >> 8) |
        ((number & 0xff000000) >> 24)
    );
}

uint16_t convert_big_endian_tiny(uint16_t number)
{
    return (
        ((number & 0x00ff) << 8) |
        ((number & 0xff00) >> 8)
    );
}