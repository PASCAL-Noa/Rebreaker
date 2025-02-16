#pragma once
#include "Component.h"

class Entity;

class Renderable : public Component
{
public:
    Renderable(Entity* parent);
    Renderable(const sf::Texture* texture, Entity* parent);
    Renderable(const sf::Texture* texture, sf::Shader* shader, Entity* parent);
    ~Renderable() override;

    const sf::Texture* getTexture() const;
    virtual sf::Shader* getShader(); 
    sf::VertexArray& getVertexArray();

private:
    void setVertices();
    //By default, we draw a plane made out of two triangles to display a simple sprite
protected:
    sf::VertexArray m_vertices;
    const sf::Texture* m_texture;
    sf::Shader* m_shader;
};
