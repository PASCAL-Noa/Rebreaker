#pragma once
#include "CameraEffect.h"

class CameraShake : public CameraEffect
{
public:
    CameraShake( sf::View view, sf::Vector2f _forces, float duration,
        Tweening::Easings easingFunction, void(*_onComplete)());
    ~CameraShake() override = default;

    void Update(float dt) override;

private:
    sf::Vector2f m_center;
    sf::Vector2f m_force;
    
};
