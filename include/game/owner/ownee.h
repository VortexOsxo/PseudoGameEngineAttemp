#pragma once

class Ownee
{
public:
    Ownee() = default;
    virtual ~Ownee() = default;

    void SetToDelete();
    bool ShouldDelete() const;

private:
    bool bShouldDelete = false;
};