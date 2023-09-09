#pragma once

#include <game/movement_component/base_movement_component.h>
#include <game/other/cooldown.h>
#include <memory>

class DashMovementComponent : public BaseMovementComponent
{
public:
    DashMovementComponent(Entity* owner, float speed, float dashCooldown, float dashTimer, float dashSpeed);
    virtual void Move(Vector2D direction, float time) override;
    virtual void MovementAbility() override;

private:
    Cooldown dashCooldown;
    Cooldown dashTimer;
    float dashSpeed;
    bool bIsDashing;
};