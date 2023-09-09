#include "game/entity/entity.h"

#include<cmath>

Entity::Entity(Vector2D InPosition, int InRayon)
    : Position(InPosition), Rayon(InRayon)
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

bool Entity::Collide(const Entity& Other) {
    float DistanceSq = std::pow((Other.Position[0] - Position[0]) , 2) + std::pow((Other.Position[1] - Position[1]) , 2.f);
    float ReachSq = std::pow((Rayon + Other.Rayon), 2.f);

    return DistanceSq < ReachSq;
}