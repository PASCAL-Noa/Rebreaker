#include "pch.h"

Component::Component(Entity* entity) : m_Entity(entity) {}

Entity* Component::getEntity() const
{
    return m_Entity;
}

