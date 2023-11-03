#pragma once

class Vector2D;

class TargetComponentBase
{
public:
    TargetComponentBase(const Vector2D& firePoint);
    virtual ~TargetComponentBase() = default;

    Vector2D GetFirePoint() const;

    virtual void UpdateTarget(const Vector2D& location) {};

    virtual Vector2D GetDirection() const =0;

private:
    const Vector2D& firePoint;
};