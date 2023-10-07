#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <Utils/Vector2D.h>

class Sprite
{
public:
    Sprite(std::string name);
    ~Sprite() = default;

    void SetPosition(const Vector2D& position);
    void SetRotation(float rotation);

    void SetPositionAll(const Vector2D& position);
    void SetRotationAll(float rotation);

    const Vector2D& GetSize() const { return size; }

    sf::Sprite& GetDrawable();

private:
    Vector2D size;
    int frame = 0;
    int frameNumber = 0;
    std::vector<sf::Sprite> sprites;
};