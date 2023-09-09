#pragma once

#include <SFML/Graphics.hpp>
#include <Utils/Vector2D.h>

class Entity;
class Map;

class GameDrawer 
{
public:
    GameDrawer(sf::RenderWindow* window);
    ~GameDrawer() = default;

    void SetRelativePosition(const Vector2D& newRelativePosition);

    void DrawEntity(Entity* entity);
    void DrawPlayer(Entity* player);
    void DrawHealthBar(float currentHealth, float maxHealth);
    void DrawMap(Map* map);

private:
    Vector2D CalculateRelativeDrawPosition();

    sf::RenderWindow* window;
    Vector2D relativePosition = Vector2D::ZeroVector;

    sf::CircleShape circle;
    sf::CircleShape mapBound;
};