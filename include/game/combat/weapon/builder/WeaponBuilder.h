class WeaponBase;
enum class TargetingType;
class Vector2D;
class EnemyOwner;

class WeaponBuilder
{
public:
    WeaponBuilder();
    ~WeaponBuilder();

    void Reset();

    WeaponBase* GetWeapon();

    void SetProjectileTarget(TargetingType targetType);

    void UseMouseTargetting(const Vector2D& firePos);
    void UseCibleTargetting(const Vector2D& firePos, const Vector2D& cible);
    void UseEnemyTargetting(const Vector2D& firePos, const EnemyOwner& enemyOwner);

private:
    WeaponBase* weapon;

    bool bTargetingSet = false;
};