#include "pch.h"
#include "BrickItem.h"

#include "../Ball.h"
#include "BigBall.h"
#include "BigPaddle.h"
#include "Laser.h"
#include "MultiBall.h"
#include "SpeedUp.h"
#include "../BrickComboText.h"

namespace Breakout
{
    BrickItem::BrickItem(int _pv, sf::Color _color) :
    Brick(_pv, _color)
    {
        
    }
    
    void BrickItem::OnHit(Collider* collider)
    {
        if (!dynamic_cast<Ball*>(collider)) return;
        int randItem = std::rand()%5;
        switch (randItem)
        {
            case 0:
                new Item<BigBall>(getPosition(), &AssetLoader::powerup, &AssetLoader::ballSound, 2);
                break;
            case 1:
                new Item<MultiBall>(getPosition(), &AssetLoader::powerup, &AssetLoader::ballSound, 2);
                break;
            case 2:
                new Item<Laser>(getPosition(), &AssetLoader::powerup, &AssetLoader::ballSound, 2);
                break;
            case 3:
                new Item<BigPaddle>(getPosition(), &AssetLoader::powerup, &AssetLoader::ballSound, 2);
                break;
            case 4:
                new Item<SpeedUp>(getPosition(), &AssetLoader::powerup, &AssetLoader::ballSound, 10);
                break;
        }
        CameraShake(sf::Vector2f(1, 1), .2f, Tweening::EaseOutQuart);
        Game::getScoreManager().AddScore(m_score);
        new BrickComboText("x" + std::to_string(Game::getScoreManager().GetScoreSize()), getPosition());
        delete this;
    }
}
