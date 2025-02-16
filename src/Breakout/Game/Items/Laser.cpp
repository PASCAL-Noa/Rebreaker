#include "pch.h"
#include "Laser.h"

#include "../Brick.h"
#include "../Paddle.h"
#include "../AssetLoader/AssetLoader.hpp"
#include "../Ball.h"
#include "../BrickComboText.h"

namespace Breakout
{
    
    Laser::Laser() :
    Effect(0),
    Renderable(this),
    ParticleEmitter(this),
    SoundPlayer(),
    m_effectDuration(3)
    {
        Paddle* paddle = Game::getUpdateSystem().GetFirstEntityOfType<Paddle>();
        paddle->TweenScale(sf::Vector2f(2, 2), .3f, [&]
        {
            Paddle* paddle = Game::getUpdateSystem().GetFirstEntityOfType<Paddle>();
            paddle->TweenScale(sf::Vector2f(paddle->getCurrentScale(), 1), .3f, Tweening::EaseInCubic);
        }, Tweening::EaseInCubic);
        setPosition(paddle->getPosition());

        m_vertices = sf::VertexArray(sf::Lines, 180);

        int size = 50;
        
        m_vertices[0].position = sf::Vector2f(0, 0);
        m_vertices[0].color = sf::Color::Yellow;
        m_vertices[1].position = sf::Vector2f(0, -20);
        m_vertices[0].color = sf::Color::Yellow;
        m_nextLightning = 2;

        PlaySound(&AssetLoader::thunder, 60, 0.5f);
        
    }

    void Laser::Update(float dt)
    {
        
        if (m_totalTime >= 0.01f && m_nextLightning < 150)
        {

            m_vertices[m_nextLightning].color = sf::Color::Yellow;
            m_vertices[m_nextLightning+1].color = sf::Color::Yellow;
            
            m_vertices[m_nextLightning].position = sf::Vector2f(m_lastX, m_lastY);

            char direction = (rand()%2)*2-1;
            m_lastX += (20 + rand()%30) * direction;
            m_lastY -= (20 + rand()%50);
            m_vertices[m_nextLightning+1].position = sf::Vector2f(m_lastX, m_lastY);
            
            DestroyOnPoint(sf::Vector2f(m_lastX, m_lastY));
            
            m_nextLightning+=2;
            m_totalTime = 0;

            if (rand()%2 == 0)
            {
                GenerateBranch(5, direction);
            }
            
        } else if (m_nextLightning >= 150)
        {
            delete this;
        }
        m_totalTime += dt;
        
    }

    void Laser::GenerateBranch(const int maxCount, const char direction)
    {
        int branchStartX = m_lastX;
        int branchStartY = m_lastY;
        int count = maxCount/2 + rand()%maxCount;
                
        for (int i = 0; i < count && m_nextLightning < 150; i++)
        {
                    
            m_vertices[m_nextLightning].color = sf::Color::Yellow;
            m_vertices[m_nextLightning+1].color = sf::Color::Yellow;
            
            m_vertices[m_nextLightning].position = sf::Vector2f(branchStartX, branchStartY);
            
            DestroyOnPoint(sf::Vector2f(branchStartX, branchStartY));
            
            branchStartX += (10 + rand()%20) * direction;
            branchStartY -= (10 + rand()%20);
            m_vertices[m_nextLightning+1].position = sf::Vector2f(branchStartX, branchStartY);
            
            m_nextLightning+=2;
                    
        }
    }

    void Laser::DestroyOnPoint(sf::Vector2f _point)
    {
        sf::Vector2f point = getPosition() + _point;
        SetEmitter(point);
        BurstParticle(10, 5, sf::Color::Yellow, .7f, sf::Vector2f(0, 360), 50.0f);
            
        for (Brick* brick : Game::getUpdateSystem().GetAllEntityOfType<Brick>())
        {
            if (brick == nullptr) return;
            bool isInside = brick->getPosition().x - 50 < point.x
                && brick->getPosition().x + 50 > point.x
                && brick->getPosition().y - 50 < point.y
                && brick->getPosition().y + 50 > point.y;
                
            if (isInside)
            {
                brick->setHealthPoint(brick->getHealthPoint()-1);
                CameraShake(sf::Vector2f(1, 1), .2f, Tweening::EaseOutQuart);
                Game::getScoreManager().AddScore(brick->getScore());
                new BrickComboText("x" + std::to_string(Game::getScoreManager().GetScoreSize()), brick->getPosition());
                if (brick->getHealthPoint() <= 0) delete brick;
            }
        }
    }
}

