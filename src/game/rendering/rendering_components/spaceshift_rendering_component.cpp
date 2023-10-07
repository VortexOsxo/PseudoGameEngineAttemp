#include <game/rendering/rendering_components/spaceshift_rendering_component.h>

#include <game/rendering/rendering_system.h>
#include <game/entity/entity.h>
#include <filesystem>

#include <iostream>

SpaceshiftRenderingComponent::SpaceshiftRenderingComponent(Entity* entity, std::string shipPath, std::string enginePath)
    : entity(entity) 
{
    textureShip.loadFromFile(shipPath);
    spriteShip.setTexture(textureShip);
    size = Vector2D(textureShip.getSize().x, textureShip.getSize().y); 
    spriteShip.setOrigin(size.x/2, size.y/2);
    
    for (const auto& entry : std::filesystem::directory_iterator(enginePath))
    {
        textureEngine.emplace(textureEngine.end());
        spriteEngine.emplace(spriteEngine.end());
    }

    for (const auto& entry : std::filesystem::directory_iterator(enginePath))
    {
        textureEngine[frameEngineNumber].loadFromFile(entry.path().string());
        spriteEngine[frameEngineNumber].setTexture(textureEngine[frameEngineNumber]);
        spriteEngine[frameEngineNumber].setOrigin(size.x/2, size.y/2);
        ++frameEngineNumber;
    }
}

void SpaceshiftRenderingComponent::Render(sf::RenderWindow* window)
{
    RenderSpaceshift(window);
}

void SpaceshiftRenderingComponent::RenderSpaceshift(sf::RenderWindow* window)
{
    Vector2D pos = entity->GetPosition();
    const float rayon = static_cast<float>(entity->GetRayon());

    Vector2D relativePosition = renderingSystem->GetRelativePosition();

    float px = relativePosition[0] + pos[0]; float py = relativePosition[1] + pos[1];
    spriteShip.setPosition(px, py);

    frameEngine  = (frameEngine + 1) % frameEngineNumber;
    spriteEngine[frameEngine].setPosition(px, py);
    OrientSprite();
    window->draw(spriteShip);
    window->draw(spriteEngine[frameEngine]);
}

void SpaceshiftRenderingComponent::OrientSprite() 
{
    const Vector2D def = Vector2D(0.f, -1.f);
    const Vector2D& orientation = entity->GetOrientation();
    float angle = orientation.x >= 0 ? def.angleDegree(orientation) : 360.f - def.angleDegree(orientation);

    spriteEngine[frameEngine].setRotation(angle);
    spriteShip.setRotation(angle);
}