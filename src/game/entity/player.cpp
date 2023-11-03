#include <game/entity/player.h>

#include <game/game.h>
#include <iostream>

#include <game/combat/weapon/weapon_test.h>
#include <game/movement_component/dash_movement_component.h>
#include <game/combat/weapon/target_component/target_component_enemy.h>

const float BASE_HEALTH = 10000.f;
const float BASE_SPEED = 0.1f;

const float DASH_CD = 0.5f;
const float DASH_TIME = 0.150f;
const float DASH_BONUS_SPEED = 0.5f;


Player::Player(Vector2D position, int rayon) 
    : LivingEntity(position, rayon, BASE_HEALTH)
{   
    movementComponent = std::make_unique<DashMovementComponent>(this, BASE_SPEED, DASH_CD, DASH_TIME, DASH_BONUS_SPEED);
    fightingComponent = std::make_unique<FightingComponent>(new TargetComponentEnemy(GetPosition(), *(Game::GetInstance()->GetEnemyOwner())));
    renderingComponent = std::make_unique<PlayerRenderingComponent>(this);
    
    WeaponTest* weapon = new WeaponTest(fightingComponent.get(), TargetingType::Enemy);
    fightingComponent->SetupWeapon(weapon);
}

Player::~Player()
{
}

void Player::Attack()
{
    fightingComponent->WeaponAttack();
}