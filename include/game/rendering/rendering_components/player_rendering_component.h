#pragma once

#include <game/rendering/rendering_components/spaceshift_rendering_component.h>

class PlayerRenderingComponent : public SpaceshiftRenderingComponent
{
public:
    PlayerRenderingComponent(Entity* entity);
    virtual ~PlayerRenderingComponent() = default;

    virtual void Render(sf::RenderWindow* window) override;

};