#include <game/rendering/rendering_components/player_rendering_component.h>

#include <game/rendering/rendering_system.h>
#include <game/entity/player.h>

PlayerRenderingComponent::PlayerRenderingComponent(Entity* player)
    : SpaceshiftRenderingComponent(player, "D:/Program/Games/SpaceFighter/assets/player/ship.png",
                                           "D:/Program/Games/SpaceFighter/assets/player/engine/") 
{}

void PlayerRenderingComponent::Render(sf::RenderWindow* window)
{
    RenderSpaceshift(window);

    /// Render Health Bar
    Player* player = dynamic_cast<Player*>(entity);

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
