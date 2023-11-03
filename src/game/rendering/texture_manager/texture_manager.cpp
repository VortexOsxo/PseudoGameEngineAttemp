#include <game/rendering/texture_manager/texture_manager.h>

#include <iostream>

TextureManager::TextureManager()
{}

TextureManager::~TextureManager()
{

}

TextureManager* TextureManager::GetInstance() 
{
    if (instance == nullptr)
    {
        instance = new TextureManager();
    }
    return instance;
}

void TextureManager::DeleteInstance()
{
    if (instance != nullptr)
    {
        delete instance;
    }
}

const std::vector<sf::Texture>& TextureManager::FindTexture(std::string textureKey)
{
    if (textures.find(textureKey) == textures.end()) {
        // std::cout << "loaded: " << textureKey << std::endl;
        return LoadTexture(textureKey).GetTextures();
    }
    return textures.find(textureKey)->second.GetTextures();
}

Texture& TextureManager::LoadTexture(std::string textureKey)
{
    return textures.emplace(textureKey, textureKey).first->second;
}

TextureManager* TextureManager::instance = nullptr;