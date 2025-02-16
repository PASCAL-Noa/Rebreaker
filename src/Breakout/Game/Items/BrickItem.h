#pragma once
#include "Item.hpp"
#include "../Brick.h"
#include "../AssetLoader/AssetLoader.hpp"


namespace Breakout
{
    
    class BrickItem : public Brick
    {
    public:
        BrickItem( int m_pv, sf::Color m_color);
        ~BrickItem() override = default;
        
        void OnHit(Collider* collider) override;
        
    };
    
}

