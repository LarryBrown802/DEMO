#include "Segment2.hpp"

// Constructeurs
Segment2::Segment2() : origin(), direction() {}

Segment2::Segment2(const Point2& origin, const Vector2& direction) 
    : origin(origin), direction(direction) {}

// Accesseurs
Point2 Segment2::getOrigin() const {
    return origin;
}

Vector2 Segment2::getDirection() const {
    return direction;
}

// Méthodes
float Segment2::length() const {
    return direction.norm();
}

IntersectionStatus Segment2::intersect(const Segment2& r, Point2& p) const {
    Point2 oa = getOrigin();
    Point2 ob = r.getOrigin();
    Vector2 da = getDirection();
    Vector2 db = r.getDirection();
    Vector2 dc = ob - oa;
    
    float det = da.cross(db);
    
    if (det != 0.0f) {
        float u = dc.cross(db) / det;
        float v = dc.cross(da) / det;
        
        if ((u >= 0.0f && u <= 1.0f) && (v >= 0.0f && v <= 1.0f)) {
            Vector2 tmp = da * u;
            p = oa + tmp;
            return IntersectionStatus::POINT;
        } else {
            return IntersectionStatus::NON_INTERSECTING;
        }
    } else {
        float st = dc.cross(da);
        
        if (det == 0.0f && st == 0.0f) { // Colinéaires
            float pj = da.dot(da);
            float d1 = dc.dot(da) / pj;
            float d2 = d1 + db.dot(da) / pj;
            
            if (d1 >= 0.0f && d1 <= 1.0f) {
                p = ob;
                return IntersectionStatus::COLINEAR_INTERSECTING;
            } else if (d2 >= 0.0f && d2 <= 1.0f) {
                p = ob + db;
                return IntersectionStatus::COLINEAR_INTERSECTING;
            } else {
                return IntersectionStatus::COLINEAR_NON_INTERSECTING;
            }
        } else if (det == 0.0f && st != 0.0f) {
            return IntersectionStatus::PARALLEL_NON_INTERSECTING;
        }
    }
    
    return IntersectionStatus::NON_INTERSECTING;
}