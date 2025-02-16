#include "pch.h"
#include "MultiBall.h"
#include "../Ball.h"
#include "../Trail.h"

namespace Breakout
{
    
    MultiBall::MultiBall() : Effect(.2)
    {
        for (Ball* ball : Game::getUpdateSystem().GetAllEntityOfType<Ball>())
        {
            Ball* clonedBall = new Ball();
            clonedBall->setPosition(ball->getPosition());
            clonedBall->move(-ball->getDirection().x * ball->getSize().x, 0);
            clonedBall->changeDirection(clonedBall->getDirection().x * -1, 1);
            clonedBall->attachTrail();
        }
    }

    void MultiBall::Update(float dt)
    {
        m_effectDuration -= dt;
        if (m_effectDuration < 0)
        {
            delete this;
        }
    }
}

