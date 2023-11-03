#pragma once

#include "weapon_base.h"
#include <game/other/cooldown.h>

class WeaponTest : public WeaponBase
{
public:
    WeaponTest(FightingComponent* inFightingComponent, TargetingType inProjectileTarget = TargetingType::Player);
    virtual ~WeaponTest() = default;

    virtual void Use() override;

private:
    Cooldown cooldown = Cooldown(1.5f);
};