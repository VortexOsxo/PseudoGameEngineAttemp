#pragma once

class Entity;
class Vector2D;

class BaseMovementComponent
{
public:
    BaseMovementComponent(Entity* owner, float speed);

    virtual void Move(Vector2D direction, float time);
    virtual void MovementAbility() {};

    inline float GetSpeed() { return speed; }

    inline Entity* GetOwner() const { return owner; }

protected:
    Entity* owner = nullptr;
    float speed;
};