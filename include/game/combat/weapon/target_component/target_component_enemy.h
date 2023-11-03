#include <game/combat/weapon/target_component/target_component_base.h>
#include <game/entity/living_entity_observer.h>

class Entity;
class EnemyOwner;

class TargetComponentEnemy : public TargetComponentBase, private LivingEntityObserver
{
public:
    TargetComponentEnemy(const Vector2D& inFirePoint, const EnemyOwner& enemyOwner);
    virtual ~TargetComponentEnemy() = default;

    virtual void UpdateTarget(const Vector2D& location) override;

    virtual Vector2D GetDirection() const override;

    virtual void ReceiveNotification() const override;

private:
    void FindTarget() const;
    void FindTarget(const Vector2D& location) const;

private:
    LivingEntity* targettedEnemy = nullptr;
    const EnemyOwner& enemyOwner;
};