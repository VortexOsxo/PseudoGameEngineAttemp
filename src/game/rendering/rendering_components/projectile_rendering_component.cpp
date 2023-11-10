#include <game/rendering/rendering_components/projectile_rendering_component.h>

#include <game/rendering/rendering_system.h>
#include <game/rendering/texture_manager/texture_manager.h>
#include <game/entity/projectile.h>

#include <iostream>

ProjectileRenderingComponent::ProjectileRenderingComponent(Projectile* projectile, std::string path)
    : projectile(projectile), projectileSprite(path)
{
    Vector2D orientation = projectile->GetOrientation();
    float angle = orientation.getAngleDegree();
    
    projectileSprite.SetRotationAll(angle);
}

void ProjectileRenderingComponent::Render(sf::RenderWindow* window)
{
    RenderProjectile(window);
}

void ProjectileRenderingComponent::RenderProjectile(sf::RenderWindow* window)
{
    projectileSprite.SetPosition(GetRelativePosition() + projectile->GetPosition());
    window->draw(projectileSprite.GetDrawable());
}
