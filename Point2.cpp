#include "Point2.hpp"

// Constructeurs
Point2::Point2() : x(0.0f), y(0.0f) {}

Point2::Point2(float x, float y) : x(x), y(y) {}

// Accesseurs
float Point2::getX() const {
    return x;
}

float Point2::getY() const {
    return y;
}

// Setters
void Point2::setX(float x) {
    this->x = x;
}

void Point2::setY(float y) {
    this->y = y;
}

// Méthodes
void Point2::print() const {
    std::cout << "{" << x << ", " << y << "}" << std::endl;
}

Vector2 Point2::operator-(const Point2& p) const {
    return Vector2(x - p.x, y - p.y);
}

Point2 Point2::operator+(const Vector2& v) const {
    return Point2(x + v.getX(), y + v.getY());
}