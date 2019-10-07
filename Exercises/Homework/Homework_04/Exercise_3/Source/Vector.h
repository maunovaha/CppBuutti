#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
    Vector(int origin_x, int origin_y, int direction_x, int direction_y);

    void print() const;

    int origin_x;
    int origin_y;
    int direction_x;
    int direction_y;
};

#endif
