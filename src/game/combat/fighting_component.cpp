#include <game/combat/fighting_component.h>

#include <game/combat/weapon/weapon_test.h>
#include <game/combat/ability/ability.h>

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

void FightingComponent::SetupAbility(Ability* inAbility)
{
    if (ability != nullptr) 
    {
        delete ability;
    }

    ability = inAbility;
}


void FightingComponent::WeaponAttack()
{
    if (weapon == nullptr) return;
    weapon->Use();
}

void FightingComponent::UseAbility()
{
    if(ability == nullptr) return;
    ability->Use();
}