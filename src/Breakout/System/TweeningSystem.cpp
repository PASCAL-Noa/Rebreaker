#include "pch.h"
#include "TweeningSystem.h"

void TweeningSystem::Tween(const float dt) const
{
    for (int i = 0; i < m_tweeners.size(); i++)
    {
        m_tweeners[i]->Update(dt);
    }
}

void TweeningSystem::AddTweener(Tweener* tween)
{
    m_tweeners.push_back(tween);
}

void TweeningSystem::RemoveTweener(const Tweener* tween)
{
    auto it = std::find(m_tweeners.begin(), m_tweeners.end(), tween);
    
    if (it != m_tweeners.end())
        m_tweeners.erase(it);
    
}

void TweeningSystem::Clear()
{
    m_tweeners.clear();
}
