#include "pch.h"
#include "SpeedUp.h"
#include "../Ball.h"
#include "../Paddle.h"

namespace Breakout
{
    
    SpeedUp::SpeedUp() : Effect(10)
    {
    }

    void SpeedUp::Update(float dt)
    {
        m_effectDuration -= dt;
        if (m_effectDuration <= 0)
        {
            for (Ball* ball : Game::getUpdateSystem().GetAllEntityOfType<Ball>())
                ball->setSpeed(300);
            delete this;
        } else
        {
            
            for (Ball* ball : Game::getUpdateSystem().GetAllEntityOfType<Ball>())
                ball->setSpeed(600 * log(WINDOW_HEIGHT / (ball->getPosition().y+50)));
            
        }
    }
    
}

