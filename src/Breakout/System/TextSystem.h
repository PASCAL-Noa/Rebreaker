#pragma once

class TextSystem
{
public:
    TextSystem() = default;
    ~TextSystem();
    void AddText(const Breakout::Text* entity);
    void RemoveText(const Breakout::Text* entity);

    void Render(sf::RenderTexture* _tex) const;

private:
    std::vector<const Breakout::Text*> m_texts;
};
