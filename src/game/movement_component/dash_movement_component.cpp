#include <game/movement_component/dash_movement_component.h>
#include <Utils/Vector2D.h>
#include <game/entity/entity.h>

DashMovementComponent::DashMovementComponent(Entity* owner, float speed, float dashCooldown, float dashTimer, float dashSpeed) 
    : BaseMovementComponent(owner, speed), dashCooldown(dashCooldown), dashTimer(dashTimer), dashSpeed(dashSpeed)  { bIsDashing = false; }

void DashMovementComponent::Move(Vector2D direction, float time)
{
    BaseMovementComponent::Move(direction, time);
    bIsDashing = !dashTimer.Available();
    if (bIsDashing) 
    {
        direction.normalize(dashSpeed * time);
        owner->AddToPosition(direction);
    }
}

void DashMovementComponent::MovementAbility()
{
    if (dashCooldown.Available())
    {
        bIsDashing = true;
        dashCooldown.Reset();
        dashTimer.Reset();
    }
}
