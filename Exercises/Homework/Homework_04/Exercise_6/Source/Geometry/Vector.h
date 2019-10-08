#ifndef GEOMETRY_VECTOR_H
#define GEOMETRY_VECTOR_H

#include "Point.h"

namespace geometry {

struct Vector {
    Vector(const Point& origin, const Point& direction);

    static bool is_perpendicular(const Vector& a, const Vector& b);
    static int dot(const Vector& a, const Vector& b);
    Point end_point() const;
    void print() const;

    Point origin;
    Point direction;
};

}

#endif

