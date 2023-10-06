#pragma once

#include "game/tick_system/tickable.h"

class Enemy;

class AIControllerBase : public Tickable
{
public:
    AIControllerBase(Enemy* InEnemy);
    virtual ~AIControllerBase() = default;

protected:
    Enemy* enemy = nullptr;
};