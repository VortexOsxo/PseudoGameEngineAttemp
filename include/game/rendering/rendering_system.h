#pragma once

#include <SFML/Graphics.hpp>
#include <Utils/Vector2D.h>
#include <vector>

class RenderingComponent;

typedef std::vector<RenderingComponent*> RenderingComponents;

class RenderingSystem
{
friend RenderingComponent;

public:
    static RenderingSystem* GetInstance();
    static void DeleteInstance();
    
    void Render();
    void Clear();

    void SetRelativePosition(const Vector2D& newRelativePosition);
    inline const Vector2D& GetRelativePosition() const { return relativePosition; }

private:
    RenderingSystem();

    const RenderingSystem* AddRenderingComponent(RenderingComponent* renderComponent);
    void RemoveRenderingComponent(RenderingComponent* renderComponent);

    RenderingComponents renderingComponents;
    sf::RenderWindow* window = nullptr;
    Vector2D relativePosition = Vector2D::ZeroVector;

    static RenderingSystem* Instance;
};