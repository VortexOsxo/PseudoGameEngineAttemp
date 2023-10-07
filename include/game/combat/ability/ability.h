#pragma once

#include <game/combat/targeting_type.h>

class TargetComponentBase;

class Ability
{
public:
    Ability(TargetingType target) : abilityTarget(target) {}

    virtual ~Ability() = default;

    virtual void Use() =0;

protected:    
    TargetingType abilityTarget;
};