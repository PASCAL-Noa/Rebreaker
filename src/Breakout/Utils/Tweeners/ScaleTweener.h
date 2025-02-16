#pragma once
#include "Tweener.h"

class ScaleTweener : public Tweener
{
public:
    ScaleTweener(sf::Transformable* entity, const sf::Vector2f& target, float duration,Tweening::Easings easing = Tweening::EaseInSine);
    ScaleTweener(sf::Transformable* entity, const sf::Vector2f& target, float duration, const std::function<void()>&, Tweening::Easings easing = Tweening::EaseInSine);
    ~ScaleTweener() override = default;
    
    void Update(float dt) override;

private:
    sf::Vector2f m_startScale;
    sf::Vector2f m_targetScale;
};
