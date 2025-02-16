#pragma once
#include "../Easings.h"

class Entity;

class Tweener
{
public:
    Tweener(sf::Transformable* entity, Tweening::Easings easing, float duration, const std::function<void()>& = []{});
    virtual ~Tweener() = default;
    
    virtual void Update(float dt) = 0;

protected:
    sf::Transformable* m_entity;
    float (*m_easingFunction)(float);
    float m_duration;
    float m_elapsedTime = 0;

    std::function<void()> m_onComplete;
};
