#include <game/rendering/texture_manager/texture.h>

#include <filesystem>
#include <iostream>

Texture::Texture(std::string name)
{   
    std::string path = ressourcePath + "/assets/" + name; 
    if (std::filesystem::is_directory(path)) {
        int count = 0;
        for (const auto& entry : std::filesystem::directory_iterator(path))
        {   
            textures.emplace(textures.end());
            textures[count++].loadFromFile(entry.path().string());
        }
    } else {
        textures.emplace(textures.end());
        textures[0].loadFromFile(path);
    }
}

std::string Texture::ressourcePath = std::filesystem::current_path().string();