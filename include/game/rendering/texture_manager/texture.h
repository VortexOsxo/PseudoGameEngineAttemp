#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Texture
{
public:
    Texture(std::string name);

    const std::vector<sf::Texture>& GetTextures() { return textures; }

private:
    std::vector<sf::Texture> textures;

};