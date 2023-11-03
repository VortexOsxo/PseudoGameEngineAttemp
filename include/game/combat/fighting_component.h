#pragma once

class Ability;
class WeaponBase;

class Entity;
enum class TargetingType;
class TargetComponentBase;

class FightingComponent
{
public:
    FightingComponent(TargetComponentBase* targetComponentIn);
    virtual ~FightingComponent();

    const TargetComponentBase* GetTargetComponent() { return targetComponent; }
    void UpdateTarget(const class Vector2D& location);

    void SetupWeapon(WeaponBase* weapon);
    void SetupAbility(Ability* ability);

    void UseAbility();
    void WeaponAttack();

private:
    TargetComponentBase* targetComponent = nullptr;

    WeaponBase* weapon = nullptr;
    Ability* ability = nullptr;
};