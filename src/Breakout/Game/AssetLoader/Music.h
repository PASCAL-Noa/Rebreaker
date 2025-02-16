#pragma once

namespace Breakout
{
    class Music : public sf::Music
    {
    public:
        Music(const std::string& path);
        ~Music() = default;
    };
}
