/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Pattern
*/

#include <cstdlib>
#include <vector>
#include <iostream>
#include <utility>
#include "../../utils/Matrix.hpp"

#ifndef PATTERN_HPP_
#define PATTERN_HPP_

namespace istudio {
    class Pattern {
        public:
            Matrix generate(int dimension);
            Matrix generateSmallPattern(int choice);
            static int fillWithSmallPatterns(Pattern &pattern, Matrix &map, int &small_patterns_tested, int &i);
            static int fillWithOneLinePatterns(Matrix &map);
            static void fillWithBigPatterns(Pattern &pattern, Matrix &map, int &big_patterns_tested, int &i);
            static void fillMapWithPatterns(Matrix &map);
            static void fillBreakableWall(Matrix &map);
        protected:
        private:
            static void one_bloc(Matrix &matrix, int nb, int line, int dimension);
            static void two_bloc(Matrix &matrix, int nb, int line, int dimension);
            static void first_case(int length, int width, Matrix &matrix, int nb_blocs, int dimension);
            static void second_case(int length, int width, Matrix &matrix, int nb_blocs, int dimension);
    };
}

#endif /* !PATTERN_HPP_ */
