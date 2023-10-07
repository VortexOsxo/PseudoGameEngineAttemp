#include <Utils/Vector2D.h>

#include <cmath>
#include <ostream>

Vector2D::Vector2D()
    : x(0.f), y(0.f)
{
    lengthSq = 1.f;
}

Vector2D::Vector2D(float x, float y)
    : x(x), y(y)
{
    lengthSq = std::pow(x,2) + std::pow(y,2);
}
    
Vector2D Vector2D::operator+(const Vector2D &other) const
{
    return { x + other.x, y + other.y };
}

void Vector2D::operator+=(const Vector2D &other)
{
   x += other.x;
   y += other.y;
   updateLengthSq();
}

Vector2D Vector2D::operator-(const Vector2D &other) const
{
    return { x - other.x, y - other.y };
}

void Vector2D::operator-=(const Vector2D &other)
{
   x -= other.x;
   y -= other.y;
   updateLengthSq();
}

Vector2D Vector2D::operator*(float multiple) const
 {
    return { x * multiple, y * multiple };
}

void Vector2D::operator*=(float multiple)
{
    x *= multiple;
    y *= multiple;
    updateLengthSq();
}

bool Vector2D::operator==(const Vector2D& other) const
{
    return x == other.x && y == other.y;
}

float Vector2D::operator[](int index) const
{
    if (index == 0)
        return x;
    return y;
}

void Vector2D::normalize(float length)
{
    float fLength = pow(lengthSq, 0.5f);
    if (fLength == 0)
        return;
    x *= length / fLength;
    y *= length / fLength;

    lengthSq = length;
}

float Vector2D::Length() const
{
    return std::pow(lengthSq, 0.5f);
}

float Vector2D::dotProduct(const Vector2D& other) const
{
    return x * other.x + y * other.y;
}

float Vector2D::angleDegree(const Vector2D& other) const
{
    float k = dotProduct(other) / (Length() * other.Length());
    return std::acos(k) * 180.f / M_PI;
}

void Vector2D::updateLengthSq()
{
    lengthSq = std::pow(x,2) + std::pow(y,2);
}

std::ostream &operator<<(std::ostream &os, const Vector2D &vector)
{
    os << "(" << vector.x << ", " << vector.y << ")";
    return os;
}

Vector2D Vector2D::ZeroVector = Vector2D(0.f,0.f);