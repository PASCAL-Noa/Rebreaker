#include "pch.h"
#include "ParticleSystem.h"

void ParticleSystem::RegisterEntity(ParticleEmitter* entity)
{
    if (entity == nullptr) return;
    m_emitters.push_back(entity);   
}
void ParticleSystem::UnregisterEntity(ParticleEmitter* entity)
{
    if (entity == nullptr) return;
    auto it = std::find(m_emitters.begin(), m_emitters.end(), entity);
    m_emitters.erase(it);
}

void ParticleSystem::Update(float dT) const
{
    for (ParticleEmitter* emitter : m_emitters)
    {
        emitter->UpdateAllVectices(dT);
    }
}

void ParticleSystem::Render(sf::RenderTexture* _tex) const
{
    for (ParticleEmitter* emitter : m_emitters)
    {
        for (sf::VertexArray array : emitter->getVertexArrays())
        {
            _tex->draw(array, sf::RenderStates::Default);   
        }
    }
}
