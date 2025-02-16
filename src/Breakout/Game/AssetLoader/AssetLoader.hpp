#pragma once
#include "Font.h"
#include "Music.h"
#include "Shader.h"
#include "Sound.h"
#include "Texture.h"

struct AssetLoader
{
    const static inline Breakout::Texture ballTexture = Breakout::Texture("Ball.png");
    const static inline Breakout::Texture brickTexture = Breakout::Texture("Brick.png");
    const static inline Breakout::Texture paddleTexture = Breakout::Texture("Paddle.png");
    const static inline Breakout::Texture borderTexture = Breakout::Texture("Border.png");
    const static inline Breakout::Texture fireTexture = Breakout::Texture("Fire.png");
    const static inline Breakout::Texture crackTexture = Breakout::Texture("Crack.png");
    
    const static inline Breakout::Texture menuTitle = Breakout::Texture("MenuTitle.png");
    const static inline Breakout::Texture menuStart = Breakout::Texture("MenuStart.png");
    
    const static inline Breakout::Texture fissureGameOver = Breakout::Texture("fissureGameOver.png");
    const static inline Breakout::Texture heart = Breakout::Texture("heart.png");
    
    const static inline Breakout::Texture powerup = Breakout::Texture("powerup.png");
    
    static inline Breakout::Shader colorShader = Breakout::Shader("Color.frag", sf::Shader::Fragment);
    static inline Breakout::Shader brickShader = Breakout::Shader("Brick.frag", sf::Shader::Fragment);

    static inline Breakout::Sound ballSound = Breakout::Sound("ballHit.wav");
    static inline Breakout::Sound paddleSound = Breakout::Sound("paddleHit.wav");
    static inline Breakout::Sound thunder = Breakout::Sound("lightning.wav");
    static inline Breakout::Sound combo = Breakout::Sound("combo.wav");
    static inline Breakout::Sound brickHit = Breakout::Sound("brickHit.wav");
    static inline Breakout::Sound brickDestroy = Breakout::Sound("brickDestroy.wav");
    
    static inline Breakout::Sound brickSound = Breakout::Sound("brickHit.wav");
    static inline Breakout::Sound gameOverSound = Breakout::Sound("gameOver.mp3");
    static inline Breakout::Sound victorySound = Breakout::Sound("victory.mp3");
    
    static inline Breakout::Music musicTheme1 = Breakout::Music("Game-1.ogg");
    static inline Breakout::Music musicTheme2 = Breakout::Music("Game-2.ogg");
    static inline Breakout::Music musicTheme3 = Breakout::Music("Game-3.ogg");
    static inline Breakout::Music musicTheme4 = Breakout::Music("Game-4.ogg");
    static inline Breakout::Music musicMenu = Breakout::Music("Game-menu.ogg");
    static inline Breakout::Music musicDeath = Breakout::Music("Game-death.ogg");

    const static inline Breakout::Font textFont = Breakout::Font("vt323.ttf");
};
