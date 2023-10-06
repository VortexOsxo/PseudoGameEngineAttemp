#pragma once

#include <game/ai/ai_controller_base.h>

class Enemy;

class AIControllerRusher : public AIControllerBase
{
public:
    AIControllerRusher(Enemy* InEnemy);
    virtual ~AIControllerRusher() = default;

    virtual void Tick(float Time) override;
};