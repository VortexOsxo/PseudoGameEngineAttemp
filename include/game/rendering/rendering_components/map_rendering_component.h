#pragma once

#include <game/rendering/rendering_component.h>

class Map;

class MapRenderingComponent : public RenderingComponent
{
public:
    MapRenderingComponent(Map* map);
    virtual ~MapRenderingComponent() = default;

    virtual void Render(sf::RenderWindow* window) override;

private:
    Map* map;
    sf::CircleShape circle = sf::CircleShape(1.f);
};