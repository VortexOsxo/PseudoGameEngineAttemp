#include <game/rendering/rendering_components/map_rendering_component.h>

#include <game/rendering/rendering_system.h>
#include <game/map/map.h>

#include <iostream>

MapRenderingComponent::MapRenderingComponent(Map* map)
    : map(map) {}

void MapRenderingComponent::Render(sf::RenderWindow* window)
{
    const float rayon = static_cast<float>(map->GetRayon());

    Vector2D relativePosition = GetRelativePosition();
    circle.setPosition(relativePosition[0] - rayon, relativePosition[1] - rayon);
    circle.setRadius(rayon);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(10.f); 
    circle.setOutlineColor(sf::Color::White);
    window->draw(circle);
}