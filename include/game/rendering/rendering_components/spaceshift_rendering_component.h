#pragma once

#include <game/rendering/rendering_component.h>
#include <vector>
#include <Utils/Vector2D.h>

class Entity;

class SpaceshiftRenderingComponent : public RenderingComponent
{
public:
    SpaceshiftRenderingComponent(Entity* entity, std::string shipPath, std::string enginePath);
    virtual ~SpaceshiftRenderingComponent() = default;

    virtual void Render(sf::RenderWindow* window) override;

protected:
    void RenderSpaceshift(sf::RenderWindow* window);
    void OrientSprite();

protected:
    Entity* entity = nullptr;
    Vector2D size;

private:
    sf::Texture textureShip;
    sf::Sprite spriteShip;

    int frameEngine = 0;
    int frameEngineNumber = 0;
    std::vector<sf::Texture> textureEngine;
    std::vector<sf::Sprite> spriteEngine;
};