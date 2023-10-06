#pragma once 

#include <vector>
#include <game/entity/enemy/spawn_order.h>

class EnemyOwner;

class EnemyWave
{
public:
    EnemyWave();

    bool CanBeSpawned(float difficulty);
    void AddEnemy(const std::string& type, const Vector2D& point);

    void Spawn(EnemyOwner* enemyOwner);

private:
    float minDifficulty = 0;
    float maxDifficulty = 0;

    std::vector<SpawnOrder> spawnOrders;
};