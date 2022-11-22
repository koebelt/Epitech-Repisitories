/*
** EPITECH PROJECT, 2022
** indie
** File description:
** FillMap
*/

#include "Pattern.hpp"
#include <iostream>
#include <cstdlib>

/**
** @author Thibaut
**
** @brief This function is used to check if pattern can be insert in map
** @param Matrix current pattern
** @param x X position to insert into
** @param y Y position to insert into
** @param map Map
**
** @return if can insert or not
**/
bool canInsertPattern(istudio::Matrix pattern, int x, int y, istudio::Matrix &map)
{
    if (pattern.getRows() > map.getRows() || pattern.getCols() > map.getCols())
        return (false);
    for (int r = 0; r < (pattern.getRows() + 2); r++) {
        for (int c = 0; c < (pattern.getCols() + 2); c++) {
            if ((x + (r - 1)) >= map.getRows() || (y + (c - 1)) >= map.getCols())
                return (false);
            if (!map(x + (r - 1), y + (c - 1)) || map(x + (r - 1), y + (c - 1)) != EMPTY)
                return (false);
        }
    }
    return (true);
}

/**
** @author Thibaut
**
** @brief This function is used to try to put a pattern in the map, parcouring all the pos x and y
** @param map map
** @param matrix_pattern pattern to insert
**
** @return if inserted or not
**/
bool tryPutSmallPattern(istudio::Matrix &map, istudio::Matrix matrix_pattern)
{
    for (int i = 0; i < map.getRows(); i++) {
        for (int j = 0; j < map.getCols(); j++) {
            if (canInsertPattern(matrix_pattern, j, i, map)) {
                map.insertMatrix(matrix_pattern, j, i);
                return (true);
            }
        }
    }
    return (false);
}

/**
** @author Thibaut
**
** @brief This function is used to fill the map with smallest patterns (2x2)
** @param pattern current pattern
** @param map map
** @param small_patterns_tested nb small patterns already tested to insert
** @param i nb patterns already inserted from the beginning of the program
**
** @return 1 if need to stop to try to insert small patterns, 0 if need to continue to try
**/
int istudio::Pattern::fillWithSmallPatterns(Pattern &pattern, Matrix &map, int &small_patterns_tested, int &i)
{
    Matrix matrix_pattern = pattern.generateSmallPattern(small_patterns_tested);
    if (tryPutSmallPattern(map, matrix_pattern)) {
        i++;
        small_patterns_tested = 0;
    } else {
        small_patterns_tested++;
        if (small_patterns_tested >= 5)
            return (1);
    }
    return (0);
}

/**
** @author Thibaut
**
** @brief This function is used to fill the map with oneLinePatterns (1x2, 2x1)
** @param map map
**
** @return 1 if need to stop to try to insert oneLinePatterns, 0 if need to continue to try
**/
int istudio::Pattern::fillWithOneLinePatterns(Matrix &map)
{
    istudio::Matrix matrix_pattern(1, 2);
    matrix_pattern(0, 0) = WALL;
    matrix_pattern(0, 1) = WALL;
    if (!tryPutSmallPattern(map, matrix_pattern)) {
        istudio::Matrix matrix_pattern(2, 1);
        matrix_pattern(0, 0) = WALL;
        matrix_pattern(1, 0) = WALL;
        if (!tryPutSmallPattern(map, matrix_pattern))
            return (1);
    }
    return (0);
}

/**
** @author Thibaut
**
** @brief This function is used to fill the map with big patterns (3x2, 2x3)
** @param pattern current pattern
** @param map map
** @param big_patterns_tested nb big patterns already tested to insert
** @param i nb patterns already inserted from the beginning of the program
**
** @return Nothing
**/
void istudio::Pattern::fillWithBigPatterns(Pattern &pattern, Matrix &map, int &big_patterns_tested, int &i)
{
    Matrix matrix_pattern = pattern.generate(3);
    int pos_x = rand() % map.getCols();
    int pos_y = rand() % map.getRows();
    int cmpt = 0;

    while (!canInsertPattern(matrix_pattern, pos_x, pos_y, map)) {
        if (cmpt >= 5000)
            break;
        pos_x = rand() % map.getCols();
        pos_y = rand() % map.getRows();
        cmpt++;
    }
    if (canInsertPattern(matrix_pattern, pos_x, pos_y, map)) {
        map.insertMatrix(matrix_pattern, pos_x, pos_y);
        if (big_patterns_tested < 10)
            big_patterns_tested = 0;
        i++;
    }
}

/**
** @author Thibaut
**
** @brief This function is used to fill map with patterns
** @param map map
**
** @return Nothing
**/
void istudio::Pattern::fillMapWithPatterns(Matrix &map)
{
    int nb_patterns = 30;
    int big_patterns_tested = 0;
    int small_patterns_tested = 0;

    for (int i = 0; i < nb_patterns;) {
        Pattern pattern;

        big_patterns_tested < 10 ? big_patterns_tested++ : 0;
        if (big_patterns_tested >= 10) {
            if (fillWithSmallPatterns(pattern, map, small_patterns_tested, i))
                if (fillWithOneLinePatterns(map))
                    break;
            continue;
        }
        fillWithBigPatterns(pattern, map, big_patterns_tested, i);
    }
}

/**
** @author Paul
**
** @brief This function is used to fill map breakable walls
** @param map map
**
** @return Nothing
**/
void istudio::Pattern::fillBreakableWall(Matrix &map)
{
    auto cleanCross = [&map](Vector position) {
        for (int r = -1; r <= 1; r++) {
            for (int c = -1; c <= 1; c++) {
                if ((r != 0 && c != 0)) continue;
                if (map.isValid(position + Vector(c, r)))
                    map(position.getY() + r, position.getX() + c) = EMPTY;
            }
        }
    };

    for (int r = 0; r < map.getRows(); r++) {
        for (int c = 0; c < map.getCols(); c++) {
            if (map(r, c) != EMPTY) continue;
            map(r, c) = BREAKABLE;
        }
    }
    cleanCross(Vector(0, 0));
    cleanCross(Vector(0, map.getRows() - 1));
    cleanCross(Vector(map.getCols() - 1, 0));
    cleanCross(Vector(map.getCols() - 1, map.getRows() - 1));
}