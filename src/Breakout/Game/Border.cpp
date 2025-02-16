#include "pch.h"
#include "Border.h"

#include "AssetLoader/AssetLoader.hpp"

namespace Breakout
{
    Border::Border() : Entity(), Renderable(&AssetLoader::borderTexture, this)
    {
        setPosition(45, 40);
        setScale(0.95f, 0.9f);
    }

    void Border::Update(float dt) {}


}

