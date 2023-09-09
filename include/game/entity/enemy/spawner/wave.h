#pragma once 

#include <vector>

class Vector2D;
class EnemyOwner;

class EnemyWave
{
public:
    EnemyWave();

    bool CanBeSpawned(float difficulty);
    void AddPoint(const Vector2D& point);

    void Spawn(EnemyOwner* enemyOwner);

private:
    float minDifficulty = 0;
    float maxDifficulty = 0;

    std::vector<Vector2D> Locations;
};