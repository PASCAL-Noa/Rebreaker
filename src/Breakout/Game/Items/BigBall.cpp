#include "pch.h"
#include "BigBall.h"
#include "../Ball.h"

namespace Breakout
{
    
    BigBall::BigBall() : Effect(5)
    {
        for (Ball* ball : Game::getUpdateSystem().GetAllEntityOfType<Ball>())
        {
            ball->setBallScale(3, sf::Vector2f(90, 90));
        }
    }

    void BigBall::Update(float dt)
    {
        m_effectDuration -= dt;
        if (m_effectDuration <= 0)
        {
            for (Ball* ball : Game::getUpdateSystem().GetAllEntityOfType<Ball>())
                ball->setBallScale(1, sf::Vector2f(30, 30));
            delete this;
        }
    }
    
}