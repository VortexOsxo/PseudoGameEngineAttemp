#pragma once

#include <game/rendering/rendering_component.h>

class Player;

class PlayerRenderingComponent : public RenderingComponent
{
public:
    PlayerRenderingComponent(Player* player);
    virtual ~PlayerRenderingComponent() = default;

    virtual void Render(sf::RenderWindow* window) override;

private:
    Player* player;
    sf::CircleShape circle = sf::CircleShape(1.f);
};