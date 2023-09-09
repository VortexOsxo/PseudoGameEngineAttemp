#pragma once

#include <game/combat/targeting_type.h>

class ProjectileOwner;
class TargetComponentBase;

class WeaponBase
{
friend class WeaponBuilder;
public:
    WeaponBase(ProjectileOwner& ProjectileOwner) 
        : projectileTarget(TargetingType::Player), ProjectileOwner(ProjectileOwner) {}

    virtual ~WeaponBase() = default;

    virtual void Use() =0;

protected:
    ProjectileOwner& ProjectileOwner;
    
    TargetingType projectileTarget;
    TargetComponentBase* targetComponent = nullptr;
};