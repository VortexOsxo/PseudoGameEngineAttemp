#include "game/tick_system/tickable.h"

class Enemy;

class AIController : public Tickable
{
public:
    AIController(Enemy* InEnemy);
    virtual ~AIController() = default;

    virtual void Tick(float Time) override;

private:
    Enemy* enemy = nullptr;
};