#include "pch.h"

PhysicSystem::~PhysicSystem()
{
    m_movable_entities.clear();
    m_static_entities.clear();
}

void PhysicSystem::RegisterEntity(Collidable* entity)
{
    if (entity == nullptr) return;
    m_static_entities.push_back(entity);   
}
void PhysicSystem::RegisterEntity(Collider* entity)
{
    if (entity == nullptr) return;
    m_movable_entities.push_back(entity);   
}

void PhysicSystem::UnregisterEntity(const Collidable* component)
{
    auto it = std::find(m_static_entities.begin(), m_static_entities.end(), component);
    if (*it != nullptr) m_static_entities.erase(it);
}

void PhysicSystem::UnregisterEntity(const Collider* component)
{
    auto it = std::find(m_movable_entities.begin(), m_movable_entities.end(), component);
    if (*it != nullptr) m_movable_entities.erase(it);
}


void PhysicSystem::Update() const
{
    for (int i = 0; i < m_movable_entities.size(); i++)
    {
        for (int j = 0; j < m_static_entities.size(); j++)
        {
            if (i >= m_movable_entities.size()) continue;
            if (j >= m_static_entities.size()) continue;
            
            Collider* collider = m_movable_entities[i];
            Collidable* collidable = m_static_entities[j];
            
            if (collider==nullptr) continue;
            if (collidable==nullptr) continue;
            
            if (collider->Collide(collidable))
            {
                collider->OnCollisionEnter(collidable, collider->getSide());
                collidable->OnHit(collider);
            }
        }
    }
}
