#ifndef ENTITY_H__
#define ENTITY_H__

#include <string>
#include "Vector2.h"

class Entity {
protected:
    Vector2 Position;

public:

    virtual void SetPosition(float _x, float _y);
    virtual Vector2 GetPosition();

    Entity(float, float);
};

#endif