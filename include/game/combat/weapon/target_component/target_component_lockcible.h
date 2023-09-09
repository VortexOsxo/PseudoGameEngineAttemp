#include <game/combat/weapon/target_component/target_component_base.h>

class TargetComponentLockCible : public TargetComponentBase
{
public:
    TargetComponentLockCible(const Vector2D& inFirePoint, const Vector2D& cible);
    virtual ~TargetComponentLockCible() = default;

    virtual Vector2D GetDirection() const override;

private:
    const Vector2D& cible;
};