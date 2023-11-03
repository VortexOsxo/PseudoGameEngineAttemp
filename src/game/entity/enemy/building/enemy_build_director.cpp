#include <game/entity/enemy/building/enemy_build_director.h>

#include <game/game.h>

#include <game/combat/fighting_component.h>
#include <game/combat/weapon/target_component/target_component_lockcible.h>

#include <game/combat/weapon/weapon_test.h>
#include <game/combat/ability/ability_test.h>

#include <game/ai/ai_controller_default.h>
#include <game/ai/ai_controller_rusher.h>

#include <Utils/Vector2D.h>

EnemyBuildDirector::EnemyBuildDirector(EnemyOwner* enemyOwner)
    : enemyOwner(enemyOwner) {}

std::unique_ptr<Enemy> EnemyBuildDirector::RequestEnemy(const SpawnOrder& spawnOrder)
{
    std::unique_ptr<Enemy> e;
    if (spawnOrder.type == "default") {
        e = std::make_unique<Enemy>(spawnOrder.location, 25.f, "klaed/fighter");

        FightingComponent* fightingComponent = new FightingComponent( new TargetComponentLockCible(e->GetPosition(), Game::GetInstance()->GetPlayer()->GetPosition()) );

        WeaponTest* weapon = new WeaponTest(fightingComponent);
        fightingComponent->SetupWeapon(weapon);

        e->SetFightingComponent(fightingComponent);

        AIControllerBase* AIController = new AIControllerDefault(e.get());
        e->SetAIController(AIController);
        
    } else if (spawnOrder.type == "rusher") {
        e = std::make_unique<Enemy>(spawnOrder.location, 25.f, "klaed/scout");

        FightingComponent* fightingComponent = new FightingComponent( new TargetComponentLockCible(e->GetPosition(), Game::GetInstance()->GetPlayer()->GetPosition()) );
        fightingComponent->SetupAbility(new AbilityTest(e->GetPosition()));
        e->SetFightingComponent(fightingComponent);

        AIControllerBase* AIController = new AIControllerRusher(e.get());
        e->SetAIController(AIController);
    }
    
    return std::move(e);
}