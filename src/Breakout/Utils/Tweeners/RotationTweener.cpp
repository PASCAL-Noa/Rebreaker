#include "pch.h"
#include "RotationTweener.h"

RotationTweener::RotationTweener(sf::Transformable* entity, float target, float duration, Tweening::Easings easing) :
    Tweener(entity, easing, duration),
    m_startRotation(entity->getRotation()),
    m_targetRotation(target)
{
    Game::getTweeningSystem().AddTweener(this);
}

RotationTweener::RotationTweener(sf::Transformable* entity, float target, float duration,  const std::function<void()>& onComplete, Tweening::Easings easing) :
    Tweener(entity, easing, duration, onComplete),
    m_startRotation(entity->getRotation()),
    m_targetRotation(target)
{
    Game::getTweeningSystem().AddTweener(this);
}

void RotationTweener::Update(const float dt)
{
    m_entity->setRotation( m_startRotation + ( m_easingFunction(m_elapsedTime / m_duration) * (m_targetRotation - m_startRotation)));
    m_elapsedTime += dt;
    if (m_elapsedTime >= m_duration)
    {
        if (m_onComplete != nullptr) m_onComplete();
        Game::getTweeningSystem().RemoveTweener(this);
        delete this;
    }
}