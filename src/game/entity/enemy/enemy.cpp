#include <game/entity/enemy/enemy.h>

#include <game/entity/player.h>

#include <game/movement_component/base_movement_component.h>
#include <game/rendering/rendering_components/entity_rendering_component.h>

#include <game/ai/ai_controller_base.h>

#include <iostream>

const int BASE_HEALTH = 100;
const float BASE_SPEED = 0.1f;

Enemy::Enemy(Vector2D position, int rayon) 
    : LivingEntity(position, rayon, BASE_HEALTH)
{   
    movementComponent = new BaseMovementComponent(this, BASE_SPEED);
    renderingComponent = new EntityRenderingComponent(this);
}

Enemy::~Enemy()
{
    delete fightingComponent;
    delete movementComponent;
    delete AIcontroller;
    delete renderingComponent;
}

void Enemy::TakeDamage(float damage)
{
    LivingEntity::TakeDamage(damage);
    if(LivingEntity::GetHealth() <= 0)
    {
        SetToDelete();
    }
}

void Enemy::SetFightingComponent(FightingComponent *inFightingComponent)
{
    if (fightingComponent != nullptr) {
        delete fightingComponent;
    }
    fightingComponent = inFightingComponent;
}

void Enemy::SetAIController(AIControllerBase *inAIController)
{
    if (AIcontroller != nullptr) {
        delete AIcontroller;
    }
    AIcontroller = inAIController;
}
