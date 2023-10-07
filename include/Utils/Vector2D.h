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

    bool operator==(const Vector2D& other) const;

    float operator[](int index) const;

    void normalize(float length = 1.f);

    float Length() const; 

    float dotProduct(const Vector2D& other) const;
    float angleDegree(const Vector2D& other) const;

    inline float GetFirst() const { return x; }
    inline float GetSecond() const { return y; }

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vector);

public:
    float x;
    float y;

private:
    void updateLengthSq();

    float lengthSq;

public:
    static Vector2D ZeroVector;
};
