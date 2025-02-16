#pragma once
#include "CameraEffect.h"

class CameraMove : public CameraEffect
{

public:
    CameraMove(sf::View view, sf::Vector2f finalPosition, float duration, Tweening::Easings _easingFunction,
               void (*_onComplete)());
    ~CameraMove() override = default;
    
    void Update(float dt) override;

private:
    sf::Vector2f m_startPosition;
    sf::Vector2f m_finalPosition;
    
};
