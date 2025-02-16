#include "pch.h"
#include "Shader.h"

namespace Breakout
{
    Shader::Shader(const std::string& path, sf::Shader::Type type) : sf::Shader()
    {
        if(!loadFromFile(Utils::getResourcesPath() + "Shaders/" + path, type))
        {
            std::cerr << "Failed to load shader from " << path << std::endl;
        }
    }

}
