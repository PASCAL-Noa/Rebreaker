#include "pch.h"
#include "CameraShake.h"

#include "CameraMove.h"


CameraShake::CameraShake(const sf::View view, sf::Vector2f _forces, float duration,
                        Tweening::Easings easingFunction, void(* _onComplete)()) :
CameraEffect(duration, easingFunction, _onComplete),
m_center ( view.getCenter() ), m_force(_forces)
{
    
}

void CameraShake::Update(float dt)
{
    
    if (m_elapsedTime >= m_duration) return;
    sf::View editView = Game::getWindow().getView();
    float func = m_easingFunction(m_elapsedTime / m_duration);
    editView.setCenter(m_center.x + ( ((rand()%10)-5) * m_force.x) * func,
        m_center.y + (((rand()%10)-5) * m_force.y) * func);
    Game::getWindow().setView(editView);
    
    m_elapsedTime += dt;
    if (m_elapsedTime >= m_duration)
    {
        if (m_onComplete != nullptr) (*m_onComplete)();
        editView.setCenter(Game::getWindow().getDefaultView().getCenter().x,
            Game::getWindow().getDefaultView().getCenter().y);
        Game::getWindow().setView(editView);
        Game:: getCameraSystem().RemoveEffect(this);
    }
    
}
