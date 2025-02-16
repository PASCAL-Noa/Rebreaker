#pragma once
#include "../Utils/Camera/CameraMove.h"
#include "../Utils/Camera/CameraRotate.h"
#include "../Utils/Camera/CameraShake.h"
#include "../Utils/Camera/CameraZoom.h"

class CameraSystem
{
    
public:
    CameraSystem();
    ~CameraSystem();

    void RemoveEffect(const CameraEffect* effect);

    void Zoom(sf::Vector2f zoom, float duration, Tweening::Easings _easing, void(* _onComplete)());
    void Move(sf::Vector2f move, float duration, Tweening::Easings _easing, void(* _onComplete)());
    void Rotation(sf::Vector2f _rotation, float _duration, Tweening::Easings _easing, void(* _onComplete)());
    void Shake(sf::Vector2f _forces, float _duration, Tweening::Easings _easing, void(* _onComplete)());
    
    void Update(float dt) const;

private:
    sf::View m_view;
    std::vector<CameraEffect*> m_effects;
    
};
