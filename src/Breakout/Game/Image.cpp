#include "pch.h"
#include "Image.h"

Image::Image(const sf::Texture* texture, float posX, float posY, float baseScaleX, float baseScaleY, float force)
    :
Entity(sf::Vector2f(posX, posY)),
Renderable(texture, this),
Collidable(this, sf::Vector2f(posX, posY)),
m_force(force)
{
    m_baseScaleX = baseScaleX;
    m_baseScaleY = baseScaleY;
    setOrigin(m_texture->getSize().x / 2, m_texture->getSize().y / 2);
    setScale(baseScaleX, baseScaleY);
    setSize(sf::Vector2f(m_texture->getSize().x, m_texture->getSize().y));
}

void Image::OnHit(Collider* collider)
{
}

void Image::Update(float dt)
{
    m_totalTime += dt;
    float factor = m_force * std::sin((m_totalTime+5)/0.8)+1;
    factor = std::max(factor, 1.0f);
    setScale(m_baseScaleX * factor, m_baseScaleY * factor);
}
