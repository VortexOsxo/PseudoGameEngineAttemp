#pragma once

#include <utils/Vector2D.h>

#include <vector>

class Entity
{
public:
    Entity(Vector2D InPosition, int InRayon, std::vector<Vector2D>&& points);
    virtual ~Entity() = default;

    const Vector2D& GetPosition() const;
    void SetPosition(const Vector2D& position);
    void AddToPosition(const Vector2D& offset);

    const Vector2D& GetOrientation() const;
    void SetOrientation(const Vector2D& position);

    bool Collide(const Entity& Other);
    inline int GetRayon() const { return Rayon; }
    const std::vector<Vector2D> GetPoints();

protected:
    Vector2D Position;
    Vector2D orientation;
    std::vector<Vector2D> points;
    
    int Rayon;
};