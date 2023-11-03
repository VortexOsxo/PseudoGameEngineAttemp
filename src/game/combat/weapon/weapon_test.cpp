#include "game/combat/weapon/weapon_test.h"

#include <game/game.h> //Shoulndt pass by the level to get the ProjectileHolder;
#include <game/owner/projectile_owner.h>
#include <game/entity/player.h>

#include <iostream>

#include <game/combat/weapon/target_component/target_component_base.h>

WeaponTest::WeaponTest(FightingComponent* inFightingComponent, TargetingType inProjectileTarget) 
    : WeaponBase(*(Game::GetInstance()->GetProjectileOwner()), inFightingComponent, inProjectileTarget)
{
}

void WeaponTest::Use()
{
    const TargetComponentBase* targetComponent = fightingComponent->GetTargetComponent();

    if (cooldown.Available())
    {
        ProjectileOwner.Emplace(targetComponent->GetFirePoint(), 5.0f, targetComponent->GetDirection(), projectileTarget);
        cooldown.Reset();
    }
}
