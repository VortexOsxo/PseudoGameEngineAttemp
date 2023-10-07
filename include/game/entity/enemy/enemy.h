#pragma once

#include <game/entity/living_entity.h>
#include <game/owner/ownee.h>

class FightingComponent;
class BaseMovementComponent;
class AIControllerBase;
class SpaceshiftRenderingComponent;

class Enemy : public LivingEntity, public Ownee
{
public:
    Enemy(const Vector2D& position, int rayon, const std::string& path);
    virtual ~Enemy();

    virtual void TakeDamage(float damage) override;
    virtual void Kill();

    void SetFightingComponent(FightingComponent* inFightingComponent);
    void SetAIController(AIControllerBase* AIController);

    inline FightingComponent* GetFightingComponent() const { return fightingComponent; }
    inline BaseMovementComponent* GetMovementComponent() const { return movementComponent; }

private:
    FightingComponent* fightingComponent = nullptr;
    BaseMovementComponent* movementComponent = nullptr;
    AIControllerBase* AIcontroller = nullptr;
    SpaceshiftRenderingComponent* renderingComponent = nullptr;
};