#include <game/combat/weapon/target_component/target_component_mouse.h>

#include <Utils/Vector2D.h>
#include <SFML/Graphics.hpp>
#include <Utils/Window.h>

TargetComponentMouse::TargetComponentMouse(const Vector2D& inFirePoint)
    : TargetComponentBase(inFirePoint) 
    {
        auto* window = Window::GetInstance()->GetWindow();
        halfWidth = window->getSize().x / 2;
        halfHeight = window->getSize().y / 2;
    }

Vector2D TargetComponentMouse::GetDirection() const
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    int x = mousePosition.x - halfWidth;
    int y = mousePosition.y - halfHeight;

    return { static_cast<float>(x), static_cast<float>(y) };
}