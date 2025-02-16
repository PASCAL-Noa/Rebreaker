#pragma once

#define COMBO_DURATION 3.0
#include "Text.h"

namespace Breakout
{
    class ComboFire;
}

class ScoreManager
{
public:
    ScoreManager();
    ~ScoreManager();

    void Update(float dt);
    void AddScore(float m_score);
    unsigned int GetScoreSize() const;
    void LoadText();
    void SaveScoreToFile(const std::string& filename);
    std::vector<unsigned int> LoadScoresFromFile(const std::string& filename);
    void EndLevel();
    std::string DisplayScores();
    Breakout::Text* getComboText();
    unsigned int GetScore();
    
private:
    unsigned int m_score;
    unsigned int m_scoreSize = 1;
    float m_multiplier;
    float m_elapsedTime;
    unsigned int m_comboScore;
    bool m_isCombo = false;
    std::vector<unsigned int> m_scores;
    
    Breakout::Text* m_scoreText;
    Breakout::Text* m_comboText;
    Breakout::Text* m_titleBestScoreText;
    Breakout::Text* m_bestScoreText;
    Breakout::ComboFire* m_comboFire;
};
