#include <Utils/Vector2D.h>

#include <cmath>
#include <ostream>

Vector2D::Vector2D()
    : x_(0.f), y_(0.f)
{
    lengthSq = 1.f;
}

Vector2D::Vector2D(float x, float y)
    : x_(x), y_(y)
{
    lengthSq = std::pow(x,2) + std::pow(y,2);
}
    
Vector2D Vector2D::operator+(const Vector2D &other) const
{
    return { x_ + other.x_, y_ + other.y_ };
}

void Vector2D::operator+=(const Vector2D &other)
{
   x_ += other.x_;
   y_ += other.y_;
   updateLengthSq();
}

Vector2D Vector2D::operator-(const Vector2D &other) const
{
    return { x_ - other.x_, y_ - other.y_ };
}

void Vector2D::operator-=(const Vector2D &other)
{
   x_ -= other.x_;
   y_ -= other.y_;
   updateLengthSq();
}

Vector2D Vector2D::operator*(float multiple) const
 {
    return { x_ * multiple, y_ * multiple };
}

void Vector2D::operator*=(float multiple)
{
    x_ *= multiple;
    y_ *= multiple;
    updateLengthSq();
}

float Vector2D::operator[](int index) const
{
    if (index == 0)
        return x_;
    return y_;
}

void Vector2D::normalize(float length)
{
    float fLength = pow(lengthSq, 0.5f);
    if (fLength == 0)
        return;
    x_ *= length / fLength;
    y_ *= length / fLength;

    lengthSq = length;
}

float Vector2D::Length() const
{
    return std::pow(lengthSq, 0.5f);
}

void Vector2D::updateLengthSq()
{
    lengthSq = std::pow(x_,2) + std::pow(y_,2);
}

std::ostream &operator<<(std::ostream &os, const Vector2D &vector)
{
    os << "(" << vector.x_ << ", " << vector.y_ << ")";
    return os;
}

Vector2D Vector2D::ZeroVector = Vector2D(0.f,0.f);