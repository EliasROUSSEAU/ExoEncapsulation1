#ifndef WORLD_H__
#define WORLD_H__

#include "Entity.h"
#include "StaticObject.h"
#include "BreakableObject.h"
#include "Mob.h"
#include "Player.h"

class World {
private:
    Entity** entities;
    int entityCount;

public:
    World();
    ~World();
    void Init();
    void Step();
};

#endif
