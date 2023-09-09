#include <game/combat/weapon/target_component/target_component_base.h>

class Entity;
class EnemyOwner;

class TargetComponentEnemy : public TargetComponentBase
{
public:
    TargetComponentEnemy(const Vector2D& inFirePoint, const EnemyOwner& enemyOwner);
    virtual ~TargetComponentEnemy() = default;

    virtual Vector2D GetDirection() const override;

private:
    const EnemyOwner& enemyOwner;
};