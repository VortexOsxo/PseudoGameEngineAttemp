#pragma once

#include <game/entity/living_entity.h>
#include <game/owner/ownee.h>

class FightingComponent;
class BaseMovementComponent;
class AIController;

class Enemy : public LivingEntity, public Ownee
{
friend class AIController;

public:
    Enemy(Vector2D inPosition, int inRayon);
    virtual ~Enemy();

    virtual void TakeDamage(float damage) override;

private:
    bool bIsSetup = false;

    FightingComponent* fightingComponent = nullptr;
    BaseMovementComponent* movementComponent = nullptr;
    AIController* AIcontroller = nullptr;
};