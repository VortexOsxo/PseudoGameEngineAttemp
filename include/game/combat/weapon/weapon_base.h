#pragma once

#include <game/combat/targeting_type.h>

class ProjectileOwner;
class FightingComponent;

class WeaponBase
{
friend class WeaponBuilder;
public:
    WeaponBase(ProjectileOwner& ProjectileOwner, FightingComponent* inFightingComponent, TargetingType inProjectileTarget = TargetingType::Player) 
        : projectileTarget(inProjectileTarget), ProjectileOwner(ProjectileOwner),
          fightingComponent(inFightingComponent) {}

    virtual ~WeaponBase() = default;

    virtual void Use() =0;

protected:
    ProjectileOwner& ProjectileOwner;
    
    TargetingType projectileTarget;
    FightingComponent* fightingComponent = nullptr;
};