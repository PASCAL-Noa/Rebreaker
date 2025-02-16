#include "pch.h"
#include "RectCollider.h"

RectCollider::RectCollider(Entity* parent, const sf::Vector2f& size) : Collider(parent, size) {}

bool RectCollider::Collide(Collidable* other)
{
    // Vérifiez si les deux objets se chevauchent
    if (getRight() < other->getLeft() || getLeft() > other->getRight() ||
        getBottom() < other->getTop() || getTop() > other->getBottom())
    {
        // Pas de collision
        m_collisionSide = None; // Assurez-vous d'avoir une valeur None pour représenter l'absence de collision
        return false;
    }

    // Calcul des chevauchements
    float overlapLeft = other->getRight() - getLeft();
    float overlapRight = getRight() - other->getLeft();
    float overlapTop = other->getBottom() - getTop();
    float overlapBottom = getBottom() - other->getTop();

    // Trouver le chevauchement minimum
    float minOverlap = overlapLeft;
    m_collisionSide = Left; // On commence par supposer que c'est à gauche

    if (overlapRight < minOverlap) {
        minOverlap = overlapRight;
        m_collisionSide = Right;
    }
    if (overlapTop < minOverlap) {
        minOverlap = overlapTop;
        m_collisionSide = Bottom;
    }
    if (overlapBottom < minOverlap) {
        minOverlap = overlapBottom;
        m_collisionSide = Top;
    }

    return true;
}
