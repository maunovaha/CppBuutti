#ifndef VECTOR2_H
#define VECTOR2_H

#include <ostream>
#include <stdexcept>

class Vector2 {
public:
    Vector2(const float x, const float y);

    inline Vector2 operator +(const Vector2& other) const
    {
        return {x_ + other.x_, y_ + other.y_};
    }

    inline Vector2 operator -(const Vector2& other) const
    {
        return {x_ - other.x_, y_ - other.y_};
    }

    inline Vector2 operator *(const float scalar) const
    {
        return {x_ * scalar, y_ * scalar};
    }

    inline Vector2 operator /(const float scalar) const
    {
        if (scalar == 0) {
            throw std::invalid_argument("Zero division error");
        }

        return {x_ / scalar, y_ / scalar};
    }

    friend std::ostream& operator <<(std::ostream& os, const Vector2& other);
private:
    const float x_;
    const float y_;
};

// If this method is not implemented, doing e.g. `2.0f * Vector{1.0f, 1.0f}` does not work.
// So the ordering of the operations matter, here we use "lhs" and "rhs".
Vector2 operator *(const float scalar, const Vector2& other);

#endif