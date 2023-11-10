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

void Vector2D::rotate(float angle)
{
    float tx = x; float ty = y;
    x = tx * cos(angle) - ty * sin(angle);
    y = tx * sin(angle) + ty * cos(angle);
}

float Vector2D::Length() const
{
    return std::pow(lengthSq, 0.5f);
}

float Vector2D::dotProduct(const Vector2D& other) const
{
    return x * other.x + y * other.y;
}

float Vector2D::angleRadianWith(const Vector2D& other) const
{
    float k = dotProduct(other) / (Length() * other.Length());
    return std::acos(k);
}

float Vector2D::angleDegreeWith(const Vector2D& other) const
{
    return angleRadianWith(other) * 180.f / M_PI;
}

float Vector2D::getAngleRadian() const
{
    float angle = VectorJ.angleRadianWith(*this);
    return x >= 0 ? angle : 2*M_PI - angle;
}

float Vector2D::getAngleDegree() const
{
    float angle = VectorJ.angleDegreeWith(*this);
    return x >= 0 ? angle : 360.f - angle;
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
Vector2D Vector2D::VectorI = Vector2D(1.f,0.f);
Vector2D Vector2D::VectorJ = Vector2D(0.f,-1.f);