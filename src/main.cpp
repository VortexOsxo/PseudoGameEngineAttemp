#include <Utils/Window.h>

#include <context.h>
#include <game/game.h>

#include <iostream>

int main() {
    Window::GetInstance();
    Game* context = Game::GetInstance();
    context->SpawnPlayer();
    
    bool bIsRunning = true;
    sf::Clock frameClock;

    while (bIsRunning) {
        float elapsedTime = frameClock.restart().asMilliseconds();
        
        context->Draw();
        bIsRunning &= context->HandleEvents(elapsedTime);
        bIsRunning &= context->Update(elapsedTime);
        
        #ifdef FPS
        float fps = 1.0f / (elapsedTime * 0.001f);
        std::cout << fps << std::endl;
        #endif
    }
    delete context;

    Window::DeleteInstance();
    return 0;
}

