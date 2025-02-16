#include "pch.h"
#include "BigPaddle.h"
#include "../Paddle.h"

namespace Breakout
{
    
    BigPaddle::BigPaddle() : Effect(10)
    {
        Paddle* paddle = Game::getUpdateSystem().GetFirstEntityOfType<Paddle>();
        paddle->setPaddleScale(3.0f);
        paddle->setOrigin(60, 15);
        paddle->setSize(sf::Vector2f(360, 30));
    }

    void BigPaddle::Update(float dt)
    {
        m_effectDuration -= dt;
        if (m_effectDuration <= 0)
        {
            Paddle* paddle = Game::getUpdateSystem().GetFirstEntityOfType<Paddle>();
            paddle->setPaddleScale(1.0f);
            paddle->setOrigin(60, 15);
            paddle->setSize(sf::Vector2f(120.0f, 30.f));
            delete this;
        }
    }
    
}
