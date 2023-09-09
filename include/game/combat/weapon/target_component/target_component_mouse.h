#include <game/combat/weapon/target_component/target_component_base.h>

class Entity;

class TargetComponentMouse : public TargetComponentBase
{
public:
    TargetComponentMouse(const Vector2D& inFirePoint);
    virtual ~TargetComponentMouse() = default;

    virtual Vector2D GetDirection() const override;
private:
    float halfHeight = 0;
    float halfWidth = 0;
};