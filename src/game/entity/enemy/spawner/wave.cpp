#include <game/entity/enemy/spawner/wave.h>

#include <game/owner/enemy_owner.h>

EnemyWave::EnemyWave() {}

bool EnemyWave::CanBeSpawned(float difficulty)
{
    return true;
}

void EnemyWave::AddEnemy(const std::string& type, const Vector2D& point)
{
    spawnOrders.push_back(SpawnOrder{type, point});
}

void EnemyWave::Spawn(EnemyOwner* enemyOwner)
{
    for (auto& spawnOrder : spawnOrders)
    {
        enemyOwner->RequestSpawn(spawnOrder);
    }
}