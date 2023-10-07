#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <Utils/Vector2D.h>

class Animation
{
public:
    Animation(const std::string& name, const Vector2D& position);
    ~Animation() = default;

    void Render(sf::RenderWindow* window);

    bool IsOver() const;

private:
    Vector2D position;
    int speed = 3;
    int frame = 0;
    int frameNumber = 0;
    std::vector<sf::Sprite> sprites;
};