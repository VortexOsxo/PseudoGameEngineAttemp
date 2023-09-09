#include <game/map/map.h>

#include <game/entity/entity.h>

Map::Map(float inRayon)
    : rayon(inRayon)
{}

float Map::GetRayon() const 
{
    return rayon;
}

bool Map::IsInside(Entity* entity) const
{
    return entity->GetPosition().Length() + entity->GetRayon() < rayon;
}

bool Map::IsInside(const Vector2D& position) const
{
    return position.Length() < rayon;
}

sf::Shape* Map::GetDrawableShape()
{
    return obstacle.GetShape();
}