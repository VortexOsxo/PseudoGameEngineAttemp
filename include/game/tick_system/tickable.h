#pragma once

class Tickable
{
public:
    Tickable();
    virtual ~Tickable();

    void RegisterToTickManager();
    void UnregisterFromTickManager();

    virtual void Tick(float time) =0;
    virtual bool ShouldTick() const { return true; };
};