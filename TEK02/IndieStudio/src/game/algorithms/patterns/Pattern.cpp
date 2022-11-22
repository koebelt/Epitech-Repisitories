/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Pattern
*/

#include "Pattern.hpp"

/**
** @author Thibaut
**
** @brief This function is used to create blocs who only contains 1 bloc on the smallest side of the pattern
** @param matrix Pattern's matrix
** @param nb If length > width, nb = 0, otherwise nb = 1 (because the filling method is not the same)
** @param line Correspond to the line to fill when length is superior to the width
**
** @return Nothing
**/
void istudio::Pattern::one_bloc(Matrix &matrix, int nb, int line, int dimension)
{
    int bloc_pos = rand() % dimension;

    if (nb == 0) {
        for (int i = 0; i < dimension; i++) {
            if (i == bloc_pos)
                matrix(line, i) = WALL;
            else
                matrix(line, i) = EMPTY;
        }
    } else {
        for (int i = 0; i < dimension; i++) {
            if (i == bloc_pos)
                matrix(i, line) = WALL;
            else
                matrix(i, line) = EMPTY;
        }
    }
}

/**
** @author Thibaut
**
** @brief This function is used to create blocs who contains 2 blocs on the smallest side of the pattern
** @param matrix Pattern's matrix
** @param nb If length > width, nb = 0, otherwise nb = 1 (because the filling method is not the same)
** @param line Correspond to the line to fill when length is superior to the width
**
** @return Nothing
**/
void istudio::Pattern::two_bloc(Matrix &matrix, int nb, int line, int dimension)
{
    int bloc_pos = rand() % 2;
    int first_pos;
    int second_pos;

    if (bloc_pos == 0) {
        first_pos = 0;
        second_pos = 1;
    } else {
        first_pos = 1;
        second_pos = 2;
    }

    if (nb == 0) {
        for (int i = 0; i < dimension; i++) {
            if (i == first_pos || i == second_pos)
                matrix(line, i) = WALL;
            else
                matrix(line, i) = EMPTY;
        }
    } else {
        for (int i = 0; i < dimension; i++) {
            if (i == first_pos || i == second_pos)
                matrix(i, line) = WALL;
            else
                matrix(i, line) = EMPTY;
        }
    }
}

/**
** @author Thibaut
**
** @brief This function is used to handle pattern generation when the side of the matrix to fill first is the top or the left (depending of the biggest side and the random "start_to_fill").
** @param length Length of the pattern's matrix
** @param width Width of the pattern's matrix
** @param matrix Pattern's matrix
** @param nb_blocs Correspond to the number of blocs of which will be constituted the smallest side of the pattern's matrix
**
** @return Nothing
**/
void istudio::Pattern::first_case(int length, int width, Matrix &matrix, int nb_blocs, int dimension)
{
    if (length > width) {
        for (int i = 0; i < length; i++)
            matrix(0, i) = WALL;
        if (nb_blocs == 1)
            one_bloc(matrix, 0, 1, dimension);
        else if (nb_blocs == 2)
            two_bloc(matrix, 0, 1, dimension);
        else
            for (int i = 0; i < nb_blocs; i++)
                matrix(1, i) = WALL;
    } else {
        for (int i = 0; i < width; i++)
            matrix(i, 0) = WALL;
        if (nb_blocs == 1)
            one_bloc(matrix, 1, 1, dimension);
        else if (nb_blocs == 2)
            two_bloc(matrix, 1, 1, dimension);
        else
            for (int i = 0; i < nb_blocs; i++)
                matrix(i, 1) = WALL;
    }
}

/**
** @author Thibaut
**
** @brief This function is used to handle pattern generation when the side of the matrix to fill first is the bottom or the right (depending of the biggest side and the random "start_to_fill").
** @param length Length of the pattern's matrix
** @param width Width of the pattern's matrix
** @param matrix Pattern's matrix
** @param nb_blocs Correspond to the number of blocs of which will be constituted the smallest side of the pattern's matrix
**
** @return Nothing
**/
void istudio::Pattern::second_case(int length, int width, Matrix &matrix, int nb_blocs, int dimension)
{
    if (length > width) {
        if (nb_blocs == 1)
            one_bloc(matrix, 0, 0, dimension);
        else if (nb_blocs == 2)
            two_bloc(matrix, 0, 0, dimension);
        else
            for (int i = 0; i < nb_blocs; i++)
                matrix(0, i) = WALL;
        for (int i = 0; i < length; i++)
            matrix(1, i) = WALL;
    } else {
        if (nb_blocs == 1)
            one_bloc(matrix, 1, 0, dimension);
        else if (nb_blocs == 2)
            two_bloc(matrix, 1, 0, dimension);
        else
            for (int i = 0; i < nb_blocs; i++)
                matrix(i, 0) = WALL;
        for (int i = 0; i < width; i++)
            matrix(i, 1) = WALL;
    }
}

/**
** @author Thibaut
**
** @brief This function is used to generate a pattern randomly (always with a matrix size of 3x2 or 2x3).
**
** @return It returns the matrix containing the pattern.
**/
istudio::Matrix istudio::Pattern::generate(int dimension)
{
    unsigned int length = rand();
    int nb_blocs = rand();
    int start_to_fill = rand() % 2;

    length = length % 2;
    length = length == 0 ? dimension - 1 : dimension;

    unsigned int width = length == dimension ? dimension - 1 : dimension;

    nb_blocs = nb_blocs % dimension;
    nb_blocs++;

    dimension == 2 ? width = 2, length = 2 : 0;
    Matrix matrix(width, length);

    if (start_to_fill == 0)
        first_case(length, width, matrix, nb_blocs, dimension);
    else
        second_case(length, width, matrix, nb_blocs, dimension);
    return (matrix);
}

istudio::Matrix istudio::Pattern::generateSmallPattern(int choice)
{
    Matrix matrix(2, 2);

    switch (choice) {
        case (0):
            matrix(0, 0) = WALL;
            matrix(1, 0) = WALL;
            matrix(0, 1) = WALL;
            matrix(1, 1) = WALL;
            break;
        case (1):
            matrix(0, 0) = WALL;
            matrix(0, 1) = WALL;
            matrix(1, 0) = WALL;
            matrix(1, 1) = EMPTY;
            break;
        case (2):
            matrix(0, 0) = WALL;
            matrix(0, 1) = WALL;
            matrix(1, 0) = EMPTY;
            matrix(1, 1) = WALL;
        case (3):
            matrix(0, 0) = WALL;
            matrix(0, 1) = EMPTY;
            matrix(1, 0) = WALL;
            matrix(1, 1) = WALL;
        case (4):
            matrix(0, 0) = EMPTY;
            matrix(0, 1) = WALL;
            matrix(1, 0) = WALL;
            matrix(1, 1) = WALL;
    }
    return (matrix);
}
