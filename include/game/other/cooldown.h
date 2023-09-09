#pragma once

#include "game/tick_system/tickable.h"

class Cooldown : public Tickable
{
public:
    Cooldown(float cooldownTime);
    virtual ~Cooldown() = default;

    virtual void Tick(float time) override;

    inline bool Available() { return actualTime <= 0; }
    inline void Reset() { actualTime = baseTime; }

private:
    const float baseTime;
    float actualTime;
};