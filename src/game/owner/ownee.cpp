#include <game/owner/ownee.h>

void Ownee::SetToDelete() 
{
    bShouldDelete = true;
}

bool Ownee::ShouldDelete() const
{
    return bShouldDelete;
}