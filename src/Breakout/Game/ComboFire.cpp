#include "pch.h"
#include "ComboFire.h"

#include "AssetLoader/AssetLoader.hpp"

namespace Breakout
{

    ComboFire::ComboFire(const sf::Vector2f& pos) : Renderable(&AssetLoader::fireTexture, this), m_frame(1), m_elapsedTime(0.0f)
    {
        m_vertices[0].position = sf::Vector2f(0, 0);
        m_vertices[1].position = sf::Vector2f(m_texture->getSize().x/8.0f, 0);
        m_vertices[2].position = sf::Vector2f(0, m_texture->getSize().y);
        m_vertices[3].position = sf::Vector2f(m_texture->getSize().x/8.0f, 0);
        m_vertices[4].position = sf::Vector2f(m_texture->getSize().x/8.0f, m_texture->getSize().y);
        m_vertices[5].position = sf::Vector2f(0, m_texture->getSize().y);
        
        m_vertices[0].texCoords = sf::Vector2f(0, 0);
        m_vertices[1].texCoords = sf::Vector2f(m_texture->getSize().x/8.0f, 0);
        m_vertices[2].texCoords = sf::Vector2f(0, m_texture->getSize().y);
        m_vertices[3].texCoords = sf::Vector2f(m_texture->getSize().x/8.0f, 0);
        m_vertices[4].texCoords = sf::Vector2f(m_texture->getSize().x/8.0f, m_texture->getSize().y);
        m_vertices[5].texCoords = sf::Vector2f(0, m_texture->getSize().y);
        
        new ScaleTweener(this, sf::Vector2f(5, 5), 0.3);
        //setScale(5, 5);
        setPosition(pos);
    }

    void ComboFire::Update(float dt)
    {
        if(m_elapsedTime >= .1)
        {
            if (m_frame >= ANIM_FRAMES) m_frame = 1;
            m_vertices[0].texCoords = sf::Vector2f((m_frame-1.0) * m_texture->getSize().x/ANIM_FRAMES, 0);
            m_vertices[1].texCoords = sf::Vector2f( m_frame * m_texture->getSize().x/ANIM_FRAMES, 0);
            m_vertices[2].texCoords = sf::Vector2f((m_frame-1.0) * m_texture->getSize().x/ANIM_FRAMES, m_texture->getSize().y);
            m_vertices[3].texCoords = sf::Vector2f( m_frame * m_texture->getSize().x/ANIM_FRAMES, 0);
            m_vertices[4].texCoords = sf::Vector2f(m_frame * m_texture->getSize().x/ANIM_FRAMES, m_texture->getSize().y);
            m_vertices[5].texCoords = sf::Vector2f((m_frame-1.0) * m_texture->getSize().x/ANIM_FRAMES, m_texture->getSize().y);
            m_elapsedTime = 0;
            m_frame += 1;
        }
        m_elapsedTime += dt;
    }

    void ComboFire::setOpacity(float opacity)
    {
        m_vertices[0].color = sf::Color(255, 255, 255, opacity);
        m_vertices[1].color = sf::Color(255, 255, 255, opacity);
        m_vertices[2].color = sf::Color(255, 255, 255, opacity);
        m_vertices[3].color = sf::Color(255, 255, 255, opacity);
        m_vertices[4].color = sf::Color(255, 255, 255, opacity);
        m_vertices[5].color = sf::Color(255, 255, 255, opacity);
    }

    
}
