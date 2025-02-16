#include "pch.h"
#include "Brick.h"

#include "BrickComboText.h"
#include "Level.h"
#include "AssetLoader/AssetLoader.hpp"

namespace Breakout
{
    Brick::Brick(unsigned int healthPoint, sf::Color color) :
    Collidable(this, sf::Vector2f(80.0, 27.0)),
    Renderable(&AssetLoader::brickTexture, &AssetLoader::brickShader, this),
    m_color(color),
    m_healthPoint(healthPoint),
    m_healthPointMax(healthPoint)
    {
        Game::AddBrick(this);
        setOrigin(40, 13.5f);
    }

    Brick::~Brick()
    {
        Game::RemoveBrick(this);
    }

    sf::Shader* Brick::getShader()
    {
        m_color.a = 255/m_healthPointMax * m_healthPoint;
        m_shader->setUniform("color", sf::Glsl::Vec4(m_color));
        m_shader->setUniform("crack_texture", AssetLoader::crackTexture);
        m_shader->setUniform("crack_amount", (m_healthPointMax - m_healthPoint) * 1.0f/m_healthPointMax*2);
        return m_shader;
    }

    unsigned int Brick::getHealthPoint() const
    {
        return m_healthPoint;
    }

    void Brick::setHealthPoint(const unsigned int hp)
    {
        m_healthPoint = hp;
    }

    const sf::Color& Brick::getColor() const
    {
        return m_color;
    }

    unsigned int Brick::getScore() const
    {
        return m_score;
    }

    void Brick::Update(float dt) {}

    void Brick::OnHit(Collider* collider)
    {
        if (dynamic_cast<Ball*>(collider) && m_healthPoint <= 0)
        {
            CameraShake(sf::Vector2f(1, 1), .2f, Tweening::EaseOutQuart);
            Game::getScoreManager().AddScore(m_score);
            new BrickComboText("x" + std::to_string(Game::getScoreManager().GetScoreSize()), getPosition());
            delete this;
        }
    }
}




