#include "pch.h"
#include "Sound.h"

namespace Breakout
{

    Sound::Sound(const std::string& path)
    {
        if(!m_buffer.loadFromFile(Utils::getResourcesPath() + "sfx/" + path))
        {
            std::cerr << " Failed to load sound file" << std::endl;
            return;
        }
        setBuffer(m_buffer);
    }
    
}
