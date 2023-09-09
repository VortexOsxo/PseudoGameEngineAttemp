#pragma once

namespace sf {
    class RenderWindow;
}

class Window
{
public:
    ~Window();
    
    static Window* GetInstance();
    static void DeleteInstance();

    static sf::RenderWindow* GetWindow();

private:
    Window();

    static Window* window;

private:
    sf::RenderWindow* renderWindow;
};