#pragma once

#include <game/entity/entity.h>

class LivingEntity : public Entity
{
public:
    LivingEntity(Vector2D position, int rayon, float health);
    virtual ~LivingEntity() = default;

    virtual void TakeDamage(float damage);

    float GetHealth() const { return health; }
    float GetMaxHealth() const { return maxHealth; }

private:
    float health;
    float maxHealth;
};