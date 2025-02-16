#pragma once
#include "Effect.h"

class Ball;

namespace Breakout
{

    class Laser : public Effect, public Renderable, public ParticleEmitter, public SoundPlayer
    {
    public:
        Laser();

        void Update(float dt) override;
        const std::string getEffectName() override {return "Thunderstorm";}
    private:
        std::vector<sf::Vector2f> m_collisionPoints;
        float m_effectDuration;
        
        int m_nextLightning = 2;
        int m_lastX = 0;
        int m_lastY = -20;

        float m_totalTime = 0;

        void GenerateBranch(int maxCount, char direction);
        void DestroyOnPoint(sf::Vector2f _point);
        
    };
}
