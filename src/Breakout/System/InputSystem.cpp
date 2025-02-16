#include "pch.h"
#include "InputSystem.h"

InputSystem::InputSystem()
{}

void InputSystem::ProcessKey(sf::Event::EventType _event, sf::Keyboard::Key _key)
{
    switch (_event)
    {
    case sf::Event::KeyPressed:
        KeyStates[_key] = true;
        break;
    case sf::Event::KeyReleased:
        KeyStates[_key] = false;
        break;
    default:
        break;
    }
}

void InputSystem::ProcessMousseButton(sf::Event::EventType _event, sf::Mouse::Button _button)
{
    switch (_event)
    {
    case sf::Event::MouseButtonPressed:
        mouseStates[_button] = true;
        break;
    case sf::Event::MouseButtonReleased:
        mouseStates[_button] = false;
        break;
    default:
        break;
    }
}


bool InputSystem::GetMousseButton(sf::Mouse::Button _button)
{
    return mouseStates.contains(_button) && mouseStates.at(_button);
}


bool InputSystem::GetKeyPressed(sf::Keyboard::Key _key)
{
    return KeyStates.contains(_key) && KeyStates.at(_key);
}