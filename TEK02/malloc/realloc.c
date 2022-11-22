/*
** EPITECH PROJECT, 2022
** B-PSU-400-STG-4-1-malloc-thomas.koebel
** File description:
** realloc
*/

#include "malloc.h"

void *realloc(void *p, size_t size)
{
    memory_block_t found_block = NULL;
    memory_block_t new_ptr = NULL;
    void *newp = NULL;

    if (!p)
        return (malloc(size));
    if (!valid_address(p))
        return (NULL);
    found_block = get_block(p);
    if (alignpower2(size) <= found_block->size)
        return (p);
    newp = malloc(size);
    if (!newp)
        return (NULL);
    new_ptr = get_block(newp);
    for (int i = 0; i < found_block->size; i++)
        new_ptr->data[i] = found_block->data[i];
    found_block->free = 1;
    return (newp);
}

void *reallocarray(void *ptr, size_t memb, size_t size)
{
    if (size > 0 && memb > (4294967295 / size))
        return (NULL);
    return (realloc(ptr, memb * size));
}