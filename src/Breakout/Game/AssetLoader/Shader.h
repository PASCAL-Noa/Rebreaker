#pragma once


namespace Breakout
{
    
    class Shader : public sf::Shader
    {
    public:
        Shader(const std::string& path, sf::Shader::Type type);
        ~Shader() = default;
    };
    
}

