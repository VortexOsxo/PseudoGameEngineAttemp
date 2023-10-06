#include <animation/animation.h>

class AnimationSystem 
{
public:
    ~AnimationSystem() = default;

    static AnimationSystem* GetInstance();

    void AddAnimation(Animation animation);

private:
    AnimationSystem() {};
private:
    static AnimationSystem* instance;
};