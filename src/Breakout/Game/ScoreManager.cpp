#include "pch.h"
#include "ScoreManager.h"

#include "ComboFire.h"
#include "fstream"
#include "AssetLoader/AssetLoader.hpp"

ScoreManager::ScoreManager() :
    m_scoreText(nullptr),
    m_score(0),
    m_multiplier(1),
    m_comboScore(0),
    m_elapsedTime(0),
    m_isCombo(false),
    m_comboFire(nullptr)
{}

ScoreManager::~ScoreManager()
{
    delete m_scoreText;
    delete m_comboText;
    delete m_bestScoreText;
}


void ScoreManager::LoadText()
{
    m_scoreText = new Breakout::Text(&AssetLoader::textFont, "0");
    m_comboText = new Breakout::Text(&AssetLoader::textFont, "");
    m_titleBestScoreText = new Breakout::Text(&AssetLoader::textFont, "BEST SCORE : ");
    
    m_bestScoreText = new Breakout::Text(&AssetLoader::textFont, "0");
    LoadScoresFromFile(Utils::getResourcesPath() + "scores.txt");
    m_bestScoreText->SetText(std::to_string(m_scores[0]));
    
    m_scoreText->setCharacterSize(40);
    m_scoreText->setRotation(-2);
    m_scoreText->setPosition(140, 80);
    m_scoreText->scale(sf::Vector2f(2, 2));
    m_scoreText->setOrigin(20, 30);

    m_comboText->setCharacterSize(40);
    m_comboText->setRotation(-2);
    m_comboText->setPosition(m_scoreText->getGlobalBounds().width + 120, 20);
    m_comboText->scale(sf::Vector2f(1.5, 1.5));
    m_comboText->setFillColor(sf::Color(200, 200, 200, 255));

    m_titleBestScoreText->setCharacterSize(25);
    m_titleBestScoreText->setRotation(0);
    m_titleBestScoreText->setPosition(127, 1038);
    m_titleBestScoreText->scale(sf::Vector2f(2, 2));
    m_titleBestScoreText->setOrigin(20, 30);
    
    m_bestScoreText->setCharacterSize(25);
    m_bestScoreText->setRotation(1);
    m_bestScoreText->setPosition(390, 1038);
    m_bestScoreText->scale(sf::Vector2f(2, 2));
    m_bestScoreText->setOrigin(20, 30);
    
}


void ScoreManager::Update(float dt)
{
    if (m_isCombo == false) return;
    
    if (m_elapsedTime >= COMBO_DURATION)
    {
        m_isCombo = false;
        m_score += m_comboScore;
        m_multiplier = 1.0;
        m_comboScore = 0;
        m_scoreText->SetText(std::to_string(m_score));
        m_scoreSize = 1;
        
        new ScaleTweener(m_scoreText, sf::Vector2f(2.7, 2.7), 0.3, [&]()
        {
            new ScaleTweener(m_scoreText, sf::Vector2f(2, 2), 0.2, Tweening::EaseInCubic);
            m_comboText->setPosition(m_scoreText->getGlobalBounds().width + 79, 20);
        },Tweening::EaseOutBounce);
        
         m_elapsedTime = 0;
        if(m_comboFire != nullptr)
        {
            delete m_comboFire;
            m_comboFire = nullptr;
        }
        return;
    }
    
    m_comboText->setFillColor(sf::Color(200, 200, 200, (1 - m_elapsedTime/COMBO_DURATION) * 255));
    if (m_comboFire != nullptr) m_comboFire->setOpacity((1 - m_elapsedTime/COMBO_DURATION) * 255);
    m_elapsedTime += dt;
}

void ScoreManager::AddScore(float m_score)
{
    if (m_isCombo) m_scoreSize ++;
    
    m_isCombo = true;
    m_comboScore += m_multiplier * m_score;
    m_multiplier += 0.2;
    
    std::string scoreText = std::to_string(m_multiplier);
    
    int pos = scoreText.find('.');
    
    m_comboText->SetText(std::to_string(m_comboScore) + "x" + scoreText.substr(0, pos+2));
    m_comboText->setFillColor(sf::Color(200, 200, 200, 255));
    

    if (m_scoreSize >= 5 && m_comboFire == nullptr)
    {
        m_comboFire = new Breakout::ComboFire(sf::Vector2f(m_comboText->getGlobalBounds().left + m_comboText->getGlobalBounds().width + 10, -15));
    }

    SoundPlayer::PlaySound(&AssetLoader::combo, 70, m_multiplier-0.5f);
    
    new PositionTweener(m_comboText,  sf::Vector2f(m_scoreText->getGlobalBounds().width + 120, 50), Tweening::EaseInOutCubic);
    if (m_comboFire) m_comboFire->setPosition(sf::Vector2f(m_comboText->getGlobalBounds().left + m_comboText->getGlobalBounds().width + 10, -15));
    m_elapsedTime = 0; 
}

void ScoreManager::SaveScoreToFile(const std::string& filename)
{
    std::ofstream file(filename, std::ios::app); 
    if (!file)
    {
        std::cerr << "Erreur: impossible d'ouvrir le fichier " << filename << std::endl;
        return;
    }
    file << m_score << std::endl; 
    file.close();
}

std::vector<unsigned int> ScoreManager::LoadScoresFromFile(const std::string& filename)
{
    m_scores.clear();
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Erreur: impossible d'ouvrir le fichier " << filename << std::endl;
        return m_scores;
    }

    unsigned int score;
    while (file >> score)
    { 
        m_scores.push_back(score);
    }
    file.close();

    std::sort(m_scores.begin(), m_scores.end(), std::greater<unsigned int>());
    
    if (m_scores.size() > 5)
    {
        m_scores.resize(5);
    }
    return m_scores;
}

void ScoreManager::EndLevel()
{
    SaveScoreToFile(Utils::getResourcesPath() + "scores.txt");
    m_scoreSize = 0;
    m_score = 0;
}

std::string ScoreManager::DisplayScores()
{
    LoadScoresFromFile(Utils::getResourcesPath() +"scores.txt");

    std::string strScores = "";
    for (size_t i = 0; i < m_scores.size(); ++i) {
        strScores += std::to_string(m_scores[i]) + "\n";
    }
    return strScores;
}

unsigned int ScoreManager::GetScoreSize() const
{
    return m_scoreSize;
}

Breakout::Text* ScoreManager::getComboText()
{
    return m_comboText;
}

unsigned int ScoreManager::GetScore()
{
    return m_score;
}

    


