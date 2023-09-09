#include <vector>

class Tickable;

typedef std::vector<Tickable*> TickObjects;

class TickManager
{
friend Tickable;

public:
    static TickManager* GetInstance();
    static void DeleteInstance();
    
    void CallTick(float time);

private:
    TickManager() {};

    void AddTickObject(Tickable* tickable);
    void RemoveTickObject(Tickable* tickable);

    TickObjects tickObjects;
    TickObjects addedObjects;
    TickObjects removedObjects;

    static TickManager* Instance;
};