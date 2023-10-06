#pragma once

#include <string>
#include <Utils/Vector2D.h>

class Animation
{
public:
    Animation(std::string path, Vector2D location);
    ~Animation() = default;

private:
    std::string path;
    Vector2D location;
}