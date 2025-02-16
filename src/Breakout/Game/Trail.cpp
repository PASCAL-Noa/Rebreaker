#include "pch.h"
#include "Trail.h"

#include "Ball.h"

namespace Breakout
{
    Trail::Trail(Ball* ball) : Renderable(this), m_ball(ball)
    {
        m_vertices = sf::VertexArray(sf::TrianglesStrip, 20);
    }

    void Trail::Update(float dt)
    {
        m_vertices.clear();
        for (int i = 1; i < m_ball->getLastPos().size(); i++)
        {
            float f = static_cast<float>(i) / TRAIL_LENGTH;
            
            sf::Vector2f direction = m_ball->getLastPos()[i] - m_ball->getLastPos()[i - 1];
            sf::Vector2f normal = sf::Vector2f(-direction.y, direction.x);
            sf::Vector2f offset = normal * 3.f * m_ball->getBallScale() * f;
            
            m_vertices.append(sf::Vertex(m_ball->getLastPos()[i-1] + offset, sf::Color(255, 255, 255,  45 * f)));
            m_vertices.append(sf::Vertex(m_ball->getLastPos()[i-1] - offset, sf::Color(255, 255, 255,  45 * f)));
            
        }
        
    }
    
}


