#include <game/entity/projectile.h>
#include <game/movement_component/base_movement_component.h>
#include <game/entity/living_entity.h>
#include "Utils/Vector2D.h"

#include <iostream>

const float BASE_SPEED = .1f;
const float BASE_DAMAGE = 20.f;

Projectile::Projectile(Vector2D InPosition, int InRayon, Vector2D InDirection, TargetingType inTargetType)
    : Entity(InPosition, InRayon), target(inTargetType), Direction(InDirection), damage(BASE_DAMAGE)
{
    MovementComponent = new BaseMovementComponent(this, BASE_SPEED);
}

Projectile::~Projectile()
{
    delete MovementComponent;
}

void Projectile::Tick(float time)
{
    Vector2D temp(Direction[0], Direction[1]);
    MovementComponent->Move(temp, time);
}

void Projectile::HitEntity(LivingEntity* cible) 
{
    cible->TakeDamage(damage);
}