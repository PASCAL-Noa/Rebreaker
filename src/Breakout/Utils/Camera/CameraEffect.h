#pragma once
#include "../Easings.h"

class CameraEffect
{
public:
    CameraEffect(float _duration, Tweening::Easings _easingFunction, void(*_onComplete)());
    virtual ~CameraEffect() = default;

    virtual void Update(float deltaTime) = 0;

protected:
    float m_elapsedTime = 0;
    float m_duration;

    float (*m_easingFunction)(float);
    void(*m_onComplete)();
    
};
