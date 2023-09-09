#include <game/entity/player.h>

#include <game/movement_component/dash_movement_component.h>
#include <game/combat/targeting_type.h>
#include <game/combat/weapon/builder/WeaponBuilder.h>
#include <game/game.h>
#include <iostream>

#include <game/combat/weapon/weapon_test.h>

const float BASE_HEALTH = 100.f;
const float BASE_SPEED = 0.1f;

const float DASH_CD = 0.5f;
const float DASH_TIME = 0.150f;
const float DASH_BONUS_SPEED = 0.5f;


Player::Player(Vector2D position, int rayon) 
    : LivingEntity(position, rayon, BASE_HEALTH)
{   
    movementComponent = std::make_unique<DashMovementComponent>(this, BASE_SPEED, DASH_CD, DASH_TIME, DASH_BONUS_SPEED);
    fightingComponent = std::make_unique<FightingComponent>();
    
    WeaponBuilder builder;
    builder.SetProjectileTarget(TargetingType::Enemy);
    builder.UseEnemyTargetting(GetPosition(), *(Game::GetInstance()->GetEnemyOwner()));
    fightingComponent->SetupWeapon(builder.GetWeapon());
}

Player::~Player()
{
}

void Player::Attack()
{
    fightingComponent->WeaponAttack();
}