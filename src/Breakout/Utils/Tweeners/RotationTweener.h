#pragma once

class RotationTweener : public Tweener
{
public:
    RotationTweener(sf::Transformable* entity, float target, float duration,Tweening::Easings easing = Tweening::EaseInSine);
    RotationTweener(sf::Transformable* entity, float target, float duration, const std::function<void()>& onComplete, Tweening::Easings easing = Tweening::EaseInSine);

    void Update(float dt) override;

private:
    float m_startRotation;
    float m_targetRotation;
    
};
