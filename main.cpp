#include <cstdlib>
#include <iostream>
#include "Point2.hpp"
#include "Vector2.hpp"
#include "Segment2.hpp"

int main() {
    Point2 p1(0.0f, 0.0f);
    Point2 p2(1.0f, 2.0f);
    Vector2 v1(1.0f, 1.0f);
    Vector2 v2(2.0f, 4.0f);
    
    Segment2 s1(p1, v1);
    Segment2 s2(p2, v2);
    
    // Test d'intersection
    Point2 intersection;
    IntersectionStatus status = s1.intersect(s2, intersection);
    
    std::cout << "Segment 1: origine = ";
    p1.print();
    std::cout << "           direction = (" << v1.getX() << ", " << v1.getY() << ")" << std::endl;
    std::cout << "           longueur = " << s1.length() << std::endl;
    
    std::cout << "\nSegment 2: origine = ";
    p2.print();
    std::cout << "           direction = (" << v2.getX() << ", " << v2.getY() << ")" << std::endl;
    std::cout << "           longueur = " << s2.length() << std::endl;
    
    std::cout << "\nStatut d'intersection: ";
    switch(status) {
        case IntersectionStatus::POINT:
            std::cout << "POINT à ";
            intersection.print();
            break;
        case IntersectionStatus::COLINEAR_INTERSECTING:
            std::cout << "COLINEAR_INTERSECTING" << std::endl;
            break;
        case IntersectionStatus::COLINEAR_NON_INTERSECTING:
            std::cout << "COLINEAR_NON_INTERSECTING" << std::endl;
            break;
        case IntersectionStatus::PARALLEL_NON_INTERSECTING:
            std::cout << "PARALLEL_NON_INTERSECTING" << std::endl;
            break;
        case IntersectionStatus::NON_INTERSECTING:
            std::cout << "NON_INTERSECTING" << std::endl;
            break;
    }
    
    return EXIT_SUCCESS;
}