#include "pch.h"
#include "Collider.h"

Collider::Collider(Entity* _parent, const sf::Vector2f& size) : Component(_parent), m_size(size), m_collisionSide(Top)
{
    Game::getPhysicSystem().RegisterEntity(this);
}

Collider::~Collider()
{
    Game::getPhysicSystem().UnregisterEntity(this);
}

float Collider::getLeft() const
{
    return m_Entity->getPosition().x - m_size.x/2.0f;
}

float Collider::getRight() const
{
    return m_Entity->getPosition().x + m_size.x/2.0f;
}

float Collider::getTop() const
{
    return m_Entity->getPosition().y - m_size.y/2.0f;
}

float Collider::getBottom() const
{
    return m_Entity->getPosition().y + m_size.y/2.0f;
}

sf::Vector2f& Collider::getSize()
{
    return m_size;
}

sf::Vector2f Collider::getCenter() const
{
    return sf::Vector2f(m_Entity->getPosition().x, m_Entity->getPosition().y);
}

void Collider::setSize(sf::Vector2f _size)
{
    m_size = _size;
}

CollisionSide& Collider::getSide()
{
    return m_collisionSide;
}







