/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** Centipede
*/

#include "Centipede.hpp"

namespace arcade {

    Centipede::Centipede()
    {
        srand((unsigned) time(0));
        _matrix = Matrix(Vector(34, 22), _map);
        addObstacles();
    }

    Centipede::~Centipede()
    {
    }

    void Centipede::addObstacles()
    {
        int randomRows = 0;
        int randomCols = 0;

        for (int nbrObstacles = 0; nbrObstacles < 15;) {
            randomRows = (rand() % 19) + 1;
            randomCols = (rand() % 31) + 1;
            if (_matrix(randomRows, randomCols) == ' ') {
                _matrix(randomRows, randomCols) = 'O';
                nbrObstacles++;
            }
        }
    }

    void Centipede::eraseShot()
    {
        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++) {
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++) {
                if (_matrix(rows, cols) == '|') {
                    _matrix(rows, cols) = ' ';
                    return ;
                }
            }
        }
    }

    void Centipede::hitHead(int rows, int cols)
    {
        eraseShot();
        for (auto it = list.begin(); it != list.end(); it++) {
            if (it->head[0] == rows && it->head[1] == cols) {
                if (it->body.size() > 0) {
                    auto it2 = it->body.begin();
                    int snakeHead = _matrix(it->head[0], it->head[1]);
                    _matrix(it->head[0], it->head[1]) = 'O';
                    _matrix((it2->begin())[0], (it2->begin())[1]) = snakeHead;
                    it->head[0] = (it2->begin())[0];
                    it->head[1] = (it2->begin())[1];
                    it->body.pop_front();
                } else {
                    _matrix(it->head[0], it->head[1]) = ' ';
                    list.erase(it);
                }
                return;
            }
        }
    }

    void Centipede::hitbody(int rows, int cols)
    {
        int nbrDelete = 0;
        eraseShot();
        for (auto it = list.begin(); it != list.end(); it++) {
            nbrDelete = it->body.size();
            for (auto it2 = it->body.begin(); it2 != it->body.end(); it2++, nbrDelete--) {
                if (it2->begin()[0] == rows && it2->begin()[1] == cols) {
                    Entity cent;
                    _matrix((it2->begin())[0], (it2->begin())[1]) = 'O';
                    int prevCols = (it2->begin())[1];
                    it2++;
                    if (it2 == it->body.end()) {
                        it->body.pop_back();
                        return;
                    }
                    if ((it2->begin())[1] > prevCols)
                        _matrix((it2->begin())[0], (it2->begin())[1]) = '<';
                    else
                        _matrix((it2->begin())[0], (it2->begin())[1]) = '>';
                    cent.head = {(it2->begin())[0], (it2->begin())[1]};
                    it2++;
                    for (; it2 != it->body.end(); it2++)
                        cent.body.push_back({it2->begin()[0], it2->begin()[1]});
                    for (; nbrDelete > 0; nbrDelete--)
                        it->body.pop_back();
                    list.push_back(cent);
                    return;
                }
            }
        }
    }

    void Centipede::moveShot()
    {
        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++) {
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++) {
                if (_matrix(rows, cols) == '|' ) {
                    _matrix(rows, cols) = ' ';
                    switch(_matrix(rows - 1, cols)) {
                            case '#':
                                break;
                            case '<':
                                hitHead(rows - 1, cols);
                            case '>':
                                hitHead(rows - 1, cols);
                                break;
                            case 'O':
                                _matrix(rows - 1, cols) = '0';
                                break;
                            case '0':
                                _matrix(rows - 1, cols) = '8';
                                break;
                            case '8':
                                _matrix(rows - 1, cols) = 'o';
                                break;
                            case 'o':
                                _matrix(rows - 1, cols) = 'c';
                                break;
                            case 'c':
                                _matrix(rows - 1, cols) = ' ';
                                break;
                            case '@':
                                hitbody(rows - 1, cols);
                                break;
                            default:
                                _matrix(rows - 1, cols) = '|';
                                break;
                        }
                    return ;
                }
            }
        }
    }

    void Centipede::movePlayerLeft()
    {
        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++) {
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++) {
                if (_matrix(rows, cols) == 'A' && _matrix(rows, cols - 1) == ' ') {
                    _matrix(rows, cols) = ' ';
                    _matrix(rows, cols - 1) = 'A';
                    return ;
                }
            }
        }
    }

    void Centipede::movePlayerRight()
    {
        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++) {
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++) {
                if (_matrix(rows, cols) == 'A' && _matrix(rows, cols + 1) == ' ') {
                    _matrix(rows, cols) = ' ';
                    _matrix(rows, cols + 1) = 'A';
                    return ;
                }
            }
        }
    }

    void Centipede::movePlayerUp()
    {
        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++) {
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++) {
                if (_matrix(rows, cols) == 'A' && _matrix(rows - 1, cols) == ' ' && (float)(_matrix.getRows() - rows) < (float)(_matrix.getRows() * 0.2)) {
                    _matrix(rows, cols) = ' ';
                    _matrix(rows - 1, cols) = 'A';
                    return ;
                }
            }
        }
    }

    void Centipede::movePlayerDown()
    {
        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++) {
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++) {
                if (_matrix(rows, cols) == 'A' && _matrix(rows + 1, cols) == ' ') {
                    _matrix(rows, cols) = ' ';
                    _matrix(rows + 1, cols) = 'A';
                    return ;
                }
            }
        }
    }

    bool Centipede::hasShot()
    {
        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++)
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++)
                if (_matrix(rows, cols) == '|')
                    return true;
        return false;
    }

    void Centipede::shoot()
    {
        if (hasShot() == false) {
            for (std::size_t rows = 0; rows < _matrix.getRows(); rows++)
                for (std::size_t cols = 0; cols < _matrix.getCols(); cols++)
                    if (_matrix(rows, cols) == 'A') {
                        switch(_matrix(rows - 1, cols)) {
                            case '<':
                                hitHead(rows - 1, cols);
                                break;
                            case '>':
                                hitHead(rows - 1, cols);
                                break;
                            case 'O':
                                _matrix(rows - 1, cols) = '0';
                                break;
                            case '0':
                                _matrix(rows - 1, cols) = '8';
                                break;
                            case '8':
                                _matrix(rows - 1, cols) = 'o';
                                break;
                            case 'o':
                                _matrix(rows - 1, cols) = 'c';
                                break;
                            case 'c':
                                _matrix(rows - 1, cols) = ' ';
                                break;
                            case '@':
                                hitbody(rows - 1, cols);
                            default:
                                _matrix(rows - 1, cols) = '|';
                                break;
                        }
                    }
        }
    }

    int Centipede::listen(std::shared_ptr<arcade::Event> event)
    {
        if (event == nullptr)
            return 0;
        if (event->getValue()[0] == Event::AKEY_LEFT)
            movePlayerLeft();
        else if (event->getValue()[0] == Event::AKEY_RIGHT)
            movePlayerRight();
        else if (event->getValue()[0] == Event::AKEY_UP)
            movePlayerUp();
        else if (event->getValue()[0] == Event::AKEY_DOWN)
            movePlayerDown();
        else if (event->getValue()[0] == Event::AKEY_SPACE)
            shoot();
        return 0;
    }

    void Centipede::cleanMap()
    {
        int check = 0;
        for (std::size_t rows = 0; rows < _matrix.getRows(); rows++) {
            for (std::size_t cols = 0; cols < _matrix.getCols(); cols++) {
                if (_matrix(rows, cols) == '@') {
                    check = 1;
                    for (auto it = list.begin(); it != list.end(); it++)
                        for (auto it2 = it->body.begin(); it2 != it->body.end(); it2++)
                            if ((size_t)it2->begin()[0] == rows && (size_t)it2->begin()[1] == cols)
                                check = 2;
                }
                if (_matrix(rows, cols) == '<' || _matrix(rows, cols) == '>') {
                    check = 1;
                    for (auto it = list.begin(); it != list.end(); it++)
                        if ((size_t)it->head[0] == rows && (size_t)it->head[1] == cols)
                            check = 2;
                }
                if (check == 1)
                    _matrix(rows, cols) = ' ';
                check = 0;
            }
        }
    }

    int Centipede::moveCentipedesSecond(std::list<Entity>::iterator it, int currentRows, int currentCols, int add)
    {
        int rows = 0;
        int cols = 0;
        int pastRows = 0;
        int pastCols = 0;

        if (_matrix(currentRows, currentCols) == ' ' || _matrix(currentRows, currentCols) == '|') {
            if (_matrix(currentRows, currentCols) == '|') {
                hitHead(it->head[0], it->head[1]);
                for (auto it2 = it->body.begin(); it2 != it->body.end(); it2++) {
                    if ((it2->begin())[0] != 0)
                        _matrix((it2->begin())[0], (it2->begin())[1]) = '@';
                    else {
                        (it2->begin())[0] += 1;
                        return 0;
                    }
                }
            }
            else {
                pastRows = it->head[0];
                pastCols = it->head[1];
                if (add == 0) {
                    it->head[1] += 1;
                    _matrix(currentRows, currentCols) = '>';
                } else if (add == 1) {
                    it->head[1] -= 1;
                    _matrix(currentRows, currentCols) = '<';
                }
                for (auto it2 = it->body.begin(); it2 != it->body.end(); it2++) {
                    if (pastRows != 0) {
                        rows = (it2->begin())[0];
                        cols = (it2->begin())[1];
                        _matrix(pastRows, pastCols) = '@';
                        (it2->begin())[0] = pastRows;
                        (it2->begin())[1] = pastCols;
                        pastRows = rows;
                        pastCols = cols;
                    } else {
                        (it2->begin())[0] += 1;
                        return 0;
                }
            }
            }
        } else if (_matrix(currentRows, currentCols) == 'A') {
            it = list.erase(it);
            return 1;
        } else {
            pastRows = it->head[0];
            pastCols = it->head[1];
            if (_matrix(it->head[0], it->head[1]) == '>' && _matrix(it->head[0] + 1, it->head[1]) == ' ')
                _matrix(it->head[0] + 1, it->head[1]) = '<';
            else if (_matrix(it->head[0] + 1, it->head[1]) == ' ')
                _matrix(it->head[0] + 1, it->head[1]) = '>';
            else if (_matrix(it->head[0] + 1, it->head[1]) == '#') {
                it = list.erase(it);
                return 0;
            } else
                return 0;
            it->head[0] += 1;
            for (auto it2 = it->body.begin(); it2 != it->body.end(); it2++) {
                if (pastRows != 0) {
                    rows = (it2->begin())[0];
                    cols = (it2->begin())[1];
                    _matrix(pastRows, pastCols) = '@';
                    (it2->begin())[0] = pastRows;
                    (it2->begin())[1] = pastCols;
                    pastRows = rows;
                    pastCols = cols;
                } else {
                    (it2->begin())[0] += 1;
                    return 0;
                }
            }
            return 0;
        }
        return 0;
    }

    int Centipede::decideMovement(std::list<Entity>::iterator it)
    {
        switch (_matrix(it->head[0], it->head[1])) {
            case '<':
                if (moveCentipedesSecond(it, it->head[0], it->head[1] - 1, 1) == 1) return 1;
                cleanMap();
                if (list.size() == 0)
                    return 0;
                break;
            case '>':
                if (moveCentipedesSecond(it, it->head[0], it->head[1] + 1, 0) == 1) return 1;
                cleanMap();
                if (list.size() == 0)
                    return 0;
                break;
        }
        return 0;
    }

    int Centipede::moveCentipedes()
    {
        int randomNbr = 0;

        randomNbr = (rand() % 2) + 1;
        for (auto it = list.begin(); it != list.end();) {
            auto next = std::next(it);
            if (it->body.size() > 0) {
                if (it->body.begin()->begin()[0] != 0) {
                    if (decideMovement(it) == 1) return 1;
                } else {
                    if (randomNbr == 1)
                        _matrix(it->head[0], it->head[1]) = '>';
                    else
                        _matrix(it->head[0], it->head[1]) = '<';
                    (it->body.begin()->begin())[0] += 1;
                }
            } else
                if (decideMovement(it) == 1) return 1;
            it = next;
            if (it == list.end())
                return 0;
        }
        return 0;
    }

    void Centipede::createCentipede()
    {
        Entity cent;
        cent.head = {1, 16};
        cent.body.push_back({0, 16});
        cent.body.push_back({0, 16});
        cent.body.push_back({0, 16});
        cent.body.push_back({0, 16});
        cent.body.push_back({0, 16});
        cent.body.push_back({0, 16});
        cent.body.push_back({0, 16});
        cent.body.push_back({0, 16});
        cent.body.push_back({0, 16});
        cent.body.push_back({0, 16});
        list.push_back(cent);
    }

    Centipede::Entity::Entity()
    {
    }

    Centipede::Entity::~Entity()
    {
    }

    int Centipede::update(float time_elapsed, std::function<void()>)
    {
        int randomNbr = 0;

        if (list.size() == 0) {
            randomNbr = (rand() % 5) + 1;
            if (randomNbr == 3)
                createCentipede();
        }
        moveShot();
        if (list.size() > 0) {
            centipedeMovement += 1;
            if (centipedeMovement >= 10) {
                if (moveCentipedes() == 1) return 1;
                centipedeMovement = 0;
            }
        }
        return 0;
    }

    Matrix Centipede::getMatrix() const
    {
        return _matrix;
    }

    std::vector<std::shared_ptr<Property>> Centipede::getProperties() const
    {
        return _props;
    }
    
    void Centipede::reset()
    {
        list.clear();
        srand((unsigned)time(0));
        _matrix = Matrix(Vector(34, 22), _map);
        addObstacles();
    }
}
