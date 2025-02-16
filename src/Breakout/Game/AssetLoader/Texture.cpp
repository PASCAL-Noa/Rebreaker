#include "pch.h"
#include "Texture.h"

namespace Breakout
{
    Texture::Texture(const std::string& path) : sf::Texture()
    {
        if(!loadFromFile(Utils::getResourcesPath() + path))
        {
            std::cerr << "Failed to load texture from " << path << std::endl;
        }
        setSmooth(true);
    }

}
