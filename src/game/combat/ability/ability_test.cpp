#include <game/combat/ability/ability_test.h>

#include <game/game.h>
#include <iostream>

AbilityTest::AbilityTest(const Vector2D& position, TargetingType abilityTarget) 
    : Ability(abilityTarget), position(position) {}

void AbilityTest::Use()
{
    Player* player = Game::GetInstance()->GetPlayer();

    if ((player->GetPosition() - position).Length() < 150)
        player->TakeDamage(damage);
}