#include <game/combat/fighting_component.h>

#include <game/combat/weapon/weapon_test.h>
#include <game/entity/entity.h>

#include <iostream>

FightingComponent::FightingComponent()
{

}

FightingComponent::~FightingComponent()
{
    if (weapon != nullptr)
    {
        delete weapon;
    }
}

void FightingComponent::SetupWeapon(WeaponBase* inWeapon)
{
    if (weapon != nullptr) 
    {
        delete weapon;
    }

    weapon = inWeapon;
}

void FightingComponent::WeaponAttack()
{
    if (weapon == nullptr) return;
    weapon->Use();
}
