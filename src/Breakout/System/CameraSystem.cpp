#include "pch.h"
#include "CameraSystem.h"

class CameraEffect;

CameraSystem::CameraSystem()
{}

CameraSystem::~CameraSystem()
{
    m_effects.clear();
}

void CameraSystem::RemoveEffect(const CameraEffect* effect)
{
    auto it = std::find(m_effects.begin(), m_effects.end(), effect);
    if (*it != nullptr)
    {
        m_effects.erase(it);
    }
}



void CameraSystem::Zoom(sf::Vector2f zoom, float duration, Tweening::Easings _easing, void(* _onComplete)())
{
    m_effects.push_back( new CameraZoom(Game::getWindowView(), zoom, duration, _easing, _onComplete) );
}

void CameraSystem::Move(sf::Vector2f move, float duration, Tweening::Easings _easing, void(* _onComplete)())
{
    m_effects.push_back( new CameraMove(Game::getWindowView(), move, duration, _easing, _onComplete) );
}

void CameraSystem::Rotation(sf::Vector2f _rotation, float _duration, Tweening::Easings _easing, void(* _onComplete)())
{
    m_effects.push_back( new CameraShake(Game::getWindowView(), _rotation, _duration, _easing, _onComplete) );
}

void CameraSystem::Shake(sf::Vector2f _forces, float _duration, Tweening::Easings _easing, void(* _onComplete)())
{
    m_effects.push_back( new CameraShake(Game::getWindowView(), _forces, _duration, _easing, _onComplete) );
}

void CameraSystem::Update(const float dt) const
{
    for (CameraEffect* effect : m_effects)
    {
        if (effect != nullptr)
            effect->Update(dt);
    }
}

