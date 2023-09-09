#include <context.h>
#include <Utils/Window.h>

Context::Context()
{
    window = Window::GetInstance()->GetWindow();
}

bool Context::HandleEvents(float time)
{
    sf::Event event;
    bool bReturn = true;
    while (window->pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
        {
            window->close();
            return false; 
        }
        bReturn &= HandleEventIntern(time, event);
    }
    bReturn &= HandleEventsImplementation(time);
    return bReturn;
}