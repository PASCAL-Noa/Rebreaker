#pragma once
class Renderable;

class RenderSystem
{
public:
    RenderSystem();
    ~RenderSystem();
    
    void Render() const;

    void RegisterEntity(Renderable* component);
    void UnregisterEntity(const Renderable* component);

    sf::Color& GetColor();
    void SetColor(const sf::Color& color);
    
private:
    std::vector<Renderable*> m_entities;

    sf::Color m_color = sf::Color(72,72,72,255);
    
    sf::RenderTexture* m_blurTexture;
    sf::RenderTexture* m_renderTexture;
    sf::RenderTexture* m_brightTexture;

    sf::Shader* m_postProcess;
    sf::Shader* m_BlurShader;
    sf::Shader* m_ThresholdShader;
    
};
