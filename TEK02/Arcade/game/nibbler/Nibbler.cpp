/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

arcade::Nibbler::Nibbler()
{
    srand((unsigned) time(0));
    list.push_back({9, 11});
    list.push_back({9, 10});
    list.push_back({9, 9});
    _matrix = Matrix(Vector(23, 19), _map);
}

arcade::Nibbler::~Nibbler()
{
}

namespace arcade
{

    void Nibbler::newFruit()
    {
        int randomCols = 0;
        int randomRows = 0;

        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++) {
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++) {
                if (_matrix(rows, cols) == 'o')
                    return;
            }
        }
        while (true) {
            randomRows = (rand() % (_matrix.getRows() - 1)) + 1;
            randomCols = (rand() % (_matrix.getCols() - 1)) + 1;
            if (_matrix(randomRows, randomCols) == ' ') {
                _matrix(randomRows, randomCols) = 'o';
                return;
            }
        }
    }

    void Nibbler::changeHead(std::string str)
    {
        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++) {
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++) {
                if (_matrix(rows, cols) == '>' || _matrix(rows, cols) == '<' || _matrix(rows, cols) == '^' || _matrix(rows, cols) == 'v') {
                    if (str == "right") {
                        switch (_matrix(rows, cols)) {
                            case '<':
                                _matrix(rows, cols) = '^';
                                break;
                            case '^':
                                _matrix(rows, cols) = '>';
                                break;
                            case '>':
                                _matrix(rows, cols) = 'v';
                                break;
                            case 'v':
                                _matrix(rows, cols) = '<';
                                break;
                        }
                    } else {
                        switch (_matrix(rows, cols)) {
                            case '<':
                                _matrix(rows, cols) = 'v';
                                break;
                            case '^':
                                _matrix(rows, cols) = '<';
                                break;
                            case '>':
                                _matrix(rows, cols) = '^';
                                break;
                            case 'v':
                                _matrix(rows, cols) = '>';
                                break;
                        }
                    }
                }
            }
        }
    }

    int Nibbler::listen(std::shared_ptr<arcade::Event> event)
    {
        if (event->getValue()[0] == Event::AKEY_LEFT){
            changeHead("left");
        } else if (event->getValue()[0] == Event::AKEY_RIGHT) {
            changeHead("right");

        }
        return 0;
    }

    void Nibbler::updateBody(int rows, int cols, int nbr)
    {
        int end_rows = 0;
        int end_cols = 0;

        for (auto it = list.begin(); it != list.end(); it++) {
            _matrix((*it)[0], (*it)[1]) = ' ';
        }
        for (auto it = list.begin(); it != list.end(); it++) {
            end_rows = (*it)[0];
            end_cols = (*it)[1];
            (*it) = {rows, cols};
            _matrix(rows, cols) = '@';
            rows = end_rows;
            cols = end_cols;
        }
        if (nbr > 0) {
            list.push_back({end_rows, cols});
            _matrix(end_rows, end_cols) = '@';
        }

    }

    int Nibbler::snakeUp(int rows, int cols)
    {
        if (_matrix(rows - 1, cols) == 'o') {
            _matrix(rows, cols) = ' ';
            _matrix(rows - 1, cols) = '^';
            updateBody(rows, cols, 1);
        } else if (_matrix(rows - 1, cols) == '#' || _matrix(rows - 1, cols) == '@') {
            return 1;
        } else {
            _matrix(rows, cols) = ' ';
            _matrix(rows - 1, cols) = '^';
            updateBody(rows, cols, 0);
        }
        return 0;
    }

    int Nibbler::snakeDown(int rows, int cols)
    {
        if (_matrix(rows + 1, cols) == 'o') {
            _matrix(rows, cols) = ' ';
            _matrix(rows + 1, cols) = 'v';
            updateBody(rows, cols, 1);
        } else if (_matrix(rows + 1, cols) == '#' || _matrix(rows + 1, cols) == '@') {
            return 1;
        } else {
            _matrix(rows, cols) = ' ';
            _matrix(rows + 1, cols) = 'v';
            updateBody(rows, cols, 0);
        }
        return 0;
    }

    int Nibbler::snakeLeft(int rows, int cols)
    {
        if (_matrix(rows, cols - 1) == 'o') {
            _matrix(rows, cols) = ' ';
            _matrix(rows, cols - 1) = '<';
            updateBody(rows, cols, 1);
        } else if (_matrix(rows, cols - 1) == '#' || _matrix(rows, cols - 1) == '@') {
            return 1;
        } else {
            _matrix(rows, cols) = ' ';
            _matrix(rows, cols - 1) = '<';
            updateBody(rows, cols, 0);
        }
        return 0;
    }

    int Nibbler::snakeRight(int rows, int cols)
    {
        if (_matrix(rows, cols + 1) == 'o') {
            _matrix(rows, cols) = ' ';
            _matrix(rows, cols + 1) = '>';
            updateBody(rows, cols, 1);
        } else if (_matrix(rows, cols + 1) == '#' || _matrix(rows, cols + 1) == '@') {
            return 1;
        } else {
            _matrix(rows, cols) = ' ';
            _matrix(rows, cols + 1) = '>';
            updateBody(rows, cols, 0);
        }
        return 0;
    }

    int Nibbler::update(float time_elapsed, std::function<void()>)
    {
        newFruit();
        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++) {
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++) {
                if (_matrix(rows, cols) == '>' || _matrix(rows, cols) == '<' || _matrix(rows, cols) == '^' || _matrix(rows, cols) == 'v') {
                    switch (_matrix(rows, cols)) {
                        case '<' :
                            if (snakeLeft(rows, cols) == 1) return 1;
                            return 0;
                        case '>' :
                            if (snakeRight(rows, cols) == 1) return 1;
                            return 0;
                        case '^' :
                            if (snakeUp(rows, cols) == 1) return 1;
                            return 0;
                        case 'v' :
                            if (snakeDown(rows, cols) == 1) return 1;
                            return 0;
                    }
                }
            }
        }
        return 0;
    }

    Matrix Nibbler::getMatrix() const
    {
        return this->_matrix;
    }
    
    std::vector<std::shared_ptr<Property>> Nibbler::getProperties() const
    {
        return _props;
    }
    
    void Nibbler::reset()
    {
        list.clear();
        srand((unsigned) time(0));
        list.push_back({9, 11});
        list.push_back({9, 10});
        list.push_back({9, 9});
        _matrix = Matrix(Vector(23, 19), _map);
    }
}
