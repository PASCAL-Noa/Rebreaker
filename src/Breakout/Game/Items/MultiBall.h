#pragma once
#include "Effect.h"

namespace Breakout
{
    class Ball;

    class MultiBall : public Effect
    {
    public:
        MultiBall();
        ~MultiBall() override = default;

        void Update(float dt) override;
        const std::string getEffectName() override {return "More Balls";}

    private:
        float m_effectDuration;
        
    };
}
