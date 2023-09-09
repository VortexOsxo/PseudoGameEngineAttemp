#include <game/combat/weapon/target_component/target_component_enemy.h>

#include <game/owner/enemy_owner.h>
#include <Utils/Vector2D.h>

TargetComponentEnemy::TargetComponentEnemy(const Vector2D& inFirePoint, const EnemyOwner& enemyOwner)
    : TargetComponentBase(inFirePoint), enemyOwner(enemyOwner)
    {}

Vector2D TargetComponentEnemy::GetDirection() const 
{
    if (enemyOwner.GetOwnees().size() > 0)
    {
        Enemy* enemy = enemyOwner.GetOwnees()[0].get();
        return enemy->GetPosition() - GetFirePoint();
    }
    return { 1.f, 1.f };
}