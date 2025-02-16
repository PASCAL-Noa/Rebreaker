#pragma once

namespace Breakout
{
    
    class Sound : public sf::Sound
    {
    public:
        Sound(const std::string& path);

    private:
        sf::SoundBuffer m_buffer;
    };
    
}


