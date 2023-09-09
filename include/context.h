#pragma once

#include <SFML/Graphics.hpp>

class Context
{
public:
    Context();
    virtual ~Context() = default;

    virtual bool Update(float time) =0;
    bool HandleEvents(float time);
    virtual void Draw() =0;

private:
    virtual bool HandleEventsImplementation(float time) { return true; }
    virtual bool HandleEventIntern(float time, const sf::Event& event) { return true; };

protected:
    sf::RenderWindow* window = nullptr;
};