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
    #ifdef DEBUG
    RenderHitbox(window);
    #endif
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

#ifdef DEBUG
void SpaceshiftRenderingComponent::RenderHitbox(sf::RenderWindow* window)
{
    Vector2D pos = entity->GetPosition() + GetRelativePosition();

    const std::vector<Vector2D>& points = entity->GetPoints();
    int size = points.size();
    if (size <= 1) return;

    sf::Vertex line[2] = {
        sf::Vertex(sf::Vector2f(points[size-1].x+pos.x, points[size-1].y+pos.y), sf::Color::Red),
        sf::Vertex(sf::Vector2f(points[0].x+pos.x, points[0].y+pos.y), sf::Color::Blue)
    }; window->draw(line, points.size(), sf::Lines);

    
    for (int i = 0; i+1 < points.size(); ++i) {
        line[0].position = sf::Vector2f(points[i].x+pos.x, points[i].y+pos.y);
        line[1].position = sf::Vector2f(points[i+1].x+pos.x, points[i+1].y+pos.y);
        window->draw(line, points.size(), sf::Lines);
    }
}
#endif

void SpaceshiftRenderingComponent::OrientSprite() 
{
    const Vector2D& orientation = entity->GetOrientation();
    float angle = orientation.getAngleDegree();

    spriteEngine.SetRotation(angle);
    spriteShip.SetRotation(angle);
}