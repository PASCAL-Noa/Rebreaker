#pragma once
#include "CameraEffect.h"

class CameraZoom : public CameraEffect
{
public:
    CameraZoom(sf::View view, sf::Vector2f zoom, float duration, Tweening::Easings easingFunction, void(* _onComplete)());
    ~CameraZoom() override = default;

    void Update(float dt) override;

private:
    sf::Vector2f m_startSize;
    float m_zoomX;
    float m_zoomY;

    float m_fZoomX;
    float m_fZoomY;
    
};
