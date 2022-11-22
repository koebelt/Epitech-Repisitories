/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <string>
#include <iostream>
#include <cmath>

namespace istudio {
    template <typename T>
    class Vector2D {
        public:
            Vector2D(T x, T y) : _x(x), _y(y) {};
            Vector2D(): _x(0), _y(0) {};
            ~Vector2D() = default;

            Vector2D(const Vector2D &cpy) : _x(cpy._x), _y(cpy._y) {};
            T getX() const { return _x; };
            T getY() const { return _y; };
            bool isAbs(T t) const { return std::abs(_x) == t && std::abs(_y) == t; };
            std::string to_string() const { return (std::to_string(_x) + ":" + std::to_string(_y)); };
            Vector2D operator-(Vector2D<T> vec) { return Vector2D<T>(_x - vec.getX(), _y - vec.getY()); };
            Vector2D operator+(Vector2D<T> vec) { return Vector2D<T>(_x + vec.getX(), _y + vec.getY());};
            Vector2D operator*(T factor) { return Vector2D<T>(_x * factor, _y * factor);};
            Vector2D operator*(Vector2D<T> vec) { return Vector2D<T>(_x * vec.getX(), _y * vec.getY());};
            Vector2D &operator=(Vector2D<T> vec) { _x = vec.getX(); _y = vec.getY(); return (*this); };
            Vector2D &operator*=(T vec) { _x *= vec; _y *= vec; return (*this); };
            Vector2D &operator*=(Vector2D<T> vec) { _x *= vec.getX(); _y *= vec.getY(); return (*this); };
            Vector2D &operator+=(Vector2D<T> vec) { _x += vec.getX(); _y += vec.getY(); return (*this); };
            Vector2D &operator-=(Vector2D<T> vec) { _x -= vec.getX(); _y -= vec.getY(); return (*this); };
            bool operator==(const Vector2D<T> vec) const { return(_x == vec.getX() && _y == vec.getY()); };
            bool operator!=(const Vector2D<T> vec) const { return(_x != vec.getX() || _y != vec.getY()); };
            bool operator>(const Vector2D<T> vec) const { return (std::abs(_x - _y) > std::abs(vec.getX() - vec.getY())); };
            bool operator<(const Vector2D<T> vec) const { return (std::abs(_x - _y) < std::abs(vec.getX() - vec.getY())); };
            double diff(Vector2D<T> other) { return std::sqrt(std::pow(other.getX() - _x, 2) + std::pow(other.getY() - _y, 2)); };
            Vector2D<int> floor() { return Vector2D<int>(_x, _y); };
            Vector2D<int> round() { return Vector2D<int>(std::round(_x), std::round(_y)); };
            Vector2D<T> floorn() { return Vector2D<T>(std::floor(std::abs(_x)), std::floor(std::abs(_y))); };
            Vector2D<T> roundn() { return Vector2D<T>(std::round(_x), std::round(_y)); };
            Vector2D<T> abs() { return Vector2D<T>(std::abs(_x), std::abs(_y)); };

            friend std::ostream& operator<<(std::ostream& out, Vector2D<T> const& vector) {
                out << "X: (" << vector.getX() << "), Y: (" << vector.getY() << ")" << std::endl;
                return (out);
            };
        private:
            T _x, _y;
    };

    using Vector = Vector2D<int>;
    using VectorF = Vector2D<double>;
}

#endif /* !VECTOR_HPP_ */
