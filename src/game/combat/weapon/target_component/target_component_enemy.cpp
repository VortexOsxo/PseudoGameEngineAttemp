#include <game/combat/weapon/target_component/target_component_enemy.h>

#include <game/owner/enemy_owner.h>
#include <Utils/Vector2D.h>
#include <iostream>

TargetComponentEnemy::TargetComponentEnemy(const Vector2D& inFirePoint, const EnemyOwner& enemyOwner)
    : TargetComponentBase(inFirePoint), enemyOwner(enemyOwner)
    {}

Vector2D TargetComponentEnemy::GetDirection() const 
{
    if (targettedEnemy == nullptr)
        FindTarget();
        
    if(targettedEnemy == nullptr) 
        return { 1.f, 1.f };
    
    return targettedEnemy->GetPosition() - GetFirePoint();       
}

void TargetComponentEnemy::ReceiveNotification() const
{
    auto* idk = const_cast<TargetComponentEnemy*>(this); 
    idk->targettedEnemy = nullptr;
}

void TargetComponentEnemy::FindTarget() const {
    auto* idk = const_cast<TargetComponentEnemy*>(this); 
    idk->targettedEnemy = enemyOwner.FindClosestEnemy(GetFirePoint());
    if(targettedEnemy != nullptr) {
        idk->SubscribeTo(targettedEnemy);
    }
}