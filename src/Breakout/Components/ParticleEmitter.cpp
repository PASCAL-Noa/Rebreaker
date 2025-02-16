#include "pch.h"
#include "ParticleEmitter.h"

#include <valarray>

ParticleEmitter::ParticleEmitter(Entity* entity)
: Component(entity), m_emitter(0, 0)
{
    Game::getParticleSystem().RegisterEntity(this);
}

ParticleEmitter::~ParticleEmitter()
{
    Game::getParticleSystem().UnregisterEntity(this);
}

void ParticleEmitter::SetEmitter(sf::Vector2f emitter)
{
    m_emitter = emitter;
}

void ParticleEmitter::BurstParticle( unsigned int count, float size, sf::Color color, float duration, sf::Vector2f direction, float force )
{

    sf::VertexArray vertices(sf::Triangles, count*6);
    std::vector<Particle> particle;
    
    for (uint8_t i = 0; i < count; i++)
    {
        float rotationAngle = (std::rand() % 360);
        sf::Vector2f origin(m_emitter.x + (vertices[i*6+4].position.x - vertices[i*6].position.x) / 2,
    m_emitter.y + (vertices[i*6+4].position.y - vertices[i*6].position.y) / 2);
        sf::Transform rotation = sf::Transform().rotate(rotationAngle, origin.x, origin.y);
    
        // on remet à zéro la position du vertex correspondant à la particule
        vertices[i*6].position = (rotation.transformPoint(m_emitter + sf::Vector2f(0, 0)));
        vertices[i*6+1].position = (rotation.transformPoint(m_emitter + sf::Vector2f(size, 0)));
        vertices[i*6+2].position = (rotation.transformPoint(m_emitter + sf::Vector2f(0, size)));
        vertices[i*6+3].position = (rotation.transformPoint(m_emitter + sf::Vector2f(size, 0)));
        vertices[i*6+4].position = (rotation.transformPoint(m_emitter + sf::Vector2f(size, size)));
        vertices[i*6+5].position = (rotation.transformPoint(m_emitter + sf::Vector2f(0, size)));

        vertices[i*6].color = color;
        vertices[i*6+1].color = color;
        vertices[i*6+2].color = color;
        vertices[i*6+3].color = color;
        vertices[i*6+4].color = color;
        vertices[i*6+5].color = color;
        
        float angle = (direction.x + static_cast <float> (rand()) / (RAND_MAX/(direction.y-direction.x))) * 3.14f / 180.f;
        float speed = (std::rand() % 10) + 10.f;
        float randLife = duration/2 + static_cast <float> (rand()) / (RAND_MAX/(duration-duration/2));
        particle.push_back(Particle(sf::Vector2f(std::cos(angle) * speed * force,
            std::sin(angle) * speed * force),
            randLife,
            randLife));
        
    }

    m_lifeTimes.push_back( duration );
    m_particles.push_back( particle );
    m_pVertices.push_back( vertices );
}

void ParticleEmitter::UpdateAllVectices(float dT)
{
    for ( unsigned int i = 0; i < m_lifeTimes.size(); i++ )
    {
        m_lifeTimes[i] -= dT;
        if (m_lifeTimes[i] <= 0)
        {
            m_pVertices.erase(m_pVertices.begin() + i);   
            m_lifeTimes.erase(m_lifeTimes.begin() + i);
            m_particles.erase(m_particles.begin() + i);
        }
    }
    
    for ( unsigned int i = 0; i < m_particles.size(); i++ )
    {
        
        for (std::size_t j = 0; j < m_particles[i].size(); ++j)
        {
            // on met à jour la durée de vie de la particule
            Particle& p = m_particles[i][j];
            p.lifetime -= dT;

            float ratio = p.lifetime / p.mLifeTime;
            if (p.lifetime <= 0)
            {
                continue;
            }

            m_pVertices[i][j*6].position += p.velocity * dT;
            m_pVertices[i][j*6+1].position += p.velocity * dT;
            m_pVertices[i][j*6+2].position += p.velocity * dT;
            m_pVertices[i][j*6+3].position += p.velocity * dT;
            m_pVertices[i][j*6+4].position += p.velocity * dT;
            m_pVertices[i][j*6+5].position += p.velocity * dT;
            
            m_pVertices[i][j*6].color.a = static_cast<sf::Uint8>(ratio * 255);
            m_pVertices[i][j*6+1].color.a = static_cast<sf::Uint8>(ratio * 255);
            m_pVertices[i][j*6+2].color.a = static_cast<sf::Uint8>(ratio * 255);
            m_pVertices[i][j*6+3].color.a = static_cast<sf::Uint8>(ratio * 255);
            m_pVertices[i][j*6+4].color.a = static_cast<sf::Uint8>(ratio * 255);
            m_pVertices[i][j*6+5].color.a = static_cast<sf::Uint8>(ratio * 255);
            
        }
        
    }
    
}

sf::Vector2f ParticleEmitter::getEmitter()
{
    return m_emitter;
}

std::vector<sf::VertexArray> ParticleEmitter::getVertexArrays()
{
    return m_pVertices;
}