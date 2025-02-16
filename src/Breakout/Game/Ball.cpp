#include "pch.h"
#include "Ball.h"

#include "Brick.h"
#include "BrickComboText.h"
#include "Paddle.h"
#include "AssetLoader/AssetLoader.hpp"
#include "Items/Effect.h"
#include "Items/Item.hpp"

namespace Breakout
{
    Ball::Ball() :
    RectCollider(this, sf::Vector2f(30.0, 30.0)),
    Renderable(&AssetLoader::ballTexture,this),
    ParticleEmitter(this)
    {
        setOrigin(15, 15);
    }
    
    void Ball::Update(const float dt)
    {
        if (m_isDead) return;
        m_deltaTime = dt;
        if (m_fixedTime >= 1.0/80)
        {
            m_lastPos.push_back(getCenter());
            m_fixedTime = 0;
        }

        m_totalTime+=dt;
        m_fixedTime+=dt;
        
        move(sf::Vector2f(m_direction.x * dt * (m_speed + log(m_totalTime)), m_direction.y * dt * (m_speed + log(m_totalTime))));
        if (m_isResizing) move(-m_direction.x * getSize().x * dt, -m_direction.y * getSize().y * dt);

        if ( getLeft() + m_direction.x * dt * m_speed <= 95 || getRight() + m_direction.x * dt * m_speed >= WINDOW_WIDTH - 95)
        {
            CollideFeedback();
            move(sf::Vector2f(-m_direction.x * dt * (m_speed + log(m_totalTime)), -m_direction.y * dt * (m_speed + log(m_totalTime))));
            m_direction.x = -m_direction.x;}
        
        if (getTop() + m_direction.y * dt * m_speed <= 155)
        {
            CollideFeedback();
            move(sf::Vector2f(-m_direction.x * dt * (m_speed + log(m_totalTime)), -m_direction.y * dt * (m_speed + log(m_totalTime))));
            m_direction.y = -m_direction.y;
        }
        if (getBottom() + m_direction.y * dt * m_speed >= WINDOW_HEIGHT - 95)
        {
            setSpeed(0);
            m_isDead = true;

            SetEmitter( sf::Vector2f(getPosition()) );
            BurstParticle(20, 5, sf::Color::Red, 5.f, sf::Vector2f(0, 360), 10.f);
            CameraShake(sf::Vector2f(1, 1), .9f, Tweening::EaseOutQuart);
            
            TweenScale(sf::Vector2f(3, 3), 2.f, [&]
            {
                SetEmitter( sf::Vector2f(getPosition()) );
                BurstParticle(20, 5, sf::Color::Red, 5.f, sf::Vector2f(0, 360), 100.f);
                TweenScale(sf::Vector2f(0, 0), .2f, [&]
                {
                    if (Game::getUpdateSystem().GetAllEntityOfType<Ball>().size() > 1)
                    {
                        delete m_trail;
                        delete this;
                    } else
                    {
                        Paddle* paddle = Game::getUpdateSystem().GetFirstEntityOfType<Paddle>();
                        setPosition(paddle->getPosition().x, WINDOW_HEIGHT/2 + 200);
                        m_direction.x = -1;
                        m_direction.y = -1;
                        m_lastPos.clear();
                        SetEmitter( sf::Vector2f(getPosition()) );
                        BurstParticle(20, 5, sf::Color::Green, 5.f, sf::Vector2f(0, 360), 100.f);
                        TweenScale(sf::Vector2f(1, 1), 2.f, [&]()
                        {
                            setSpeed(300);
                            SetEmitter( sf::Vector2f(getPosition()) );
                            BurstParticle(20, 5, sf::Color::Green, 2.f, sf::Vector2f(0, 360), 100.f);
                            m_isDead = false;
                        }, Tweening::EaseInOutQuad);
                        Game::RemoveLife();
                    }
                }, Tweening::EaseOutQuart);
            }, Tweening::EaseInOutQuad);
        }
        if (m_lastPos.size() >= TRAIL_LENGTH) m_lastPos.pop_front();
    }
    
    void Ball::CollideFeedback()
    {
        PlaySound(&AssetLoader::ballSound, 30, Utils::randomFloat(0.9f, 1.1f));
        SetEmitter( sf::Vector2f(getPosition()) );
        BurstParticle(20, 5, sf::Color::White, .5f, sf::Vector2f(0, 360), 10.f);
        CameraShake(sf::Vector2f(0.3, 0.3), .2f, Tweening::EaseOutQuart);
        
        TweenScale(sf::Vector2f(getBallScale()-.2f, getBallScale()-.2), 0.2f, [&]
       {
            TweenScale(sf::Vector2f(getBallScale(), getBallScale()), 0.2f, Tweening::EaseOutQuart);
       }, Tweening::EaseInOutQuad);
    }
    
    
    void Ball::OnCollisionEnter(Collidable* collider, CollisionSide side)
    {
        //Collision Ball
        if (dynamic_cast<Paddle*>(collider))
            CollidePaddle(collider, side);
        else if (dynamic_cast<Brick*>(collider))
            CollideBrick(dynamic_cast<Brick*>(collider), side);

    }

