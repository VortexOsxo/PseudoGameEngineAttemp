#include "game/entity/living_entity.h"

#include <game/entity/living_entity_observer.h>
#include <algorithm>
#include <iostream>

LivingEntity::LivingEntity(Vector2D position, int rayon, float inHealth)
    : Entity(position, rayon), health(inHealth), maxHealth(inHealth)
{
}

LivingEntity::~LivingEntity()
{
    for(const LivingEntityObserver* observerC: observers)
    {
        LivingEntityObserver* observer = const_cast<LivingEntityObserver*>(observerC);
        observer->UnsubscribeFrom(this);
    }
}

void LivingEntity::TakeDamage(float damage)
{
    health -= damage;
    if (health > 0) return;

    NotifyObservers();
    Kill();
}

void LivingEntity::Kill()
{

}

void LivingEntity::AddObserver(const LivingEntityObserver* observer)
{
    observers.push_back(observer);
}

void LivingEntity::RemoveObserver(const LivingEntityObserver* observer)
{
    observers.erase(std::find(observers.begin(), observers.end(), observer));
}

void LivingEntity::NotifyObservers()
{
    for(const LivingEntityObserver* observer: observers)
    {
        observer->ReceiveNotification();
    }

}

