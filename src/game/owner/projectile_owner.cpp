#include <game/owner/projectile_owner.h>

#include <game/game.h>

#include <memory>
#include <iostream>

ProjectileOwner::ProjectileOwner(Game* game) 
    : game(game)
{}

void ProjectileOwner::Tick(float time)
{
    Map* map = game->GetMap();

    for (auto& Ownee : Ownees)
    {
        Ownee->Tick(time);
        switch (Ownee->GetTargetType()) 
        {
            case TargetingType::Player:
                if (Ownee->Collide(*(game->GetPlayer()))) 
                {
                    Ownee->HitEntity(game->GetPlayer());
                    Ownee->SetToDelete();
                }
                break;
            case TargetingType::Enemy:
                for (auto&& enemy : game->GetEnemyOwner()->GetOwnees())
                {
                    if (Ownee->Collide(*(enemy)))
                    {
                        Ownee->HitEntity(enemy.get());
                        Ownee->SetToDelete();
                    }
                }
                break;
        }

        if (! map->IsInside(Ownee.get()))
        {
            Ownee->SetToDelete();
        }
    }

    CleanUp();
}


