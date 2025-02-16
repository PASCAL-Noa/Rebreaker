#pragma once

namespace Breakout
{
    
    class Border : Entity, Renderable
    {
    public:
        Border();
        ~Border() override = default;

        void Update(float dt) override;
    };
    
}

