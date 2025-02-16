#pragma once

#define BRICK_TEXT_LIFETIME 1.0

namespace Breakout
{
    
    class BrickComboText : public Entity
    {
    public:
        BrickComboText(const std::string& text, const sf::Vector2f& pos);
        ~BrickComboText() override;

        void Update(float dt) override;

    private:
        float m_elapsedTime = 0;
        Text* m_text;
    };
        
}
