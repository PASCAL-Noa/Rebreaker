#pragma once

class InputSystem
{
public:
    InputSystem();
    ~InputSystem() = default;

    void ProcessKey(sf::Event::EventType _event, sf::Keyboard::Key _key);
    void ProcessMousseButton(sf::Event::EventType _event, sf::Mouse::Button _key);
    
    bool GetKeyPressed(sf::Keyboard::Key _key);
    bool GetMousseButton(sf::Mouse::Button _button);
private:
    std::map<sf::Keyboard::Key, bool> KeyStates;
    std::map<sf::Mouse::Button, bool> mouseStates;
};
