#pragma once

#include <game/entity/living_entity.h>
#include <game/movement_component/base_movement_component.h>
#include <game/combat/fighting_component.h>
#include <game/rendering/rendering_components/player_rendering_component.h>

#include <memory>


class Player: public LivingEntity
{
public:
    Player(Vector2D position, int rayon);
    virtual ~Player();

    void Attack();

    inline BaseMovementComponent* GetMovementComponent() const { return movementComponent.get(); }
    inline FightingComponent* GetFightingComponent() const { return fightingComponent.get(); }

private:
    std::unique_ptr<BaseMovementComponent> movementComponent = nullptr;
    std::unique_ptr<FightingComponent> fightingComponent = nullptr;
    std::unique_ptr<PlayerRenderingComponent> renderingComponent = nullptr;
};