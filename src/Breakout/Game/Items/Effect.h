#pragma once

namespace Breakout
{
    class Effect: public Entity
    {
        
    public:
        Effect(float duration);

        void Update(float dt) override = 0;

        virtual const std::string getEffectName() = 0;

    protected:
        float m_effectDuration;
    };
}