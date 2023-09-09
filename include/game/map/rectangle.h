#pragma once

#include <game/map/obstacle.h>
#include <Utils/Vector2D.h>

class RectangleObstacle : public Obstacle
{
public:
    RectangleObstacle(const Vector2D position, const Vector2D size);
    virtual ~RectangleObstacle() = default;

    virtual bool Collide(Entity* entity) const override;

    virtual sf::Shape* GetShape() override;

private:
    sf::RectangleShape rectangle;

    Vector2D position = Vector2D::ZeroVector;
    Vector2D size = Vector2D::ZeroVector;
};