#include <game/rendering/rendering_system.h>
#include <game/rendering/rendering_component.h>

RenderingComponent::RenderingComponent()
{
    renderingSystem = RenderingSystem::GetInstance()->AddRenderingComponent(this);
}

RenderingComponent::~RenderingComponent()
{
   RenderingSystem::GetInstance()->RemoveRenderingComponent(this);
}
