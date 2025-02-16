#include "pch.h"
#include "Renderable.h"

Renderable::Renderable(Entity* parent) :
    Component(parent),
    m_texture(nullptr),
    m_shader(nullptr)
{
    Game::getRenderSystem().RegisterEntity(this);
}

Renderable::Renderable(const sf::Texture* texture, Entity* parent) :
    Component(parent),
    m_texture(texture),
    m_shader(nullptr)
{
    setVertices();
    Game::getRenderSystem().RegisterEntity(this);
}

Renderable::Renderable(const sf::Texture* texture, sf::Shader* shader, Entity* parent) :
    Component(parent),
    m_texture(texture),
    m_shader(shader)
{
    setVertices();
    Game::getRenderSystem().RegisterEntity(this);
}

Renderable::~Renderable()
{
    Game::getRenderSystem().UnregisterEntity(this);
}


const sf::Texture* Renderable::getTexture() const
{
    return m_texture;
}

sf::VertexArray& Renderable::getVertexArray()
{
    return m_vertices;
}

sf::Shader* Renderable::getShader()
{
    return m_shader;
}


void Renderable::setVertices()
{
    m_vertices = sf::VertexArray(sf::Triangles, 6);
    
    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(m_texture->getSize().x, 0);
    m_vertices[2].position = sf::Vector2f(0, m_texture->getSize().y);

    m_vertices[3].position = sf::Vector2f(m_texture->getSize().x, 0);
    m_vertices[4].position = sf::Vector2f(m_texture->getSize().x, m_texture->getSize().y);
    m_vertices[5].position = sf::Vector2f(0, m_texture->getSize().y);

    m_vertices[0].texCoords = sf::Vector2f(0, 0);
    m_vertices[1].texCoords = sf::Vector2f(m_texture->getSize().x, 0);
    m_vertices[2].texCoords = sf::Vector2f(0, m_texture->getSize().y);

    m_vertices[3].texCoords = sf::Vector2f(m_texture->getSize().x, 0);
    m_vertices[4].texCoords = sf::Vector2f(m_texture->getSize().x, m_texture->getSize().y);
    m_vertices[5].texCoords = sf::Vector2f(0, m_texture->getSize().y);
}



