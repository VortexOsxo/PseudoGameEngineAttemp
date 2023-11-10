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

    std::vector<Vector2D> points {
        Vector2D(25,25),
        Vector2D(-25,25),
        Vector2D(-25,-25),
        Vector2D(25,-25)
    };

    if (cooldown.Available())
    {
        ProjectileOwner.Emplace(targetComponent->GetFirePoint(), 5.0f, std::move(points), targetComponent->GetDirection(), projectileTarget);
        cooldown.Reset();
    }
}
