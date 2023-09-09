#include <game/Other/Cooldown.h>

#include <iostream>

Cooldown::Cooldown(float cooldownTime)
    : baseTime(cooldownTime * 1000.f)
{
    actualTime = 0.f;
}

void Cooldown::Tick(float time)
{
    if (actualTime > 0)
    {
        actualTime -= time;
    }
}


