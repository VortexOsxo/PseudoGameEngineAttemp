#include <game/entity/enemy/building/enemy_build_director.h>

#include <game/game.h>
#include <game/combat/targeting_type.h>
#include <game/combat/fighting_component.h>
#include <game/combat/weapon/builder/WeaponBuilder.h>

#include <game/ai/ai_controller_default.h>
#include <game/ai/ai_controller_rusher.h>

#include <Utils/Vector2D.h>

EnemyBuildDirector::EnemyBuildDirector(EnemyOwner* enemyOwner)
    : enemyOwner(enemyOwner) {}

std::unique_ptr<Enemy> EnemyBuildDirector::RequestEnemy(const SpawnOrder& spawnOrder)
{
    std::unique_ptr<Enemy> e;
    if (spawnOrder.type == "default") {
        FightingComponent* fightingComponent = new FightingComponent();

        e = std::make_unique<Enemy>(spawnOrder.location, 25.f);

        WeaponBuilder builder;
        builder.SetProjectileTarget(TargetingType::Player);
        builder.UseCibleTargetting(e->GetPosition(), Game::GetInstance()->GetPlayer()->GetPosition());
        fightingComponent->SetupWeapon(builder.GetWeapon());

        e->SetFightingComponent(fightingComponent);

        AIControllerBase* AIController = new AIControllerDefault(e.get());
        e->SetAIController(AIController);
        
    } else if (spawnOrder.type == "rusher") {
        FightingComponent* fightingComponent = new FightingComponent();

        e = std::make_unique<Enemy>(spawnOrder.location, 25.f);

        WeaponBuilder builder;
        builder.SetProjectileTarget(TargetingType::Player);
        builder.UseCibleTargetting(e->GetPosition(), Game::GetInstance()->GetPlayer()->GetPosition());
        fightingComponent->SetupWeapon(builder.GetWeapon());

        e->SetFightingComponent(fightingComponent);

        AIControllerBase* AIController = new AIControllerRusher(e.get());
        e->SetAIController(AIController);
    }
    
    return std::move(e);
}