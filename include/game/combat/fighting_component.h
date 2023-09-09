#pragma once

class Ability;
class WeaponBase;

class Vector2D;
class Entity;
enum class TargetingType;

class FightingComponent
{
public:
    FightingComponent();
    virtual ~FightingComponent();

    void SetupWeapon(WeaponBase* weapon);
    void WeaponAttack();

private:    
    WeaponBase* weapon = nullptr;
};