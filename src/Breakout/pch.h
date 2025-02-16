#pragma once

//STD
#include <iostream>
#include <string>
#include <filesystem>
#include <numbers> 
#include <functional>
#include <map>
#include <array>
#include <algorithm>

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


//Breakout
#include "Game.h"
#include "Utils/Utils.h"
#include "Entity.h"

//Tweening
#include "Utils/Tweeners/Tweener.h"
#include "Utils/Tweeners/PositionTweener.h"
#include "Utils/Tweeners/ScaleTweener.h"
#include "Utils/Tweeners/RotationTweener.h"
#include "Utils/Easings.h"

//Systems
#include "System/RenderSystem.h"
#include "System/TweeningSystem.h"
#include "System/RenderSystem.h"

//Components
#include "Components/Component.h"
#include "Components/Component.h"
#include "Components/Collidable.h"
#include "Components/Collider.h"
#include "Components/Renderable.h"
#include "Components/SoundPlayer.h"
