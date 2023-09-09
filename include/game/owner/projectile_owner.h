#pragma once

#include <game/owner/owner.h>
#include <game/entity/projectile.h>
#include <game/tick_system/tickable.h>

class Game;

class ProjectileOwner : public Owner<Projectile>, public Tickable
{
public:
    ProjectileOwner(Game* game);

    virtual void Tick(float time);
private:
    Game* game;
};