#pragma once
#include "Utils/Easings.h"

class Entity : public sf::Transformable
{
public:
    Entity();
    Entity(sf::Vector2f pos);
    ~Entity() override;
    
    virtual void Update(float dt) = 0;

    bool GetMousePressed(sf::Mouse::Button _button);
    bool GetKeyPressed(sf::Keyboard::Key _key);

    void CameraRotation(sf::Vector2f _values, float _duration, Tweening::Easings _easingFunction);
    void CameraRotation(sf::Vector2f _values, float _duration, Tweening::Easings _easingFunction, void(* _onComplete)());

    void CameraMove(sf::Vector2f _values, float _duration, Tweening::Easings _easingFunction);
    void CameraMove(sf::Vector2f _values, float _duration, Tweening::Easings _easingFunction, void(* _onComplete)());

    void CameraShake(sf::Vector2f _values, float _duration, Tweening::Easings _easingFunction);
    void CameraShake(sf::Vector2f _values, float _duration, Tweening::Easings _easingFunction, void(* _onComplete)());

    void CameraZoom(sf::Vector2f _values, float _duration, Tweening::Easings _easingFunction);
    void CameraZoom(sf::Vector2f _values, float _duration, Tweening::Easings _easingFunction, void(* _onComplete)());

    void TweenPosition(sf::Vector2f target, float duration, Tweening::Easings easing = Tweening::EaseInSine);
    void TweenPosition(sf::Vector2f target, float duration, const std::function<void()>&, Tweening::Easings easing = Tweening::EaseInSine);

    void TweenScale(sf::Vector2f target, float duration, Tweening::Easings easing = Tweening::EaseInSine);
    void TweenScale(sf::Vector2f target, float duration, const std::function<void()>&, Tweening::Easings easing = Tweening::EaseInSine);

    void TweenRotation(float target, float duration, Tweening::Easings easing = Tweening::EaseInSine);
    void TweenRotation(float target, float duration, const std::function<void()>&, Tweening::Easings easing = Tweening::EaseInSine);
};
