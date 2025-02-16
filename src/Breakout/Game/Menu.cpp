#include "pch.h"
#include "Menu.h"

#include "Image.h"
#include "Jukebox.h"
#include "Text.h"
#include "AssetLoader/AssetLoader.hpp"

Menu::Menu()
{
}

/**
 * Display the start menu on game window
 * @return if window should be closed
 */
void Menu::Display()
{
    sf::RenderWindow& window = Game::getWindow();
    sf::Clock clock;
    sf::Clock startClock;

    Breakout::Jukebox* juxe = new Breakout::Jukebox( { &AssetLoader::musicMenu } );

    Image* title = new Image(&AssetLoader::menuTitle, WINDOW_WIDTH/2, 300, 1, 1, 0.02f);
    Image* start = new Image(&AssetLoader::menuStart, WINDOW_WIDTH/2, 600, 1, 1, 0.02f);

    Breakout::Text launchText(&AssetLoader::textFont, " [CONTROL + C] Start game\n music by Mithaniel Villard");
    Breakout::Text version(&AssetLoader::textFont, "v 1.0.0 \ndev : Noa P, Éthan G, Mithaniel V");
    
    version.setPosition(150, WINDOW_HEIGHT - 200);
    version.setCharacterSize(30);
    version.setFillColor(sf::Color::Green);

    launchText.setPosition(WINDOW_WIDTH - 500, WINDOW_HEIGHT - 200);
    launchText.setCharacterSize(30);
    launchText.setFillColor(sf::Color::Green);
    
    while (window.isOpen())
    {

        float dT = clock.restart().asSeconds();

        sf::View view =  Game::getWindowView();
        float time = startClock.getElapsedTime().asSeconds();
        float factor = 0.002 * std::sin((time +5)/0.8)+1;
        view.setSize(WINDOW_WIDTH * factor, WINDOW_HEIGHT * factor);
        window.setView(view);
        
        Game::getUpdateSystem().Update(dT);
        Game::getRenderSystem().Render();
        Game::getWindow().display();
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            Game::getInputSystem().ProcessKey(event.type, event.key.code);
            Game::getInputSystem().ProcessMousseButton(event.type, event.mouseButton.button);

            if (event.type == sf::Event::Closed)
                window.close();
            if (Game::getInputSystem().GetKeyPressed(sf::Keyboard::Escape))
                window.close();

            if (Game::getInputSystem().GetMousseButton(sf::Mouse::Left))
            {
                std::cout << sf::Mouse::getPosition().x << std::endl;
                std::cout << sf::Mouse::getPosition().y << std::endl;

                if (sf::Mouse::getPosition().x > 743 && sf::Mouse::getPosition().x < 1177
                    && sf::Mouse::getPosition().y < 680 && sf::Mouse::getPosition().y > 520)
                {
                    delete title;
                    delete start;
                    delete juxe;
                    return;
                }
            }
            
            if (Game::getInputSystem().GetKeyPressed(sf::Keyboard::LControl))
            {
                if (Game::getInputSystem().GetKeyPressed(sf::Keyboard::C))
                {
                    delete title;
                    delete start;
                    delete juxe;
                    return;
                }
            }
        }
    }
    
}
