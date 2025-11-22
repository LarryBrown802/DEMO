#include "Vector2.hpp"

// Constructeurs
Vector2::Vector2() : x(0.0f), y(0.0f) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

// Accesseurs
float Vector2::getX() const {
    return x;
}

float Vector2::getY() const {
    return y;
}

// Setters
void Vector2::setX(float x) {
    this->x = x;
}

void Vector2::setY(float y) {
    this->y = y;
}

// Méthodes
float Vector2::norm() const {
    return std::sqrt(x * x + y * y);
}

float Vector2::dot(const Vector2& v) const {
    return x * v.x + y * v.y;
}

float Vector2::cross(const Vector2& v) const {
    return (x * v.y) - (y * v.x);
}

Vector2 Vector2::negate() const {
    return Vector2(-x, -y);
}

// Opérateurs
Vector2 Vector2::operator*(float scalar) const {
    return Vector2(scalar * x, scalar * y);
}

Vector2 Vector2::operator-() const {
    return negate();
}