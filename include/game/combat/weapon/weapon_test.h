#pragma once

#include "weapon_base.h"
#include <game/other/cooldown.h>

class WeaponTest : public WeaponBase
{
public:
    WeaponTest();
    virtual ~WeaponTest();

    virtual void Use() override;

private:
    Cooldown cooldown = Cooldown(1.5f);
};