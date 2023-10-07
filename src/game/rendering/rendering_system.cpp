#include <game/rendering/rendering_system.h>
#include <game/rendering/rendering_component.h>

#include <Utils/Window.h>
#include <algorithm>
#include <iostream>

RenderingSystem *RenderingSystem::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = new RenderingSystem();
    }
    return Instance;
}

void RenderingSystem::DeleteInstance()
{
    if (Instance != nullptr)
    {
        delete Instance;
    }
}

RenderingSystem::RenderingSystem()
    : window(Window::GetInstance()->GetWindow()) {}


void RenderingSystem::Render() 
{
    for (auto& renderComponent: renderingComponents)
    {
        renderComponent->Render(window);
    }
    for (Animation& animation: animations)
    {
        animation.Render(window);
    }
    auto end = std::remove_if(animations.begin(), animations.end(), [] (Animation& a) { return a.IsOver(); });
    animations.erase(end, animations.end());
}

const RenderingSystem* RenderingSystem::AddRenderingComponent(RenderingComponent* renderComponent)
{
    renderingComponents.push_back(renderComponent);
    return this;
}

void RenderingSystem::RemoveRenderingComponent(RenderingComponent* renderComponent)
{
    for (auto it = renderingComponents.begin(); it != renderingComponents.end(); ++it)
    {
        if (*it == renderComponent)
        {
            renderingComponents.erase(it);
            return;
        }
    }
}

void RenderingSystem::Clear()
{
    renderingComponents.clear();
}

void RenderingSystem::SetRelativePosition(const Vector2D &newRelativePosition)
{
    relativePosition.x = (window->getSize().x/2.f - newRelativePosition[0]);
    relativePosition.y = (window->getSize().y/2.f - newRelativePosition[1]);
}

void RenderingSystem::PlayAnimation(const std::string &name, const Vector2D &position)
{
    animations.emplace(animations.end(), name, position);
}

RenderingSystem* RenderingSystem::Instance = nullptr;