#include "pch.h"
#include "UpdateSystem.h"

UpdateSystem::~UpdateSystem()
{
    m_entities.clear();
}

void UpdateSystem::Update(const float dt) const
{
    for(Entity* entity : m_entities)
    {
        entity->Update(dt);
    }
}
void UpdateSystem::UnregisterEntity(Entity* entity)
{
    auto it = std::find(m_entities.begin(), m_entities.end(), entity);
    if(*it != nullptr) m_entities.erase(it);
}

void UpdateSystem::RegisterEntity(Entity* entity)
{
    m_entities.push_back(entity);
}

