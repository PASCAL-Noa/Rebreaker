#pragma once


namespace Breakout
{
    
    class Font : public sf::Font
    {
    public:
        explicit Font(const std::string& path);
        ~Font() = default;
    };
    
}

