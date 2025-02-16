#pragma once
#include "../Components/ParticleEmitter.h"

class ParticleSystem
{
public:
    ParticleSystem() = default;

    void RegisterEntity(ParticleEmitter* emitter);
    void UnregisterEntity(ParticleEmitter* emitter);
    void Update(float dT) const;
    void Render(sf::RenderTexture* _tex) const;

private:
    std::vector<ParticleEmitter*> m_emitters;
    
};
