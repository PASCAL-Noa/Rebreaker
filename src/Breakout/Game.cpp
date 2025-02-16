#include "pch.h"
#include "Game.h"

#include "Game/Brick.h"

Game::Game() :
m_window(sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, WINDOW_STYLE, sf::ContextSettings(24, 8, 8)))
{}

sf::RenderWindow& Game::getWindow()
{
    return instance().m_window;
}
const sf::View& Game::getWindowView()
{
    return instance().m_window.getView();
}

const int& Game::GetCurrentLife()
{
    return instance().m_life;
}

int& Game::RemoveLife()
{
    return instance().m_life -= 1;
}

void Game::SetLife(int number)
{
    instance().m_life = number;
}

int Game::GetBrickNumber()
{
    return instance().m_bricks.size();
}

void Game::ClearBricks()
{
    instance().m_bricks.clear();
}

void Game::AddBrick(Breakout::Brick* brick)
{
    instance().m_bricks.push_back(brick);
}

void Game::RemoveBrick(Breakout::Brick* brick)
{
    auto it = std::find(instance().m_bricks.begin(), instance().m_bricks.end(), brick);
    if (*it != nullptr)
    {
        instance().m_bricks.erase(it);
    }
}

RenderSystem& Game::getRenderSystem()
{
    return instance().m_renderSystem;
}

TweeningSystem& Game::getTweeningSystem()
{
    return instance().m_tweeningSystem;
}

PhysicSystem& Game::getPhysicSystem()
{
    return instance().m_physicSystem;
}

InputSystem& Game::getInputSystem()
{
    return instance().m_imputSystem;
}

CameraSystem& Game::getCameraSystem()
{
    return instance().m_cameraEffectSystem;
}

ParticleSystem& Game::getParticleSystem()
{
    return instance().m_particleSystem;
}

TextSystem& Game::getTextSystem()
{
    return instance().m_textSystem;
}

ScoreManager& Game::getScoreManager()
{
    return instance().m_scoreManager;
}

UpdateSystem& Game::getUpdateSystem()
{
    return instance().m_updateSystem;
}
