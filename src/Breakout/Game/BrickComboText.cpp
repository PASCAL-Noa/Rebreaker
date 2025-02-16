#include "pch.h"
#include "BrickComboText.h"

#include "AssetLoader/AssetLoader.hpp"

namespace Breakout
{
    BrickComboText::BrickComboText(const std::string& text, const sf::Vector2f& pos) : m_text(new Text(&AssetLoader::textFont, "x1"))
    {
        m_text->SetText(text);
        m_text->setPosition(pos);
        m_text->setCharacterSize(40);
        m_text->setRotation(Utils::randomFloat(-15, 15));
        new ScaleTweener(m_text, sf::Vector2f(2, 2), 1, Tweening::EaseOutElastic);
    }
    
    BrickComboText::~BrickComboText() { delete m_text; }

    void BrickComboText::Update(float dt)
    {
        if (m_elapsedTime >= BRICK_TEXT_LIFETIME)
        {
            new ScaleTweener(m_text, sf::Vector2f(0, 0), 0.7, [&]()
            {
                delete this;
            },Tweening::EaseInElastic);
            m_elapsedTime = 0;
            return;
        }
        m_elapsedTime += dt;
    }
    
}
