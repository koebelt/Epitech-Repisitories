/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Matrix
*/

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <vector>
#include <iostream>

#include "../../utils/CustomError.hpp"
#include "./Vector.hpp"

#define WALL '1'
#define EMPTY '0'
#define BREAKABLE '#'

namespace istudio {
    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class Matrix: Use for game to handle map and by graphic library to render on screen
    **/
    class Matrix {
        public:
            Matrix(int row, int col) : _row(row), _col(col) {
                _matrix = std::vector<std::vector<int>>(row, std::vector<int>(col, EMPTY));
            };
            ~Matrix() = default;

            Matrix &operator=(Matrix matrix) {
                _row = matrix.getRows();
                _col = matrix.getCols();
                _matrix = std::vector<std::vector<int>>(matrix.getRows(), std::vector<int>(matrix.getCols(), 0));
                for (int r = 0; r < _row; r++) {
                    for (int c = 0; c < _col; c++)
                        _matrix[r][c] = matrix(r, c);
                }
                return *this;
            }
            int operator()(int row, int col) const { return _matrix[row][col]; };
            int &operator()(int row, int col) { return _matrix[row][col]; };
            int &operator()(Vector pos) { return _matrix[pos.getY()][pos.getX()]; };
            int operator()(Vector pos) const { return _matrix[pos.getY()][pos.getX()]; };
            int &operator()(VectorF pos) { return _matrix[pos.getY()][pos.getX()]; };
            int operator()(VectorF pos) const { return _matrix[pos.getY()][pos.getX()]; };

            bool isValid(Vector pos, std::vector<int> disallowed = {WALL}) {
                if (pos.getX() < 0 || pos.getY() < 0)
                    return (false);
                if (pos.getX() >= _col || pos.getY() >= _row)
                    return (false);
                for (int i = 0; i < disallowed.size(); i++)
                    if (_matrix[pos.getY()][pos.getX()] == disallowed[i])
                        return (false);
                return (true);
            };

            /**
            ** @author : Paul Gazeau-Rousseau
            **
            ** @brief Function (insertMatrix): Insert a sub matrix inside this one, so a smaller matrix
            ** @param pattern The sub matrix to insert
            ** @param x the x coordinate to insert sub matrix into
            ** @param y the y coordinate to insert sub matrix into
            **
            ** @return bool: insertion has work or not
            **/
            bool insertMatrix(Matrix &pattern, int x, int y)
            {
                if (!canInsertMatrix(pattern, x, y))
                    return (false);
                for (int r = 0; r < pattern.getRows(); r++) {
                    for (int c = 0; c < pattern.getCols(); c++) {
                        if (_matrix[x + r][y + c] != EMPTY)
                            return (false);
                        _matrix[x + r][y + c] = pattern(r, c);
                    }
                }
                return (true);
            };
            unsigned int getRows() const { return _row; };
            unsigned int getCols() const { return _col; };

            friend std::ostream& operator<<(std::ostream& out, Matrix const& matx)
            {
                for (int r = 0; r < matx.getRows(); r++) {
                    for (int c = 0; c < matx.getCols(); c++)
                        out << static_cast<char>(matx(r, c));
                    out << "\n";
                }
                return out;
            }
        protected:
        private:
            std::vector<std::vector<int>> _matrix{};
            int _row, _col;
            /**
            ** @author : Paul Gazeau-Rousseau
            **
            ** @brief Function (canInsertMatrix): Check if we can actually insert a matrix inside this one, so a smaller matrix
            ** @param pattern The sub matrix to insert
            ** @param x the x coordinate to insert sub matrix into
            ** @param y the y coordinate to insert sub matrix into
            **
            ** @return bool: insertion has work or not
            **/
            bool canInsertMatrix(Matrix &pattern, int x, int y)
            {
                if (pattern.getRows() > _row || pattern.getCols() > _col)
                    return (false);
                for (int r = 0; r < pattern.getRows(); r++) {
                    for (int c = 0; c < pattern.getCols(); c++) {
                        if ((x + r) >= _row || (y + c) >= _col)
                            return (false);
                        if (_matrix[x + r][y + c] != EMPTY)
                            return (false);
                    }
                }
                return (true);
            }
    };
}

#endif /* !MATRIX_HPP_ */
