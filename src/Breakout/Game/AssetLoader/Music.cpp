#include "pch.h"
#include "Music.h"

namespace Breakout
{

    Music::Music(const std::string& path)
    {
        if(!(openFromFile(Utils::getResourcesPath() + "/Musics/" + path)))
        {
            std::cerr << " Failed to load music file" << std::endl;
            return;
        }
    }
    
}
