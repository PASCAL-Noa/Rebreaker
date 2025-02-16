#include "pch.h"
#include "Paddle.h"

#include "AssetLoader/AssetLoader.hpp"

namespace Breakout
{
    class Ball;

    Paddle::Paddle() :
    Collidable(this, sf::Vector2f(120.0, 30.0)),
    Renderable(&AssetLoader::paddleTexture,this)
    {
        setPosition(PADDLE_X, PADDLE_Y);
        setOrigin(60, 15);
    }

    void Paddle::Update(const float dt)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (getLeft()  >= 95)
            {
                m_currentSpeed = Utils::Lerp(m_currentSpeed, -PADDLE_SPEED, 0.06);
                move(dt * sf::Vector2f(m_currentSpeed, 0));
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (getRight() <= WINDOW_WIDTH - 95)
            {
                m_currentSpeed = Utils::Lerp(m_currentSpeed, PADDLE_SPEED, 0.06);
                move(dt * sf::Vector2f(m_currentSpeed, 0));
            }
        }
        else
        {
            if (getRight() <= WINDOW_WIDTH - 95 && getLeft() >= 95)
            {
                m_currentSpeed = Utils::Lerp(m_currentSpeed, 0, 0.004);
                move(dt * sf::Vector2f(m_currentSpeed, 0));
            }
        }
    }

    void Paddle::OnHit(Collider* collider)
    {
        PlaySound(&AssetLoader::paddleSound, 20, Utils::randomFloat(0.9f, 1.1f));

        TweenScale(sf::Vector2f(m_scaleX-.2f, getScale().y-.2f), 0.2f, [&]
        {
            TweenScale(sf::Vector2f(m_scaleX, 1), 0.2f, Tweening::EaseOutQuart);
        }, Tweening::EaseInOutQuad);
        
    }

    float Paddle::getCurrentSpeed() const
    {
        return m_currentSpeed;
    }

    float Paddle::getCurrentScale()
    {
        return m_scaleX;
    }

    void Paddle::setPaddleScale(float x)
    {
        m_scaleX = x;
        TweenScale(sf::Vector2f(m_scaleX, getScale().y), 0.2f, Tweening::EaseInOutQuad);
    }
}
