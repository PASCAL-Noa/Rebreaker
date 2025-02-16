#include "pch.h"

Entity::Entity()
{
    Game::getUpdateSystem().RegisterEntity(this);
}

Entity::~Entity()
{
    Game::getUpdateSystem().UnregisterEntity(this);
}

Entity::Entity(sf::Vector2f pos)
{
    setPosition(pos);
    Game::getUpdateSystem().RegisterEntity(this);
}

bool Entity::GetMousePressed(sf::Mouse::Button _button)
{
    return Game::getInputSystem().GetMousseButton(_button);
}

bool Entity::GetKeyPressed(sf::Keyboard::Key _key)
{
    return Game::getInputSystem().GetKeyPressed(_key);
}

#
void Entity::CameraRotation(sf::Vector2f _values, float _duration,
    Tweening::Easings _easingFunction)
{
    Game::getCameraSystem().Rotation(_values, _duration, _easingFunction, nullptr);
}
void Entity::CameraRotation(sf::Vector2f _values, float _duration,
    Tweening::Easings _easingFunction, void(* _onComplete)())
{
    Game::getCameraSystem().Rotation(_values, _duration, _easingFunction, _onComplete);
}

void Entity::CameraMove(sf::Vector2f _values, float _duration,
    Tweening::Easings _easingFunction)
{
    Game::getCameraSystem().Move(_values, _duration, _easingFunction, nullptr);
}
void Entity::CameraMove(sf::Vector2f _values, float _duration,
    Tweening::Easings _easingFunction, void(* _onComplete)())
{
    Game::getCameraSystem().Move(_values, _duration, _easingFunction, _onComplete);
}

void Entity::CameraShake(sf::Vector2f _values, float _duration,
    Tweening::Easings _easingFunction)
{
    Game::getCameraSystem().Shake(_values, _duration, _easingFunction, nullptr);
}
void Entity::CameraShake(sf::Vector2f _values, float _duration,
    Tweening::Easings _easingFunction, void(* _onComplete)())
{
    Game::getCameraSystem().Shake(_values, _duration, _easingFunction, _onComplete);
}

void Entity::CameraZoom(sf::Vector2f _values, float _duration,
    Tweening::Easings _easingFunction)
{
    Game::getCameraSystem().Zoom(_values, _duration, _easingFunction, nullptr);
}
void Entity::CameraZoom(sf::Vector2f _values, float _duration,
    Tweening::Easings _easingFunction, void(* _onComplete)())
{
    Game::getCameraSystem().Zoom(_values, _duration, _easingFunction, _onComplete);
}

void Entity::TweenPosition(sf::Vector2f target, float duration, Tweening::Easings easing)
{
        new PositionTweener(this, target, duration, easing);
}

void Entity::TweenPosition(sf::Vector2f target, float duration, const std::function<void()>& onComplete, Tweening::Easings easing)
{
        new PositionTweener(this, target, duration, onComplete, easing);
}

void Entity::TweenScale(sf::Vector2f target, float duration, Tweening::Easings easing)
{
        new ScaleTweener(this, target, duration, easing);
}

void Entity::TweenScale(sf::Vector2f target, float duration, const std::function<void()>& onComplete, Tweening::Easings easing)
{
        new ScaleTweener(this, target, duration, onComplete, easing);
}

void Entity::TweenRotation(float target, float duration, Tweening::Easings easing)
{
        new RotationTweener(this, target, duration, easing);
}

void Entity::TweenRotation(float target, float duration, const std::function<void()>& onComplete, Tweening::Easings easing)
{
        new RotationTweener(this, target, duration, onComplete, easing);
}

