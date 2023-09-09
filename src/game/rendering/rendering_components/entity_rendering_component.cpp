#include <game/rendering/rendering_components/entity_rendering_component.h>

#include <game/rendering/rendering_system.h>
#include <game/entity/entity.h>

EntityRenderingComponent::EntityRenderingComponent(Entity* entity)
    : entity(entity) {}

void EntityRenderingComponent::Render(sf::RenderWindow* window)
{
    Vector2D pos = entity->GetPosition();
    const float rayon = static_cast<float>(entity->GetRayon());

    Vector2D relativePosition = renderingSystem->GetRelativePosition();

    circle.setPosition(relativePosition[0] + pos[0] - rayon, relativePosition[1] + pos[1] - rayon);
    circle.setRadius(rayon);
    circle.setFillColor(sf::Color::Blue);
    window->draw(circle);
}