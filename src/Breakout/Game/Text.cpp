#include "pch.h"
#include "Text.h"

#include "AssetLoader/Font.h"

namespace Breakout
{
    
    Text::Text(const Font* font, const std::string& text)
    {
        setFont(*font);
        setFillColor(sf::Color::White);
        setCharacterSize(20);
        setString(text);

        Game::getTextSystem().AddText(this);
    }

    Text::Text(const Font* font, const std::wstring& text)
    {
        setFont(*font);
        setFillColor(sf::Color::White);
        setCharacterSize(20);
        setString(text);
        Game::getTextSystem().AddText(this);
    }

    Text::~Text()
    {
        Game::getTextSystem().RemoveText(this);
    }

    void Text::SetText(const std::string& newText)
    {
        setString(newText);
    }
    
}
