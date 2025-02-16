#pragma once

namespace Breakout
{
    class Font;
    
    class Text : public sf::Text
    {

    public:
        Text(const Font*, const std::string& defaultText);
        Text(const Font*, const std::wstring& defaultText);
        ~Text() override;

        void SetText(const std::string& newText);
    };
}

