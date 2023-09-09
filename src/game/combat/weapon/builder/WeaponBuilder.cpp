#include <game/combat/weapon/builder/WeaponBuilder.h>

#include <game/combat/weapon/weapon_test.h>
#include <game/combat/weapon/target_component/target_component_lockcible.h>
#include <game/combat/weapon/target_component/target_component_mouse.h>
#include <game/combat/weapon/target_component/target_component_enemy.h>

WeaponBuilder::WeaponBuilder() 
{
    Reset();
}

WeaponBuilder::~WeaponBuilder()
{
    if (weapon != nullptr)
    {
        delete weapon;
    }
}

void WeaponBuilder::Reset()
{
    weapon = new WeaponTest();
    bTargetingSet = false;
}

WeaponBase* WeaponBuilder::GetWeapon()
{
    WeaponBase* temp;
    if (!bTargetingSet) 
    {
        delete weapon;
        temp = nullptr;
    }
    else 
    {
        temp = weapon;
    }
    Reset();
    return temp;
}

void WeaponBuilder::SetProjectileTarget(TargetingType targetType)
{
    weapon->projectileTarget = targetType;
}

void WeaponBuilder::UseMouseTargetting(const Vector2D& firePos)
{
    weapon->targetComponent = new TargetComponentMouse(firePos);
    bTargetingSet = true;
}

void WeaponBuilder::UseCibleTargetting(const Vector2D& firePos, const Vector2D& cible)
{
    weapon->targetComponent = new TargetComponentLockCible(firePos, cible);
    bTargetingSet = true;
}

void WeaponBuilder::UseEnemyTargetting(const Vector2D &firePos, const EnemyOwner &enemyOwner)
{
    weapon->targetComponent = new TargetComponentEnemy(firePos, enemyOwner);
    bTargetingSet = true;
}
