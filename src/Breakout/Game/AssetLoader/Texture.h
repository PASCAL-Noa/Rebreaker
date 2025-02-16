#pragma once

namespace Breakout
{
    
    class Texture : public sf::Texture
    {
    public:
        explicit Texture(const std::string& path);
        ~Texture() = default;
    };
    
}

