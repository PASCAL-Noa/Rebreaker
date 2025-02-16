#pragma once

enum CollisionSide : uint8_t;

class RectCollider : public Collider
{
public:
    RectCollider(Entity* parent, const sf::Vector2f& size);
    void OnCollisionEnter(Collidable* collider, CollisionSide side) override = 0;
    bool Collide(Collidable* other) override;
};
