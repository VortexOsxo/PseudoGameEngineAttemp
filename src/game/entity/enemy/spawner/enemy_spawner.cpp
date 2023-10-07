#include <game/entity/enemy/spawner/enemy_spawner.h>

#include <Utils/Vector2D.h>
#include <game/other/cooldown.h>
#include <game/entity/enemy/spawner/wave.h>

EnemySpawner::EnemySpawner(EnemyOwner* InEnemyOwner)
    : enemyOwner(InEnemyOwner) 
{
    e.AddEnemy("default", Vector2D(50.f, 50.f));
    // e.AddEnemy("rusher", Vector2D(75.f, 75.f));
}

void EnemySpawner::Tick(float time)
{
    static Cooldown cd(15.f);
    if (cd.Available())
    {
        cd.Reset();
        e.Spawn(enemyOwner);
    }
}