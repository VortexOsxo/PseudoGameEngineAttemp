#include <game/entity/enemy/enemy.h>

#include <game/entity/player.h>

#include <game/movement_component/base_movement_component.h>
#include <game/rendering/rendering_components/spaceshift_rendering_component.h>
#include <game/rendering/rendering_system.h>

#include <game/ai/ai_controller_base.h>

#include <iostream>

const int BASE_HEALTH = 100;
const float BASE_SPEED = 0.1f;

Enemy::Enemy(const Vector2D& position, int rayon, const std::string& path) 
    : LivingEntity(position, rayon, BASE_HEALTH)
{   
    movementComponent = new BaseMovementComponent(this, BASE_SPEED);
    renderingComponent = new SpaceshiftRenderingComponent(this, path + "/ship.png", path + "/engine");
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
        Kill();
}

void Enemy::Kill()
{
    RenderingSystem::GetInstance()->PlayAnimation("klaed/fighter/destruction", GetPosition());
    SetToDelete();
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
