#include <game/combat/weapon/target_component/target_component_base.h>

#include <Utils/Vector2D.h>

TargetComponentBase::TargetComponentBase(const Vector2D& inFirePoint)
    : firePoint(inFirePoint) {}

Vector2D TargetComponentBase::GetFirePoint() const 
{
    return { firePoint[0], firePoint[1] };
}