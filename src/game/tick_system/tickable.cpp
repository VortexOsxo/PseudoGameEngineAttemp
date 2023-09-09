#include "game/tick_system/tick_manager.h"
#include "game/tick_system/tickable.h"

Tickable::Tickable()
{
    RegisterToTickManager();
}

Tickable::~Tickable()
{
    UnregisterFromTickManager();
}

void Tickable::RegisterToTickManager()
{
    TickManager::GetInstance()->AddTickObject(this);
}

void Tickable::UnregisterFromTickManager()
{
    TickManager::GetInstance()->RemoveTickObject(this);
}
