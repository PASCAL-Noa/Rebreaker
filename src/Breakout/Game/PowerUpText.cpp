#include "pch.h"
#include "PowerUpText.h"

#include "Paddle.h"
#include "AssetLoader/AssetLoader.hpp"

namespace Breakout
{
    PowerUpText::PowerUpText(const std::string& powerName) : m_text(new Text(&AssetLoader::textFont, powerName)), m_paddle(Game::getUpdateSystem().GetFirstEntityOfType<Paddle>())
    {
        m_text->setOrigin(m_text->getGlobalBounds().width, m_text->getGlobalBounds().height);
        m_text->setCharacterSize(40);
        m_text->setOutlineColor(sf::Color::Red);

        m_text->setScale(2, 2);
        m_text->setPosition(m_paddle->getCenter().x, m_paddle->getCenter().y + 150);
        m_text->setFillColor(sf::Color::Yellow);
        
        new PositionTweener(m_text, m_paddle->getCenter() - sf::Vector2f(0, Utils::randomFloat(100, 180)), 1, Tweening::EaseInOutQuint);
    }

    PowerUpText::~PowerUpText()
    {
        delete m_text;
    }


    void PowerUpText::Update(float dt)
    {
        if(m_elapsedTime >= POWER_UP_TEXT_DURATION)
        {
            delete this;
            m_elapsedTime = 0;
            return;
        }
        
        m_elapsedTime += dt;
        sf::Color color = m_text->getFillColor();
        color.a = (1.0f - m_elapsedTime/POWER_UP_TEXT_DURATION) * 255;
        m_text->setFillColor(color);
    }


}
