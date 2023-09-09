#include <game/rendering/rendering_components/player_rendering_component.h>

#include <game/rendering/rendering_system.h>
#include <game/entity/player.h>

PlayerRenderingComponent::PlayerRenderingComponent(Player* player)
    : player(player) {}

void PlayerRenderingComponent::Render(sf::RenderWindow* window)
{
    Vector2D pos = player->GetPosition();
    const float rayon = static_cast<float>(player->GetRayon());

    Vector2D relativePosition = renderingSystem->GetRelativePosition();

    circle.setPosition(relativePosition[0] + pos[0] - rayon, relativePosition[1] + pos[1] - rayon);
    circle.setRadius(rayon);
    circle.setFillColor(sf::Color::Blue);
    window->draw(circle);

    sf::Vector2f barPosition(window->getSize().x - 160, window->getSize().y - 40);
    sf::Vector2f barSize(150, 20);

    float greenBarWidth = (player->GetHealth() / player->GetMaxHealth()) * barSize.x;

    sf::RectangleShape backgroundRect(barSize);
    backgroundRect.setPosition(barPosition);
    backgroundRect.setFillColor(sf::Color(128, 128, 128));

    sf::RectangleShape healthRect(sf::Vector2f(greenBarWidth-4, barSize.y-4));
    healthRect.setPosition(barPosition + sf::Vector2f(2,2));
    healthRect.setFillColor(sf::Color(0, 192, 0)); 

    window->draw(backgroundRect);
    window->draw(healthRect);
}