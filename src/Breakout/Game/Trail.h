#pragma once

namespace Breakout
{
    class Ball;
    
    class Trail : Entity, Renderable
    {
    public:
        Trail(Ball* ball);

        void Update(float dt) override;

    private:
        Ball* m_ball;
    };
    
}

