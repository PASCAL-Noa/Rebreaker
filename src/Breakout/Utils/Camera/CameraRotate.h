#pragma once

class CameraRotate : public CameraEffect
{
public:
    CameraRotate(const sf::View view, sf::Vector2f finalRotation, float duration,
    Tweening::Easings easingFunction, void(* _onComplete)());
    ~CameraRotate() override = default;

    void Update(float dt) override;

private:
    float m_rotation;
    float m_finalRotation;
    
};
