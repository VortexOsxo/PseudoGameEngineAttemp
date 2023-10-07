#pragma once

#include <game/rendering/rendering_component.h>
#include <vector>
#include <Utils/Vector2D.h>

class Projectile;

class ProjectileRenderingComponent : public RenderingComponent
{
public:
    ProjectileRenderingComponent(Projectile* projectile, std::string path);
    virtual ~ProjectileRenderingComponent() = default;

    virtual void Render(sf::RenderWindow* window) override;

protected:
    void RenderProjectile(sf::RenderWindow* window);

protected:
    Projectile* projectile = nullptr;
    Vector2D size;

private:
    int frame = 0;
    int frameNumber = 0;
    std::vector<sf::Texture> textures;
    std::vector<sf::Sprite> sprites;
};