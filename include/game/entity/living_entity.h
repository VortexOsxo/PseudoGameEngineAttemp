#pragma once

#include <game/entity/entity.h>
#include <vector>

class LivingEntityObserver;

class LivingEntity : public Entity
{
friend LivingEntityObserver;

public:
    LivingEntity(Vector2D position, int rayon, float health);
    virtual ~LivingEntity();

    virtual void TakeDamage(float damage);
    virtual void Kill();

    float GetHealth() const { return health; }
    float GetMaxHealth() const { return maxHealth; }

public:
    void AddObserver(const LivingEntityObserver* observer);
    void RemoveObserver(const LivingEntityObserver* observer);

private:
    void NotifyObservers();

private:
    std::vector<const LivingEntityObserver*> observers;

    float health;
    float maxHealth;
};