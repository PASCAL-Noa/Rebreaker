#pragma once

#define ANIM_FRAMES 8

namespace Breakout
{
    
    class ComboFire : public Entity, public Renderable
    {
    public:
        ComboFire(const sf::Vector2f& pos);
        ~ComboFire() override = default;

        void setOpacity(float opacity);
        
        void Update(float dt) override;

    private:
        unsigned int m_frame;
        float m_elapsedTime;
        bool m_displayFire;
    };
    
}

