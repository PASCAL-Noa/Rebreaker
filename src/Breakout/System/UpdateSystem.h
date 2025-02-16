#pragma once

class Entity;

class UpdateSystem
{
public:
    UpdateSystem() = default;
    ~UpdateSystem();

    void Update(float dt) const;
    void RegisterEntity(Entity* entity);
    void UnregisterEntity(Entity* entity);

    template<typename EntityType>
    std::vector<EntityType*> GetAllEntityOfType();
    template<typename EntityType>
    EntityType* GetFirstEntityOfType();
    
private:
    std::vector<Entity*> m_entities;
};

template <typename EntityType>
std::vector<EntityType*> UpdateSystem::GetAllEntityOfType()
{
    std::vector<EntityType*> entities;
    for (Entity* entity : m_entities)
    {
        if (EntityType* d = dynamic_cast<EntityType*>(entity); d != nullptr)
        {
            entities.push_back(d);
        }
    }

    return entities;
}

template <typename EntityType>
EntityType* UpdateSystem::GetFirstEntityOfType()
{
    for (Entity* entity : m_entities)
    {
        if (EntityType* d = dynamic_cast<EntityType*>(entity); d != nullptr)
        {
            return d;
        }
    }
    return nullptr;
}
