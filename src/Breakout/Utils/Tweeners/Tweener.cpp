#include "pch.h"
#include "Tweener.h"

Tweener::Tweener(sf::Transformable* entity, Tweening::Easings easing, float duration, const std::function<void()>& onComplete) :
    m_entity(entity),
    m_duration(duration),
    m_onComplete(std::bind(onComplete)) 
{
    m_easingFunction = getTween(easing);
}

