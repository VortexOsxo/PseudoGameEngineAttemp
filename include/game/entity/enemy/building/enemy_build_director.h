#pragma once

#include <string>
#include <game/entity/enemy/spawn_order.h>
#include <game/entity/enemy/enemy.h>
#include <memory>

class EnemyOwner;

class EnemyBuildDirector {
public:
    EnemyBuildDirector(EnemyOwner* enemyOwner);

    std::unique_ptr<Enemy> RequestEnemy(const SpawnOrder& spawnOrder);

private:
    EnemyOwner* enemyOwner = nullptr;
};