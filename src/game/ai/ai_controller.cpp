#include "game/ai/ai_controller.h"

#include "game/game.h"

#include "game/entity/player.h"
#include "game/entity/enemy/enemy.h"

#include "game/combat/fighting_component.h"
#include "game/movement_component/base_movement_component.h"

#include "Utils/Vector2D.h"

#include <iostream>

AIController::AIController(Enemy* InEnemy)
    : enemy(InEnemy)
{}

void AIController::Tick(float time) 
{
    Player* target = Game::GetInstance()->GetPlayer();
    Map* map = Game::GetInstance()->GetMap();

    Vector2D playerPos(target->GetPosition()[0], target->GetPosition()[1]);
    Vector2D thisPos(enemy->GetPosition()[0], enemy->GetPosition()[1]);

    Vector2D direction = playerPos - thisPos;
    float distance = direction.Length();

    if (distance < 400.f)
    {
        Vector2D initialPos = enemy->GetPosition();
        enemy->movementComponent->Move(direction * -1.f, time);
        if(!map->IsInside(enemy))
        {
            enemy->SetPosition(initialPos);
        }
    }

    else if (distance > 600.f)
    {
        enemy->movementComponent->Move(direction, time);
    }
    
    else 
    {
        enemy->fightingComponent->WeaponAttack();
    }
}