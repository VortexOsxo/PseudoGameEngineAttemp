#include "game/owner/enemy_owner.h"

#include <game/entity/enemy/spawner/enemy_spawner.h>

#include <memory>
#include <iostream>

EnemyOwner::EnemyOwner()
{
    enemySpawner = new EnemySpawner(this);
}

EnemyOwner::~EnemyOwner()
{
    delete enemySpawner;
}

void EnemyOwner::Tick(float time)
{
    enemySpawner->Tick(time);
    
    CleanUp();
}