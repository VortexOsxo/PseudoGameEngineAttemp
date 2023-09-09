#include <game/map/rectangle.h>

#include <game/entity/entity.h>

RectangleObstacle::RectangleObstacle(const Vector2D position, const Vector2D size)
    : position(position), size(size)
{
    rectangle = sf::RectangleShape({size[0], size[1]});
}

bool RectangleObstacle::Collide(Entity* entity) const
{
    return true;
}

sf::Shape* RectangleObstacle::GetShape()
{
    rectangle.setPosition(position[0], position[1]);
    return &rectangle;
}
