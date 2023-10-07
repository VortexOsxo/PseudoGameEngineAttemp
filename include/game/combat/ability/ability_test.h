#pragma once

#include <game/combat/ability/ability.h>
#include <Utils/Vector2D.h>

class AbilityTest : public Ability
{
public:
    AbilityTest(const Vector2D& position, TargetingType abilityTarget = TargetingType::Player);
    virtual ~AbilityTest() = default;

    virtual void Use() override;

private:
    const Vector2D& position;
    float damage = 50.f;
};