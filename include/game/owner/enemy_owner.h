#include <game/owner/owner.h>
#include <game/tick_system/tickable.h>
#include <game/entity/enemy/enemy.h>

class EnemyOwner : public Owner<Enemy>, Tickable
{
public:
    EnemyOwner();
    virtual ~EnemyOwner();
    
    virtual void Tick(float time);

    void RequestSpawn(const class SpawnOrder& spawnOrder);

private:
    class EnemySpawner* enemySpawner = nullptr;
    class EnemyBuildDirector* enemyBuildDirector = nullptr;
};