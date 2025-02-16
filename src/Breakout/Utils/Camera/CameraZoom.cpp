#include "pch.h"
#include "CameraZoom.h"

CameraZoom::CameraZoom(const sf::View view, sf::Vector2f zoom, float duration,
                        Tweening::Easings easingFunction, void(* _onComplete)()) :
CameraEffect(duration, easingFunction, _onComplete),
m_startSize ( view.getSize() ),
m_zoomX (view.getViewport().width),
m_zoomY (view.getViewport().height),
m_fZoomX( view.getViewport().width + zoom.x),
m_fZoomY( view.getViewport().height + zoom.y)
{
    
}

void CameraZoom::Update(float dt)
{
    
    if (m_elapsedTime >= m_duration) return;
    sf::View editView = Game::getWindow().getView();

    float zoomX = m_zoomX + ( m_easingFunction(m_elapsedTime / m_duration) * (m_fZoomX - m_zoomX));
    float zoomY = m_zoomX + ( m_easingFunction(m_elapsedTime / m_duration) * (m_fZoomX - m_zoomX));

    editView.setSize(m_startSize.x * zoomX, m_startSize.y * zoomY);
    
    Game::getWindow().setView(editView);
    m_elapsedTime += dt; 
    if (m_elapsedTime >= m_duration)
    {
        if (m_onComplete != nullptr) (*m_onComplete)();
        Game::getCameraSystem().RemoveEffect(this);
    }
    
}
