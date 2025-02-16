#pragma once

class Image : public Entity, public Renderable, public Collidable
{
public:

    Image(const sf::Texture* texture, float posX, float posY, float baseScaleX, float baseScaleY, float force=0);

    void OnHit(Collider* collider) override;
    void Update(float dt) override;

private:
    float m_baseScaleX;
    float m_baseScaleY;
    float m_force;
    
    float m_totalTime = 0;
    
};
