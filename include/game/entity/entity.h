#pragma once

#include <utils/Vector2D.h>

class Entity
{
public:
    Entity(Vector2D InPosition, int InRayon);
    virtual ~Entity() = default;

    const Vector2D& GetPosition() const;
    void SetPosition(const Vector2D& position);
    void AddToPosition(const Vector2D& offset);

    const Vector2D& GetOrientation() const;
    void SetOrientation(const Vector2D& position);

    bool Collide(const Entity& Other);
    inline int GetRayon() const { return Rayon; }

protected:
    Vector2D Position;
    Vector2D orientation;
    int Rayon;
};