#include <game/owner/owner.h>
#include <game/tick_system/tickable.h>
#include <game/entity/enemy/enemy.h>

class EnemyOwner : public Owner<Enemy>, Tickable
{
public:
    EnemyOwner();
    virtual ~EnemyOwner();
    
    virtual void Tick(float time);
private:
    class EnemySpawner* enemySpawner;
};