#pragma once

#include "Game/ScoreManager.h"
#include "System/CameraSystem.h"
#include "System/InputSystem.h"
#include "System/ParticleSystem.h"
#include "System/RenderSystem.h"
#include "System/TweeningSystem.h"
#include "System/PhysicSystem.h"
#include "System/TextSystem.h"
#include "System/UpdateSystem.h"

//Window Property---------------
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "Breakout"
#define WINDOW_STYLE sf::Style::Fullscreen
//-------------------------------

//Default Game Property---------
#define LIFES 3
//------------------------------

namespace Breakout
{
    class Brick;
}

class Game
{
public:
    static sf::RenderWindow& getWindow();

    //systems
    static RenderSystem& getRenderSystem();
    static TweeningSystem& getTweeningSystem();
    static PhysicSystem& getPhysicSystem();
    static InputSystem& getInputSystem();
    static CameraSystem& getCameraSystem();
    static ParticleSystem& getParticleSystem();
    static UpdateSystem& getUpdateSystem();
    static ScoreManager& getScoreManager();
    static TextSystem& getTextSystem();
    static const sf::View& getWindowView();

    static const int& GetCurrentLife();
    static int& RemoveLife();
    static void SetLife(int number);
    static int GetBrickNumber();
    static void ClearBricks();
    static void AddBrick(Breakout::Brick* brick);
    static void RemoveBrick(Breakout::Brick* brick);

private:
    Game();
    ~Game() = default;
    
    //singleton instance
    static Game& instance()
    {
        static Game instance;
        return instance;
    }

private:
    sf::RenderWindow m_window;
    RenderSystem m_renderSystem;
    TweeningSystem m_tweeningSystem;
    PhysicSystem m_physicSystem;
    InputSystem m_imputSystem;
    CameraSystem m_cameraEffectSystem;
    ParticleSystem m_particleSystem;
    TextSystem m_textSystem;
    ScoreManager m_scoreManager;
    UpdateSystem m_updateSystem;

    int m_life = LIFES;
    int m_maxLife = LIFES;
    std::vector<Breakout::Brick*> m_bricks;
    
};
