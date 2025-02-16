#pragma once

#define PADDLE_SPEED 500.0f
#define PADDLE_X WINDOW_WIDTH / 2
#define PADDLE_Y WINDOW_HEIGHT/2 + 300

namespace Breakout
{
    class Paddle : public  Entity, public Renderable, public Collidable, public SoundPlayer
    {
    public:
        Paddle();
        void Update(float dt) override;
        void OnHit(Collider* collider) override;

        float getCurrentSpeed() const;
        float getCurrentScale();
        void setPaddleScale(float scaleX);

    private:
        float m_currentSpeed = 0;
        float m_scaleX = 1;
    }; 
}
