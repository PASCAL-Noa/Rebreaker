#include "pch.h"
#include "Jukebox.h"

#include "AssetLoader/Sound.h"

namespace Breakout
{
    Jukebox::Jukebox(std::vector<Music*> _musics)
    :   m_currentlyPlaying(0),
        elapsedTime(0)
    {
        for (Music* music : _musics)
        {
            m_playlist.push_back(music);
        }

        m_music = m_playlist[rand() % m_playlist.size()];
        m_music->setVolume(4);
        m_music->setLoop(true);
        m_music->play();
    }

    Jukebox::~Jukebox()
    {
        m_music->stop();
    }

    void Jukebox::Update(float dt)
    {
        elapsedTime += dt;
        if (elapsedTime > 60)
        {
            NextMusic();
            elapsedTime = 0;
        }
    }

    void Jukebox::PlaySound(Sound* sound)
    {
        sound->setVolume(8);
        sound->setPitch(0.8);
        sound->play();
    }
    
    void Jukebox::PlayMusic(Music* _music)
    {
        m_music->pause();
        _music->setVolume(4);
        _music->play();
        m_music = _music;
    }

    void Jukebox::NextMusic()
    {

        m_music->stop();
        m_currentlyPlaying++;
        if (m_currentlyPlaying >= m_playlist.size()) m_currentlyPlaying = 0;
        Music* music = m_playlist[m_currentlyPlaying];

        music->setVolume(4);
        music->setLoop(true);
        music->play();
    
        m_music = music;
    }
}