#pragma once
#include <queue>

#include "Brick.h"
#include "Trail.h"
#include "../Components/RectCollider.h"

#define TRAIL_LENGTH 120

namespace Breakout
{
    
    class Ball : public Entity, public Renderable, public RectCollider, public SoundPlayer, public ParticleEmitter
    {
    public:
        Ball();

        void Update(float dt) override;
        void OnCollisionEnter(Collidable* collider, CollisionSide side) override;

        sf::Vector2f& getDirection();
        void changeDirection(float x, float y);
        std::deque<sf::Vector2f>& getLastPos();
        
        float getSpeed() const;
        void setSpeed(float speed);

        float getBallScale() const;
        void setBallScale(float scale, sf::Vector2f newCollision);

        void attachTrail();
        
    private:
        sf::Vector2f m_direction = sf::Vector2f(-1, -1);
        std::deque<sf::Vector2f> m_lastPos;
        Trail* m_trail;

        float m_deltaTime = 0;
        float m_fixedTime = 0;
        
        float m_speed = 300;
        float m_scale = 1;
        
        float m_totalTime = 0;
        
        bool m_isDead = false;
        bool m_isResizing = false;

        void CollidePaddle(const Collidable* collider, const CollisionSide& side);
        void CollideBrick(Brick* brick, const CollisionSide& side);

        void CollideFeedback();
        
    };
    
}
