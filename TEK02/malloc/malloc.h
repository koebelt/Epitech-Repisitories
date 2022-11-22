/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** malloc
*/

#ifndef MALLOC_H_
    #define MALLOC_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #define EXIT_ERROR 84
    #define EXIT_SUCCESS 0
    #define alignpower2(x)(((((x) - 1) >> 2) << 2) + 4)

    #define BLOCK_SIZE (sizeof(struct memory_block))
typedef unsigned long size_t;
typedef struct memory_block *memory_block_t;

struct memory_block {
    size_t size;
    int free;
    struct memory_block *next;
    struct memory_block *prev;
    void *ptr;
    char data[1];
};

extern memory_block_t memory;

void *malloc(size_t size);
void free(void *p);
int valid_address(void *p);
memory_block_t get_block(void *p);
void *realloc(void *p, size_t size);
void *reallocarray(void *ptr, size_t memb, size_t size);
void *calloc(size_t number, size_t size);

#endif /* !MALLOC_H_ */
