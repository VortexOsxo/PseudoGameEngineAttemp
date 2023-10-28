#pragma once 

#include <vector>

class LivingEntity;

class LivingEntityObserver
{
friend LivingEntity;

public:
    LivingEntityObserver() = default;
    virtual ~LivingEntityObserver();

    void SubscribeTo(LivingEntity* publisher);

    void UnsubscribeFrom(LivingEntity* publisher);

private:
    virtual void ReceiveNotification() const =0;

private:
    std::vector<LivingEntity*> publishers;
};