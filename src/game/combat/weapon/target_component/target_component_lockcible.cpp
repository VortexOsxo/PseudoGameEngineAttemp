#include <game/combat/weapon/target_component/target_component_lockcible.h>

#include <game/entity/entity.h>
#include <Utils/Vector2D.h>

TargetComponentLockCible::TargetComponentLockCible(const Vector2D& inFirePoint, const Vector2D& inCible)
    : TargetComponentBase(inFirePoint), cible(inCible) {}

Vector2D TargetComponentLockCible::GetDirection() const
{
    float x = cible[0] - GetFirePoint()[0];
    float y = cible[1] - GetFirePoint()[1];
    return { x, y };
}