#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>

class Vector2 {
private:
    float x, y;

public:
    // Constructeurs
    Vector2();
    Vector2(float x, float y);

    // Accesseurs
    float getX() const;
    float getY() const;

    // Setters
    void setX(float x);
    void setY(float y);

    // Méthodes
    float norm() const;
    float dot(const Vector2& v) const;
    float cross(const Vector2& v) const;
    Vector2 negate() const;

    // Opérateurs
    Vector2 operator*(float scalar) const;
    Vector2 operator-() const;
};

#endif // VECTOR2_HPP