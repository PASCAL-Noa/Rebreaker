#include "pch.h"
#include "Font.h"

namespace Breakout
{
    Font::Font(const std::string& path) : sf::Font()
    {
        if(!loadFromFile(Utils::getResourcesPath() + "Fonts/" + path))
            std::cerr << "Failed to load font" << std::endl;
    }

}
