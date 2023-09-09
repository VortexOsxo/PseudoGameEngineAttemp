#include <game/game.h>
#include <Utils/Window.h>

#include <game/tick_system/tick_manager.h>
#include <game/rendering/rendering_system.h>

#include <iostream>

Game::Game() 
{
    tickManager = TickManager::GetInstance();
    
    map = std::make_unique<Map>(750.f);
    projectileOwner = std::make_unique<ProjectileOwner>(this);
    enemyOwner = std::make_unique<EnemyOwner>();
}

void Game::SpawnPlayer()
{
    player = std::make_unique<Player>( Vector2D(0,0), 25);
}

Game::~Game()
{
    delete tickManager;
    instance = nullptr;
}

Game *Game::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new Game();
    }
    return instance;
}

bool Game::Update(float time)
{
    tickManager->CallTick(time);
    return player->GetHealth() > 0;
}

bool Game::HandleEventsImplementation(float time)
{
    Vector2D direction = Vector2D::ZeroVector;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        direction += {0.f,-1.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        direction += {0.f,1.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        direction += {-1.f,0.f};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        direction += {1.f,0.f};
    }
    
    Vector2D initialPos = player->GetPosition();
    player->GetMovementComponent()->Move(direction, time);
    if(!map->IsInside(player.get()))
    {
        player->SetPosition(initialPos);
    }
    return true;
}

bool Game::HandleEventIntern(float time, const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Key::LShift || event.key.code == sf::Keyboard::Key::RShift)
        {
            player->GetMovementComponent()->MovementAbility();
        }
        else if (event.key.code == sf::Keyboard::Space) {
            player->Attack();
        }
    }
    return true;
}

void Game::Draw()
{
    static RenderingSystem* renderingSystem = RenderingSystem::GetInstance();

    window->clear();

    renderingSystem->SetRelativePosition(player->GetPosition());
    renderingSystem->Render();

    window->display();
}

Game* Game::instance = nullptr;