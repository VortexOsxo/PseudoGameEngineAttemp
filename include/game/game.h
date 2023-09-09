#pragma once

#include <game/entity/player.h>
#include <game/map/map.h>
#include <game/owner/enemy_owner.h>
#include <game/owner/projectile_owner.h>

#include <context.h>
#include <memory>

class TickManager;

class Game : public Context
{
private:
    Game();
public:
    ~Game();

    static Game* GetInstance();
    void SpawnPlayer();

    virtual bool Update(float time) override;
    virtual bool HandleEventsImplementation(float time) override;
    virtual bool HandleEventIntern(float time, const sf::Event& event) override;

    virtual void Draw() override;


    inline Player* GetPlayer() { return player.get(); }
    inline Map* GetMap() { return map.get(); }
    inline EnemyOwner* GetEnemyOwner() { return enemyOwner.get(); }
    inline ProjectileOwner* GetProjectileOwner() { return projectileOwner.get(); }

private:
    TickManager* tickManager = nullptr;

    std::unique_ptr<Player> player = nullptr;
    std::unique_ptr<Map> map = nullptr;
    std::unique_ptr<EnemyOwner> enemyOwner = nullptr;
    std::unique_ptr<ProjectileOwner> projectileOwner = nullptr;  

private:
    static Game* instance;
};