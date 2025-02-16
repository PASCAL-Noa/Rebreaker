#pragma once
#include "Effect.h"

namespace Breakout
{
    class Ball;

    class BigBall : public Effect
    {
    public:
        BigBall();

        void Update(float dt) override;
        const std::string getEffectName() override {return "Big Ball";}
    };
}
