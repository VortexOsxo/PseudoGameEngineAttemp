#include <game/movement_component/base_movement_component.h>
#include <Utils/Vector2D.h>
#include <game/entity/entity.h>

#include <iostream>

BaseMovementComponent::BaseMovementComponent(Entity* owner, float speed) 
    : owner(owner), speed(speed) {}

void BaseMovementComponent::Move(Vector2D direction, float time)
{
    direction.normalize(speed);
    owner->AddToPosition(direction * time);
}
