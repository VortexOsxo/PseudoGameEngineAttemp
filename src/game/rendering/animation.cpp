#include <game/rendering/animation.h>

#include <game/rendering/texture_manager/texture_manager.h>
#include <game/rendering/rendering_system.h>

#include <iostream>

Animation::Animation(const std::string& name, const Vector2D& position) 
    : position(position)
{
    Vector2D size;
    for (const auto& texture : TextureManager::GetInstance()->FindTexture(name))
    {
        size = Vector2D(texture.getSize().x, texture.getSize().y);
        sprites.emplace(sprites.end());
        sprites[frameNumber].setTexture(texture);
        sprites[frameNumber].setOrigin(size.x/2, size.y/2);
        ++frameNumber;
    }
}

void Animation::Render(sf::RenderWindow* window)
{
    if (IsOver()) return;
    Vector2D pos = position + RenderingSystem::GetInstance()->GetRelativePosition();
    sprites[frame/speed].setPosition(pos.x, pos.y);
    window->draw(sprites[frame++/speed]);
}

bool Animation::IsOver() const
{
    return frame/speed >= frameNumber;
}