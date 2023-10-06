#include "game/owner/enemy_owner.h"

#include <game/entity/enemy/spawner/enemy_spawner.h>
#include <game/entity/enemy/building/enemy_build_director.h>

#include <memory>
#include <iostream>

EnemyOwner::EnemyOwner()
{
    enemySpawner = new EnemySpawner(this);
    enemyBuildDirector = new EnemyBuildDirector(this);
}

EnemyOwner::~EnemyOwner()
{
    delete enemySpawner;
    delete enemyBuildDirector;
}

void EnemyOwner::Tick(float time)
{
    enemySpawner->Tick(time);
    
    CleanUp();
}

void EnemyOwner::RequestSpawn(const SpawnOrder& spawnOrder) 
{
    
    Ownees.emplace_back(std::move(enemyBuildDirector->RequestEnemy(spawnOrder)));
}