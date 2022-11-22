/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** Matrix
*/

#ifndef MATRIX_HPP_
#define MATRIX_HPP_
#include "./ErrorManager.hpp"
#include "./Vector.hpp"
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

namespace arcade
{
    class Matrix
    {
    public:
        Matrix() = default;
        Matrix(Vector size, const std::string map) : _size(size)
        {
            for (int y = 0; y < _size.getY(); y++)
            {
                std::vector<std::size_t> tmp;
                for (int x = 0; x < _size.getX(); x++)
                    tmp.push_back(map[x + (y * size.getX())]);
                _matrix.push_back(tmp);
            }
        };
        ~Matrix() = default;

        std::size_t &operator()(std::size_t i, std::size_t j) { return _matrix[i][j]; };
        std::size_t &operator()(Vector vector) { return _matrix[vector.getY()][vector.getX()]; };
        std::vector<std::size_t> &operator[](std::size_t i) { return _matrix[i]; };

        void apply(std::function<void(Vector)> fn)
        {
            for (int y = 0; y < _size.getY(); y++)
                for (int x = 0; x < _size.getX(); x++)
                    fn(Vector(x, y));
        }

        void clear(char clear_symbol = ' ')
        {
            for (int y = 0; y < _size.getY(); y++)
                for (int x = 0; x < _size.getX(); x++)
                    if (std::find(_fixed.begin(), _fixed.end(), _matrix[y][x]) == _fixed.end())
                        _matrix[y][x] = clear_symbol;
        }

        void addFixed(std::size_t n) { _fixed.push_back(n); };

        std::size_t getRows() const { return _size.getY(); };
        std::size_t getCols() const { return _size.getX(); };

    protected:
    private:
        Vector _size;
        std::vector<std::size_t> _fixed = {'#', ' '};
        std::vector<std::vector<std::size_t>> _matrix;
    };
}

#endif /* !MATRIX_HPP_ */
