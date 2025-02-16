#include "pch.h"
#include "SoundPlayer.h"

void SoundPlayer::PlaySound(sf::Sound* sound)
{
    sound->play();
}

void SoundPlayer::PlaySound(sf::Sound* sound, float pitch)
{
    sound->setPitch(pitch);
    sound->play();
}

void SoundPlayer::PlaySound(sf::Sound* sound, float volume, float pitch)
{
    sound->setVolume(volume);
    sound->setPitch(pitch);
    sound->play();
}
