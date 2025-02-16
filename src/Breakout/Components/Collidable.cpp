#include "pch.h"
#include "Collidable.h"

Collidable::Collidable(Entity* _parent, const sf::Vector2f& size): Component(_parent), m_size(size)
{
    Game::getPhysicSystem().RegisterEntity(this);
}

Collidable::~Collidable()
{
    Game::getPhysicSystem().UnregisterEntity(this);
}

float Collidable::getLeft() const
{
    return m_Entity->getPosition().x - m_size.x/2;
}

float Collidable::getRight() const
{
    return m_Entity->getPosition().x + m_size.x/2;
}

float Collidable::getTop() const
{
    return m_Entity->getPosition().y - m_size.y/2;
}

float Collidable::getBottom() const
{
    return m_Entity->getPosition().y + m_size.y/2;
}

sf::Vector2f Collidable::getCenter() const
{
    return sf::Vector2f(m_Entity->getPosition().x, m_Entity->getPosition().y);
}

sf::Vector2f Collidable::getSize() const
{
    return m_size;
}

void Collidable::setSize(sf::Vector2f _size)
{
    m_size = _size;
}


