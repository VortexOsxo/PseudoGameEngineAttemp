#include <game/rendering/rendering_components/projectile_rendering_component.h>

#include <game/rendering/rendering_system.h>
#include <game/entity/projectile.h>
#include <filesystem>

#include <iostream>

ProjectileRenderingComponent::ProjectileRenderingComponent(Projectile* projectile, std::string path)
    : projectile(projectile) 
{
    Vector2D def = Vector2D(0.f,-1.f);
    Vector2D orientation = projectile->GetOrientation();
    std::cout << orientation << std::endl;
    float angle = orientation.x >= 0 ? def.angleDegree(orientation) : 360.f - def.angleDegree(orientation);

    std::cout << angle << std::endl;

    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        textures.emplace(textures.end());
        sprites.emplace(sprites.end());
    }
    bool first = true;
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        textures[frameNumber].loadFromFile(entry.path().string());
        if (first) {
            first = false;
            size = Vector2D(textures[0].getSize().x, textures[0].getSize().y);
        }
         
        sprites[frameNumber].setTexture(textures[frameNumber]);
        sprites[frameNumber].setOrigin(size.x/2, size.y/2);
        sprites[frameNumber].setRotation(angle);
        ++frameNumber;
    }
}

void ProjectileRenderingComponent::Render(sf::RenderWindow* window)
{
    RenderProjectile(window);
}

void ProjectileRenderingComponent::RenderProjectile(sf::RenderWindow* window)
{
    Vector2D pos = projectile->GetPosition();
    const float rayon = static_cast<float>(projectile->GetRayon());

    Vector2D relativePosition = renderingSystem->GetRelativePosition();

    float px = relativePosition[0] + pos[0]; float py = relativePosition[1] + pos[1];

    frame  = (frame + 1) % frameNumber;
    sprites[frame].setPosition(px, py);
    window->draw(sprites[frame]);
}
