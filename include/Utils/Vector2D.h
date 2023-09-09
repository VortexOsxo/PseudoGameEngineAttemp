#pragma once

#include <ostream>

class Vector2D
{
public:
    Vector2D();
    Vector2D(float x, float y);

    Vector2D operator+(const Vector2D& other) const;
    void operator+=(const Vector2D& other);
        
    Vector2D operator-(const Vector2D& other) const;
    void operator-=(const Vector2D& other);

    Vector2D operator*(float multiple) const;
    void operator*=(float multiple);

    float operator[](int index) const;

    void normalize(float length = 1.f);

    float Length() const; 

    inline float GetFirst() const { return x_; }
    inline float GetSecond() const { return y_; }

    inline void SetFirst(float x) { x_ = x; }
    inline void SetSecond(float y) { y_ = y; }

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vector);

private:
    void updateLengthSq();

    float x_;
    float y_;
    float lengthSq;

public:
    static Vector2D ZeroVector;
};
