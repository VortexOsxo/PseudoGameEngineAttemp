#include "game/combat/weapon/weapon_test.h"

#include <game/game.h> //Shoulndt pass by the level to get the ProjectileHolder;
#include <game/owner/projectile_owner.h>
#include <game/entity/player.h>

#include <iostream>

#include <game/combat/weapon/target_component/target_component_base.h>

WeaponTest::WeaponTest() 
    : WeaponBase(*(Game::GetInstance()->GetProjectileOwner()))
{
}

WeaponTest::~WeaponTest()
{
    delete targetComponent;
}

void WeaponTest::Use()
{
    if (cooldown.Available())
    {
        ProjectileOwner.Emplace(targetComponent->GetFirePoint(), 5.0f, targetComponent->GetDirection(), projectileTarget);
        cooldown.Reset();
    }
}
