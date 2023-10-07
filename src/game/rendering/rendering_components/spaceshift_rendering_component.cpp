#include <game/rendering/rendering_components/spaceshift_rendering_component.h>

#include <game/rendering/rendering_system.h>
#include <game/entity/entity.h>
#include <filesystem>

#include <iostream>

SpaceshiftRenderingComponent::SpaceshiftRenderingComponent(Entity* entity, std::string shipPath, std::string enginePath)
    : entity(entity), spriteShip(shipPath), spriteEngine(enginePath)
{    
    size = spriteShip.GetSize();
}

void SpaceshiftRenderingComponent::Render(sf::RenderWindow* window)
{
    RenderSpaceshift(window);
}

void SpaceshiftRenderingComponent::RenderSpaceshift(sf::RenderWindow* window)
{
    Vector2D pos = entity->GetPosition() + GetRelativePosition();

    spriteShip.SetPosition(pos);
    spriteEngine.SetPosition(pos);
    OrientSprite();

    window->draw(spriteShip.GetDrawable());
    window->draw(spriteEngine.GetDrawable());
}

void SpaceshiftRenderingComponent::OrientSprite() 
{
    const Vector2D def = Vector2D(0.f, -1.f);
    const Vector2D& orientation = entity->GetOrientation();
    float angle = orientation.x >= 0 ? def.angleDegree(orientation) : 360.f - def.angleDegree(orientation);

    spriteEngine.SetRotation(angle);
    spriteShip.SetRotation(angle);
}