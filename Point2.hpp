#ifndef POINT2_HPP
#define POINT2_HPP

#include "Vector2.hpp"
#include <iostream>

class Point2 {
private:
    float x, y;

public:
    // Constructeurs
    Point2();
    Point2(float x, float y);

    // Accesseurs
    float getX() const;
    float getY() const;

    // Setters
    void setX(float x);
    void setY(float y);

    // Méthodes
    void print() const;
    Vector2 operator-(const Point2& p) const;
    Point2 operator+(const Vector2& v) const;
};

#endif // POINT2_HPP