#pragma once

namespace Tweening
{
    
    enum Easings
    {
        EaseInSine,
        EaseOutSine,
        EaseInOutSine,

        EaseInCubic,
        EaseOutCubic,
        EaseInOutCubic,

        EaseInQuint,
        EaseOutQuint,
        EaseInOutQuint,

        EaseInCirc,
        EaseOutCirc,
        EaseInOutCirc,

        EaseInElastic,
        EaseOutElastic,
        EaseInOutElastic,

        EaseInQuad,
        EaseOutQuad,
        EaseInOutQuad,

        EaseInQuart,
        EaseOutQuart,
        EaseInOutQuart,

        EaseInExpo,
        EaseOutExpo,
        EaseInOutExpo,

        EaseInBack,
        EaseOutBack,
        EaseInOutBack,

        EaseInBounce,
        EaseOutBounce,
        EaseInOutBounce,

        Spring
        
    };

    typedef float(*EasingFunction)(float);
    EasingFunction getTween(Easings easing);

    float easeInSine(float x);
    float easeOutSine(float x);
    float easeInOutSine(float x);

    
    float easeInCubic(float x);
    float easeOutCubic(float x);
    float easeInOutCubic(float x);

    
    float easeInQuint(float x);
    float easeOutQuint(float x);
    float easeInOutQuint(float x);

    
    float easeInCirc(float x);
    float easeOutCirc(float x);
    float easeInOutCirc(float x);

    
    float easeInElastic(float x);
    float easeOutElastic(float x);
    float easeInOutElastic(float x);

    
    float easeInQuad(float x);
    float easeOutQuad(float x);
    float easeInOutQuad(float x);

    
    float easeInQuart(float x);
    float easeOutQuart(float x);
    float easeInOutQuart(float x);
    

    float easeInExpo(float x);
    float easeOutExpo(float x);
    float easeInOutExpo(float x);

    
    float easeInBack(float x);
    float easeOutBack(float x);
    float easeInOutBack(float x);

    float easeInBounce(float x);
    float easeOutBounce(float x);
    float easeInOutBounce(float x);

    float easeSpring(float f);
}

