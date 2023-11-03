#include <game/combat/fighting_component.h>

#include <game/combat/weapon/weapon_test.h>
#include <game/combat/ability/ability.h>

#include <game/entity/entity.h>
#include <game/combat/weapon/target_component/target_component_base.h>

#include <iostream>

FightingComponent::FightingComponent(TargetComponentBase* targetComponentIn)
: targetComponent(targetComponentIn) {}

FightingComponent::~FightingComponent()
{
    delete targetComponent;
    if (weapon != nullptr)
    {
        delete weapon;
    }
    if (ability != nullptr)
    {
        delete ability;
    }
}

void FightingComponent::UpdateTarget(const Vector2D& location) 
{
    targetComponent->UpdateTarget(location);
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