#include <game/rendering/texture_manager/texture.h>

#include <filesystem>
#include <iostream>

Texture::Texture(std::string name)
{    
    if (std::filesystem::is_directory(name)) {
        int count = 0;
        for (const auto& entry : std::filesystem::directory_iterator(name))
        {   
            textures.emplace(textures.end());
            textures[count++].loadFromFile(entry.path().string());
        }
    } else {
        textures.emplace(textures.end());
        textures[0].loadFromFile(name);
    }
}