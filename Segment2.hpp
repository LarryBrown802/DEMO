#ifndef SEGMENT2_HPP
#define SEGMENT2_HPP

#include "Point2.hpp"
#include "Vector2.hpp"

enum class IntersectionStatus {
    POINT,
    COLINEAR_INTERSECTING,
    COLINEAR_NON_INTERSECTING,
    PARALLEL_NON_INTERSECTING,
    NON_INTERSECTING
};

class Segment2 {
private:
    Point2 origin;
    Vector2 direction;

public:
    // Constructeur
    Segment2();
    Segment2(const Point2& origin, const Vector2& direction);

    // Accesseurs
    Point2 getOrigin() const;
    Vector2 getDirection() const;

    // Méthodes
    float length() const;
    IntersectionStatus intersect(const Segment2& s, Point2& p) const;
};

#endif // SEGMENT2_HPP