#include "Utils/Window.h"

#include <SFML/Graphics.hpp>

Window::Window()
{
    renderWindow = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0], "Space Fighter", sf::Style::Fullscreen);
    renderWindow->setFramerateLimit(1200.f);
}

Window::~Window() 
{
    delete renderWindow;
}

Window *Window::GetInstance()
{
    if (window == nullptr) 
    {
        window = new Window();
    }
    return window;
}

void Window::DeleteInstance()
{
    if (window != nullptr)
    {
        delete window;
        window = nullptr;
    }
}

sf::RenderWindow *Window::GetWindow()
{
    if (window != nullptr) {
        return window->renderWindow;
    }
    return nullptr;
}

Window* Window::window = nullptr;