#pragma once


static class SoundPlayer
{
public:
    static void PlaySound(sf::Sound* sound);
    static void PlaySound(sf::Sound* sound, float pitch);
    static void PlaySound(sf::Sound* sound, float volume, float pitch);
};
