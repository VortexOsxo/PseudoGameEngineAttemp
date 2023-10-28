#include <game/entity/living_entity_observer.h>

#include <game/entity/living_entity.h>

#include <algorithm>
#include <iostream>

LivingEntityObserver::~LivingEntityObserver()
{

}

void LivingEntityObserver::SubscribeTo(LivingEntity* publisher)
{
    publisher->AddObserver(this);
    publishers.push_back(publisher);
}

void LivingEntityObserver::UnsubscribeFrom(LivingEntity* publisher)
{
    publisher->RemoveObserver(this);
    auto it = std::find(publishers.begin(), publishers.end(), publisher);
    if (it == publishers.end()) return;
    publishers.erase(it);
}
