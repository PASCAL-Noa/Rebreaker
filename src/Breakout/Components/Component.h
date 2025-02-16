#pragma once
class Entity;

class Component
{
public:
    Component(Entity* entity);
    virtual ~Component() = default;
    Entity* getEntity() const;
protected:
    Entity* m_Entity;    
};
