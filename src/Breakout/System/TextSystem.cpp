#include "pch.h"
#include "TextSystem.h"

TextSystem::~TextSystem()
{
    m_texts.clear();
}

void TextSystem::AddText(const Breakout::Text* entity)
{
    if (entity == nullptr) return;
    m_texts.push_back(entity);   
}
void TextSystem::RemoveText(const Breakout::Text* entity)
{
    if (entity == nullptr) return;
    auto it = std::find(m_texts.begin(), m_texts.end(), entity);
    m_texts.erase(it);
}

void TextSystem::Render(sf::RenderTexture* _tex) const
{
    for (const Breakout::Text* text : m_texts)
    {
        _tex->draw(*text);
    }
}

