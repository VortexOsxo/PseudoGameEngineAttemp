#pragma once

#include <game/entity/entity.h>
#include <game/owner/ownee.h>
#include <game/tick_system/tickable.h>
#include <game/combat/targeting_type.h>

class BaseMovementComponent;
class ProjectileRenderingComponent;

class Projectile : public Entity, public Ownee
{
public:
    Projectile(Vector2D InPosition, int InRayon, Vector2D InDirection, TargetingType inTargetType = TargetingType::Player);
    virtual ~Projectile();

    void Tick(float Time);

    inline TargetingType GetTargetType() const { return target; }

    inline BaseMovementComponent* GetMovementComponent() const { return MovementComponent; }

    virtual void HitEntity(class LivingEntity* cible);

private:
    TargetingType target;

    BaseMovementComponent* MovementComponent =nullptr;
    ProjectileRenderingComponent* renderingComponent = nullptr; 

    float damage;
};