#pragma once
#include "Component.h"

class Collider;

class Collidable : public Component
{
public:
    Collidable(Entity* _parent, const sf::Vector2f& size);
    ~Collidable() override;

    virtual void OnHit(Collider* collider) = 0;

    float getLeft() const;
    float getRight() const;
    float getTop() const;
    float getBottom() const;
    sf::Vector2f getCenter() const;

    sf::Vector2f getSize() const;
    void setSize(sf::Vector2f );
private:
    sf::Vector2f m_size;
};
