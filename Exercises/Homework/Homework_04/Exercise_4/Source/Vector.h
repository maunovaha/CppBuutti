#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
    Vector(int origin_x, int origin_y, int direction_x, int direction_y);

    static bool is_perpendicular(const Vector& a, const Vector& b);
    static int dot(const Vector& a, const Vector& b);
    void print() const;

    int origin_x;
    int origin_y;
    int direction_x;
    int direction_y;
};

#endif
