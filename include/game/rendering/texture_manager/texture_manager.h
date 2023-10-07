#pragma once

#include <game/rendering/texture_manager/texture.h>

#include <unordered_map>
#include <vector>
#include <string>

class TextureManager
{
public:
    ~TextureManager();

    static TextureManager* GetInstance();
    static void DeleteInstance();

    const std::vector<sf::Texture>& FindTexture(std::string textureKey);
    
private:
    TextureManager();
    
    Texture& LoadTexture(std::string textureKey);

private:
    std::unordered_map<std::string, Texture> textures;

    static TextureManager* instance;
};