#pragma once
#include "AssetLoader/Music.h"
#include "AssetLoader/Sound.h"

namespace Breakout
{
    class Jukebox
    {
    public:
        Jukebox(std::vector<Music*> _musics);
        ~Jukebox();

        void Update(float dt);
        void NextMusic();
        void PlaySound(Sound* sound);
        void PlayMusic(Music* music);

    private:
        std::vector<Music*> m_playlist;
        Music* m_music;
        int m_currentlyPlaying;

        float elapsedTime;
    
    };
   
}