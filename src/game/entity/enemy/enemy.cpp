#include <game/entity/enemy/enemy.h>

#include <game/entity/player.h>

#include <game/movement_component/base_movement_component.h>
#include <game/rendering/rendering_components/spaceshift_rendering_component.h>
#include <game/rendering/rendering_system.h>

#include <game/ai/ai_controller_base.h>

#include <iostream>

const int BASE_HEALTH = 100;
const float BASE_SPEED = 0.1f;

Enemy::Enemy(const Vector2D& position, int rayon, std::vector<Vector2D>&& points, const std::string& path) 
    : LivingEntity(position, rayon, std::move(points), BASE_HEALTH)
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

void Enemy::Kill()
{
    RenderingSystem::GetInstance()->PlayAnimation("klaed/fighter/destruction", GetPosition());
    LivingEntity::Kill();
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
