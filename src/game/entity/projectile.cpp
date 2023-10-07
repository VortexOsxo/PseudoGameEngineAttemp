#include <game/entity/projectile.h>

#include <game/movement_component/base_movement_component.h>
#include <game/rendering/rendering_components/projectile_rendering_component.h>

#include <game/entity/living_entity.h>
#include "Utils/Vector2D.h"

#include <iostream>

const float BASE_SPEED = .5f;
const float BASE_DAMAGE = 20.f;

Projectile::Projectile(Vector2D InPosition, int InRayon, Vector2D InDirection, TargetingType inTargetType)
    : Entity(InPosition, InRayon), target(inTargetType), damage(BASE_DAMAGE)
{
    SetOrientation(InDirection);
    MovementComponent = new BaseMovementComponent(this, BASE_SPEED);
    renderingComponent = new ProjectileRenderingComponent(this, "D:/Program/Games/SpaceFighter/assets/klaed/projectiles/torpedo");
}

Projectile::~Projectile()
{
    delete MovementComponent;
    delete renderingComponent;
}

void Projectile::Tick(float time)
{
    MovementComponent->Move(orientation, time);
}

void Projectile::HitEntity(LivingEntity* cible) 
{
    cible->TakeDamage(damage);
}