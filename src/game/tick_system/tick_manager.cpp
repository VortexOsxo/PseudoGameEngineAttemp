#include "game/tick_system/tick_manager.h"
#include "game/tick_system/tickable.h"

#include <algorithm>

TickManager *TickManager::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = new TickManager();
    }
    return Instance;
}

void TickManager::DeleteInstance()
{
    if (Instance != nullptr)
    {
        delete Instance;
    }
}

void TickManager::CallTick(float time) 
{
    for (Tickable* tickObject : addedObjects)
    {
        tickObjects.push_back(tickObject);
    }
    addedObjects.clear();

    for (Tickable* tickObject : tickObjects)
    {
        if (std::find(removedObjects.begin(), removedObjects.end(), tickObject) != removedObjects.end())
            continue;
        tickObject->Tick(time);
    }
    removedObjects.clear();
}

void TickManager::AddTickObject(Tickable* tickable)
{
    for (const Tickable* tickObject : tickObjects)
    {
        if (tickObject == tickable)
        {
            return;
        }
    }
    addedObjects.push_back(tickable);
}

void TickManager::RemoveTickObject(Tickable* tickable)
{
    removedObjects.push_back(tickable);
    for (auto it = tickObjects.begin(); it != tickObjects.end(); ++it)
    {
        if (*it == tickable)
        {
            tickObjects.erase(it);
            return;
        }
    }
    for (auto it = addedObjects.begin(); it != addedObjects.end(); ++it)
    {
        if (*it == tickable)
        {
            addedObjects.erase(it);
            return;
        }
    }
}

TickManager* TickManager::Instance = nullptr;