    void Ball::CollidePaddle(const Collidable* collider, const CollisionSide& side)
    {
        sf::Vector2f pos = getCenter() - collider->getCenter();

        float angle = abs(90 - 90 * (pos.x/60.0));
        angle = std::clamp(angle, 20.0f, 160.0f);
        sf::Vector2f direction = sf::Vector2f(1.0, 0.0);

        Paddle* paddle = Game::getUpdateSystem().GetFirstEntityOfType<Paddle>();
        Utils::rotateVectorAroundPoint(direction, -angle * (std::numbers::pi / 180.0));

        TweenScale(sf::Vector2f(getBallScale()-.2f, getBallScale()-.2), 0.2f, [&]
        {
            TweenScale(sf::Vector2f(getBallScale(), getBallScale()), 0.2f, Tweening::EaseOutQuart);
        }, Tweening::EaseInOutQuad);
        
        switch (side)
        {
        case Top:
            SetEmitter( paddle->getCenter() );
            PlaySound(&AssetLoader::ballSound, 30, Utils::randomFloat(0.9f, 1.1f));
            BurstParticle(20, 5, sf::Color::White, .7f, sf::Vector2f(angle-25, angle+25), 15.f);
            m_direction = direction;
            break;
        case Left:
            BurstParticle(20, 5, sf::Color::White, .7f, sf::Vector2f(angle-25, angle+25), 15.f);
            move( -m_direction.x * m_deltaTime * paddle->getCurrentSpeed(), m_direction.y * m_deltaTime * m_speed);
            m_direction.x = -m_direction.x;
            break;
        case Right:
            move(-m_direction.x * m_deltaTime * paddle->getCurrentSpeed(), m_direction.y * m_deltaTime * m_speed);
            m_direction.x = -m_direction.x;
            break;
        }
    }

    void Ball::CollideBrick(Brick* brick, const CollisionSide& side)
    {
        brick->setHealthPoint(brick->getHealthPoint()-1);

        if (getBallScale() == 1)
        {
            switch (side)
            {
            case Top:
                m_direction.y = -m_direction.y;
                break;
            case Bottom:
                m_direction.y = -m_direction.y;
                break;
            case Left:
                m_direction.x = -m_direction.x;
                break;
            case Right:
                m_direction.x = -m_direction.x;
                break;
            }
        } else
        {
            brick->setHealthPoint(0);
        }
        
        TweenScale(sf::Vector2f(getBallScale()-.2f, getBallScale()-.2), 0.2f, [&]
       {
            TweenScale(sf::Vector2f(getBallScale(), getBallScale()), 0.2f, Tweening::EaseOutQuart);
       }, Tweening::EaseInOutQuad);
        
        if ( brick->getHealthPoint() <= 0 )
        {
            PlaySound(&AssetLoader::brickDestroy, 80, Utils::randomFloat(0.9f, 1.1f));
            SetEmitter(brick->getCenter());
            BurstParticle(10, 15, brick->getColor(), 1.2f, sf::Vector2f(0, 360), 100);
        } else
        {
            PlaySound(&AssetLoader::brickHit, 60, Utils::randomFloat(0.9f, 1.1f));
            SetEmitter(brick->getCenter());
            BurstParticle(10, 15, brick->getColor(), 0.8f, sf::Vector2f(0, 360), 10);
        }
    }
    
    sf::Vector2f& Ball::getDirection()
    {
        return m_direction;
    }

    void Ball::changeDirection(float x, float y)
    {
        m_direction.x *= x;
        m_direction.y *= y;
    }

    float Ball::getSpeed() const
    {
        return m_speed;
    }

    void Ball::setSpeed(float speed)
    {
        m_speed = speed;
    }

    float Ball::getBallScale() const
    {
        return m_scale;
    }

    void Ball::setBallScale(float scale, sf::Vector2f newCollision)
    {
        m_isResizing = true;
        TweenScale(sf::Vector2f(scale, scale), 1.f, [&]()
        {
            m_isResizing = false;
        } , Tweening::EaseOutQuart);
        m_lastPos.clear();
        m_scale = scale;
        setSize(newCollision);
    }

    void Ball::attachTrail()
    {
        m_trail = new Trail(this);
    }

    std::deque<sf::Vector2f>& Ball::getLastPos()
    {
        return m_lastPos;
    }


}
