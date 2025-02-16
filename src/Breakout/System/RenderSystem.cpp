#include "pch.h"

RenderSystem::RenderSystem() :
    m_renderTexture(new sf::RenderTexture),
    m_brightTexture(new sf::RenderTexture),
    m_blurTexture(new sf::RenderTexture),
    m_postProcess(new sf::Shader),
    m_BlurShader(new sf::Shader),
    m_ThresholdShader(new sf::Shader),
    m_color(sf::Color(72, 72, 72, 255))
{
    m_renderTexture->create(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_brightTexture->create(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_blurTexture->create(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_brightTexture->setSmooth(true);
    m_blurTexture->setSmooth(true);
    m_renderTexture->setSmooth(true);

    m_postProcess->loadFromFile(Utils::getResourcesPath() + "/Shaders/PostProcess.frag", sf::Shader::Fragment);
    m_BlurShader->loadFromFile(Utils::getResourcesPath() + "/Shaders/Blur.frag", sf::Shader::Fragment);
    m_ThresholdShader->loadFromFile(Utils::getResourcesPath() + "/Shaders/Threshold.frag", sf::Shader::Fragment);
}

RenderSystem::~RenderSystem()
{
    delete m_renderTexture;
    delete m_brightTexture;
    delete m_blurTexture;
    delete m_postProcess;
    delete m_BlurShader;
    delete m_ThresholdShader;
}


void RenderSystem::RegisterEntity(Renderable* entity)
{
    if (entity == nullptr) return;
    m_entities.push_back(entity);
}

void RenderSystem::UnregisterEntity(const Renderable* entity)
{
    if (entity == nullptr) return;
    auto it = std::find(m_entities.begin(), m_entities.end(), entity);
    m_entities.erase(it);
}

sf::Color& RenderSystem::GetColor()
{
    return m_color;
}

void RenderSystem::SetColor(const sf::Color& color)
{
    m_color = color;
}

void RenderSystem::Render() const
{
    m_renderTexture->clear(m_color);
    m_brightTexture->clear();

    Game::getTextSystem().Render(m_renderTexture);
    Game::getParticleSystem().Render(m_renderTexture);
    
    // Dessin des entités dans m_renderTexture
    for(Renderable* component : m_entities)
    {
        sf::RenderStates state = sf::RenderStates::Default;
        state.transform *= component->getEntity()->getTransform();
        state.texture = component->getTexture();
        state.shader = component->getShader();
        m_renderTexture->draw(component->getVertexArray(), state);
    }
    m_renderTexture->display();

    // Pass 1 : Extraction des zones lumineuses
    m_ThresholdShader->setUniform("screen_texture", m_renderTexture->getTexture());
    m_brightTexture->draw(sf::Sprite(m_renderTexture->getTexture()), m_ThresholdShader);
    m_brightTexture->display();

    // Pass 2 : Flou horizontal
    m_blurTexture->clear();
    m_BlurShader->setUniform("direction", sf::Glsl::Vec2(3.0f, 0.f)); // Flou horizontal
    m_BlurShader->setUniform("screen_texture", m_brightTexture->getTexture());
    m_blurTexture->draw(sf::Sprite(m_brightTexture->getTexture()), m_BlurShader);
    m_blurTexture->display();

    // Pass 3 : Flou vertical
    m_brightTexture->clear();
    m_BlurShader->setUniform("direction", sf::Glsl::Vec2(0.f, 3.0f)); // Flou vertical
    m_BlurShader->setUniform("screen_texture", m_blurTexture->getTexture());
    m_brightTexture->draw(sf::Sprite(m_blurTexture->getTexture()), m_BlurShader);
    m_brightTexture->display();

    // Pass 4 : Combinaison et dessin final
    m_postProcess->setUniform("screen_texture", m_renderTexture->getTexture());
    m_postProcess->setUniform("bloom_texture", m_brightTexture->getTexture());
    
    Game::getWindow().draw(sf::Sprite(m_renderTexture->getTexture()), m_postProcess);
}


