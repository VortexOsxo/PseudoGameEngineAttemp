#include <game/drawer/game_drawer.h>

#include <game/map/map.h>
#include <game/entity/entity.h>

GameDrawer::GameDrawer(sf::RenderWindow* inWindow) 
    :window(inWindow)
{
    circle = sf::CircleShape(1);

    mapBound = sf::CircleShape(1.f);
    mapBound.setFillColor(sf::Color::Transparent);
    mapBound.setOutlineThickness(10.f); 
    mapBound.setOutlineColor(sf::Color::White);
}

void GameDrawer::SetRelativePosition(const Vector2D& newRelativePosition)
{
    relativePosition.SetFirst(window->getSize().x/2.f - newRelativePosition[0]);
    relativePosition.SetSecond(window->getSize().y/2.f - newRelativePosition[1]);
}

void GameDrawer::DrawEntity(Entity* entity)
{
    Vector2D pos = entity->GetPosition();
    const float rayon = static_cast<float>(entity->GetRayon());
    circle.setPosition(relativePosition[0] + pos[0] - rayon, relativePosition[1] + pos[1] - rayon);
    circle.setRadius(rayon);
    circle.setFillColor(sf::Color::Blue);
    window->draw(circle);
}

void GameDrawer::DrawHealthBar(float currentHealth, float maxHealth) 
{
    sf::Vector2f barPosition(window->getSize().x - 160, window->getSize().y - 40);
    sf::Vector2f barSize(150, 20);

    float greenBarWidth = (currentHealth / maxHealth) * barSize.x;

    sf::RectangleShape backgroundRect(barSize);
    backgroundRect.setPosition(barPosition);
    backgroundRect.setFillColor(sf::Color(128, 128, 128));

    sf::RectangleShape healthRect(sf::Vector2f(greenBarWidth-4, barSize.y-4));
    healthRect.setPosition(barPosition + sf::Vector2f(2,2));
    healthRect.setFillColor(sf::Color(0, 192, 0)); 

    window->draw(backgroundRect);
    window->draw(healthRect);
}

void GameDrawer::DrawMap(Map* map) 
{
    mapBound.setRadius(map->GetRayon());
    mapBound.setPosition(relativePosition[0]-750.f, relativePosition[1]-750.f);
    window->draw(mapBound);

    sf::Shape* shape = map->GetDrawableShape();
    sf::Vector2f base_pos = shape->getPosition();
    shape->setPosition(relativePosition[0] + base_pos.x, relativePosition[1] + base_pos.y);
    window->draw(*shape);
}
