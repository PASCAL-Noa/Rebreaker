#pragma once

class Collidable;
class Collider;

class PhysicSystem
{
public:
    PhysicSystem() = default;
    ~PhysicSystem();
    
    void RegisterEntity(Collidable* component);
    void RegisterEntity(Collider* component);

    void UnregisterEntity(const Collidable* component);
    void UnregisterEntity(const Collider* component);
    
    void Update() const;

protected:
    std::vector<Collidable*> m_static_entities;
    std::vector<Collider*> m_movable_entities;
};
