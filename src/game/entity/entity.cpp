#include "game/entity/entity.h"

#include <cmath>
#include <iostream>

Entity::Entity(Vector2D InPosition, int InRayon, std::vector<Vector2D>&& points)
    : Position(InPosition), Rayon(InRayon), points(std::move(points))
{
}

const Vector2D& Entity::GetPosition() const
{
    return Position;
}

void Entity::SetPosition(const Vector2D& position)
{
    Position = position;
}

void Entity::AddToPosition(const Vector2D& offset)
{
    Position += offset;
}

const Vector2D& Entity::GetOrientation() const
{
    return orientation;
}

void Entity::SetOrientation(const Vector2D& inOrientation)
{
    if (inOrientation == Vector2D::ZeroVector) return;
    orientation = inOrientation;
}

bool Entity::Collide(const Entity& Other) {
    float DistanceSq = std::pow((Other.Position[0] - Position[0]) , 2) + std::pow((Other.Position[1] - Position[1]) , 2.f);
    float ReachSq = std::pow((Rayon + Other.Rayon), 2.f);

    return DistanceSq < ReachSq;
}
const std::vector<Vector2D> Entity::GetPoints()
{
    std::vector<Vector2D> rotatedPoints;

    float angle = orientation.getAngleRadian(); 

    for (Vector2D point : points)
    {
        point.rotate(angle);
        rotatedPoints.push_back(point);
    }
    return rotatedPoints;
}