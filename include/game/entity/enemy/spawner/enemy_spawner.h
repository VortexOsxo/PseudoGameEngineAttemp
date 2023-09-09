#include <game/entity/enemy/spawner/wave.h>

class EnemyOwner;

class EnemySpawner
{
public:
    EnemySpawner(EnemyOwner* InEnemyOwner);

    void Tick(float time);

private:
    EnemyOwner* enemyOwner;
    EnemyWave e;
};