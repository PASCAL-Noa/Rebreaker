#pragma once
#include "../Utils/Tweeners/ScaleTweener.h"
#include "../Utils/Tweeners/Tweener.h"

class Tweener;

class TweeningSystem
{
public:
    TweeningSystem() = default;
    ~TweeningSystem() = default;

    void Tween(float dt) const;

    void AddTweener(Tweener* tween);
    void RemoveTweener(const Tweener* tween);
    void Clear();

    template<typename T>
    bool IsTweening() const;
    
private:
    
    std::vector<Tweener*> m_tweeners;
};

template <typename T>
bool TweeningSystem::IsTweening() const
{
    for (Tweener* tweener : m_tweeners)
    {
        if(dynamic_cast<T*>(tweener))
        {
            return true;
        }
    }
    return false;
}