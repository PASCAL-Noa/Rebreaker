#include "pch.h"
#include "CameraMove.h"

CameraMove::CameraMove(const sf::View view, sf::Vector2f finalPosition, float duration,
    Tweening::Easings _easingFunction, void(* _onComplete)()) : 
CameraEffect(duration, _easingFunction, _onComplete),
m_finalPosition(finalPosition + view.getCenter()),
m_startPosition(view.getCenter())
{
}

void CameraMove::Update(float dt)
{
    sf::View editView = Game::getWindow().getView();
    
    editView.setCenter(m_startPosition + ( m_easingFunction(m_elapsedTime / m_duration) * (m_finalPosition - m_startPosition)));
    Game::getWindow().setView(editView);
    m_elapsedTime += dt;
    if (m_elapsedTime >= m_duration)
    {
        if (m_onComplete != nullptr) (*m_onComplete)();
        Game::getCameraSystem().RemoveEffect(this);
    }
    
}
