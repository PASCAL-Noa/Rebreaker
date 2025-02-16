#pragma once
#include "pch.h"

enum CollisionSide : uint8_t
{
    Left,
    Right,
    Top,
    Bottom,
    None
};

class Collider : public Component {
public:
    Collider(Entity* parent, const sf::Vector2f& size);
    ~Collider() override;

    virtual void OnCollisionEnter(Collidable* collider, CollisionSide side) = 0;
    virtual bool Collide(Collidable* other) = 0;

    float getLeft() const;
    float getRight() const;
    float getTop() const;
    float getBottom() const;
    
    sf::Vector2f getCenter() const;
    void setSize(sf::Vector2f _size);
    sf::Vector2f& getSize();

    CollisionSide& getSide();
    
protected:
    sf::Vector2f m_size;
    CollisionSide m_collisionSide;
};