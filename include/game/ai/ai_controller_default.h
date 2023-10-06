#pragma once

#include <game/ai/ai_controller_base.h>

class Enemy;

class AIControllerDefault : public AIControllerBase
{
public:
    AIControllerDefault(Enemy* InEnemy);
    virtual ~AIControllerDefault() = default;

    virtual void Tick(float Time) override;
};