#pragma once
#include "Ball.h"
#include "Jukebox.h"

class Image;

class Level
{
public:
    Level();
    ~Level();
    
    void Load( int levelIndex );
    void Start();

    void Win();
    void Loose();

private:

    bool m_ShouldClose;
    bool loadLevelFromFile(const std::string& filename);
    bool isLoose = false;
    Breakout::Text* win;
    Breakout::Text* restart;
    Breakout::Text* finalScore;

    Image* fissure;
    Image* fissureBis;
    Breakout::Text* gameOver;
    Breakout::Text* titleScore;
    Breakout::Text* bestScore;

    Breakout::Jukebox* jukebox;
    
};
