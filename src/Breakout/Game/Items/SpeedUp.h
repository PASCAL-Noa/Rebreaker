#pragma once
#include "Effect.h"

namespace Breakout
{
    class SpeedUp : public Effect
    {
    public:
        SpeedUp();
        ~SpeedUp() override = default;
        
        void Update(float dt) override;
        const std::string getEffectName() override {return "Time Warp";}
    };
}


