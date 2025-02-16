#include "pch.h"
#include "CameraEffect.h"

CameraEffect::CameraEffect(float _duration, Tweening::Easings _easingFunction, void(* _onComplete)())
    : m_duration(_duration),
    m_easingFunction(getTween(_easingFunction)),
    m_onComplete(_onComplete)
{
}