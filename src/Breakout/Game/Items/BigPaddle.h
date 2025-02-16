#pragma once
#include "Effect.h"

namespace Breakout
{
    class Ball;

    class BigPaddle : public Effect
    {
    public:
        BigPaddle();
        ~BigPaddle() override = default;

        void Update(float dt) override;
        const std::string getEffectName() override {return "Wide Paddle";}
        
    };
}
