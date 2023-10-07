#include <game/rendering/sprite.h>

#include <game/rendering/texture_manager/texture_manager.h>

#include <iostream>

Sprite::Sprite(std::string name)
{
    bool first = true;
    for (const auto& texture : TextureManager::GetInstance()->FindTexture(name))
    {
        if (first) {
            first = false;
            size = Vector2D(texture.getSize().x, texture.getSize().y);
        }
        sprites.emplace(sprites.end());
        sprites[frameNumber].setTexture(texture);
        sprites[frameNumber].setOrigin(size.x/2, size.y/2);
        ++frameNumber;
    }
}

void Sprite::SetPosition(const Vector2D &position)
{
    sprites[frame].setPosition(position.x, position.y);
}

void Sprite::SetRotation(float rotation)
{
    sprites[frame].setRotation(rotation);
}

void Sprite::SetPositionAll(const Vector2D &position)
{
    for (auto& sprite: sprites)
    {
        sprite.setPosition(position.x, position.y);
    }
}

void Sprite::SetRotationAll(float rotation)
{
    for (auto& sprite: sprites)
    {
        sprite.setRotation(rotation);
    }
}

sf::Sprite& Sprite::GetDrawable()
{
    sf::Sprite& sprite = sprites[frame];
    frame = (frame + 1) % frameNumber;
    return sprite;
}
