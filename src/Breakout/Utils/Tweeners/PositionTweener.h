#pragma once
#include "Tweener.h"

class PositionTweener : public Tweener
{
public:
    PositionTweener(sf::Transformable* entity, const sf::Vector2f& target, float duration,Tweening::Easings easing = Tweening::EaseInSine);
    PositionTweener(sf::Transformable* entity, const sf::Vector2f& target, float duration, const std::function<void()>& onComplete, Tweening::Easings easing = Tweening::EaseInSine);
    
    void Update(float dt) override;

private:
    sf::Vector2f m_startPosition;
    sf::Vector2f m_targetPosition;
};
