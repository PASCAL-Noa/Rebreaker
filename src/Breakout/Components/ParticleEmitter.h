#pragma once
#include "Renderable.h"

struct Particle
{
    sf::Vector2f velocity;
    float mLifeTime;
    float lifetime;
};

class ParticleEmitter : public Component
{
public:

    ParticleEmitter(Entity* entity);
    ~ParticleEmitter() override;
    
    void SetEmitter(sf::Vector2f position);
    void BurstParticle( unsigned int count, float size, sf::Color color, float duration, sf::Vector2f direction, float force );
    void UpdateAllVectices(float dT);

    sf::Vector2f getEmitter();
    std::vector<sf::VertexArray> getVertexArrays();

private:
    
    std::vector<std::vector<Particle>> m_particles;
    std::vector<sf::VertexArray> m_pVertices;
    std::vector<float> m_lifeTimes;
    
    sf::Vector2f m_emitter;
};