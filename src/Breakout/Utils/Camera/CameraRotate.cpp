#include "pch.h"
#include "CameraRotate.h"

CameraRotate::CameraRotate(const sf::View view, sf::Vector2f finalRotation, float duration,
    Tweening::Easings easingFunction, void(* _onComplete)())
: CameraEffect(duration, easingFunction, _onComplete),
m_rotation( view.getRotation() ),
m_finalRotation( view.getRotation() + finalRotation.x )
{
}

void CameraRotate::Update(float dt)
{
    if (m_elapsedTime >= m_duration) return;
    sf::View editView = Game::getWindow().getView();
    editView.setRotation(m_rotation + ( m_easingFunction(m_elapsedTime / m_duration) * (m_finalRotation - m_rotation)));
    Game::getWindow().setView(editView);
    
    m_elapsedTime += dt;
    if (m_elapsedTime >= m_duration)
    {
        if (m_onComplete != nullptr) (*m_onComplete)();
        Game::getCameraSystem().RemoveEffect(this);
    }
}
