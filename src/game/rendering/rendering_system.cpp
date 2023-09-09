#include <game/rendering/rendering_system.h>
#include <game/rendering/rendering_component.h>

#include <Utils/Window.h>


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
    relativePosition.SetFirst(window->getSize().x/2.f - newRelativePosition[0]);
    relativePosition.SetSecond(window->getSize().y/2.f - newRelativePosition[1]);
}

RenderingSystem* RenderingSystem::Instance = nullptr;