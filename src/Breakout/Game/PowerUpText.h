#pragma once

#define POWER_UP_TEXT_DURATION 5.0f

namespace Breakout
{
    class Paddle;
}

namespace Breakout
{
    
    class PowerUpText : public Entity
    {
    public:
        PowerUpText(const std::string& powerName);
        ~PowerUpText() override;
        
        void Update(float dt) override;

    private:
        float m_elapsedTime;
        Text* m_text;
        Paddle* m_paddle;
    };
        
}
