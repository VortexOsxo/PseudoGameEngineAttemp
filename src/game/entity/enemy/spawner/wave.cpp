#include <game/entity/enemy/spawner/wave.h>

#include <game/owner/enemy_owner.h>

EnemyWave::EnemyWave() {}

bool EnemyWave::CanBeSpawned(float difficulty)
{
    return true;
}

void EnemyWave::AddPoint(const Vector2D& point)
{
    Locations.push_back(point);
}

void EnemyWave::Spawn(EnemyOwner* enemyOwner)
{
    for (auto& location : Locations)
    {
        enemyOwner->Emplace(location, 25.f);
    }
}