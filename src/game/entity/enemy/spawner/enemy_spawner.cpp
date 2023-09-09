#include <game/entity/enemy/spawner/enemy_spawner.h>

#include <Utils/Vector2D.h>
#include <game/other/cooldown.h>
#include <game/entity/enemy/spawner/wave.h>

EnemySpawner::EnemySpawner(EnemyOwner* InEnemyOwner)
    : enemyOwner(InEnemyOwner) 
{
    e.AddPoint(Vector2D(50.f, 50.f));
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