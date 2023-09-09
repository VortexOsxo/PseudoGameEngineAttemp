#include <game/entity/enemy/enemy.h>

#include <game/game.h>
#include <game/entity/player.h>
#include <game/combat/targeting_type.h>

#include <game/combat/weapon/builder/WeaponBuilder.h>
#include <game/combat/fighting_component.h>
#include <game/movement_component/base_movement_component.h>
#include <game/ai/ai_controller.h>
#include <game/rendering/rendering_components/entity_rendering_component.h>

#include <iostream>

const int BASE_HEALTH = 100;
const float BASE_SPEED = 0.1f;

Enemy::Enemy(Vector2D position, int rayon) 
    : LivingEntity(position, rayon, BASE_HEALTH)
{
    fightingComponent = new FightingComponent();

    WeaponBuilder builder;
    builder.SetProjectileTarget(TargetingType::Player);
    builder.UseCibleTargetting(GetPosition(), Game::GetInstance()->GetPlayer()->GetPosition());
    fightingComponent->SetupWeapon(builder.GetWeapon());
    
    movementComponent = new BaseMovementComponent(this, BASE_SPEED);
    AIcontroller = new AIController(this);
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
