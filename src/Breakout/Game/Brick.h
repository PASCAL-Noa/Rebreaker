#pragma once

namespace Breakout
{
    class Brick :  public Entity, public Renderable, public Collidable, public SoundPlayer
    {
    public:
        Brick(unsigned int m_pv, sf::Color color);
        ~Brick() override;
        void Update(float dt) override;
        void OnHit(Collider* collider) override;

        sf::Shader* getShader() override;

        unsigned int getHealthPoint() const;
        void setHealthPoint(unsigned int hp);
        const sf::Color& getColor() const;
        unsigned int getScore() const;

    protected:
        unsigned int m_healthPoint;
        unsigned int m_healthPointMax;
        unsigned int m_score = 200;
        sf::Color m_color;
    };
}


