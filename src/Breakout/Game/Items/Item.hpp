#pragma once

#include "Effect.h"
#include "../../Components/RectCollider.h"
#include "../Paddle.h"
#include "../PowerUpText.h"

namespace Breakout
{
    class Ball;
    
    template<class T>
    class Item : public Entity, public Renderable, public RectCollider, public SoundPlayer
    {
    public:
        Item(sf::Vector2f position, const sf::Texture* texture, sf::Sound* sound, float duration);
        ~Item() override = default;
        
        void OnCollisionEnter(Collidable* collider, CollisionSide side) override;
        void Update(float deltaTime) override;
    
        
    private:
        sf::Sound* m_sound;
        float m_duration;
    };

    template<class T>
    Item<T>::Item(sf::Vector2f position, const sf::Texture* texture, sf::Sound* sound, float duration) :
        Renderable(texture, this),
        RectCollider(this, sf::Vector2f(30, 30)),
        m_duration(duration),
        m_sound(sound)
    {
        setPosition(position);
    }

    template <class T>
    void Item<T>::OnCollisionEnter(Collidable* collider, CollisionSide side)
    {
        if (dynamic_cast<Paddle*>(collider))
        {
            delete Game::getUpdateSystem().GetFirstEntityOfType<T>();
            PlaySound(m_sound, 20, Utils::randomFloat(0.9f, 1.1f));
            Effect* effect = new T();
            new PowerUpText(effect->getEffectName());
            delete this;
        }
    }

    template<class T>
    void Item<T>::Update(float deltaTime)
    {
        move( 0, 100.0f * deltaTime);
        rotate(45 * deltaTime);
        
        if (getPosition().y > WINDOW_HEIGHT)
        {
            delete this;
        }
    }
}


