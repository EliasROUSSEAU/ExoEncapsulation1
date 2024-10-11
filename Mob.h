#ifndef MOB_H__
#define MOB_H__

#include <iostream>
#include "Entity.h"
#include "Alive.h"
#include "AMovable.h"

class Mob : public Entity, public Alive, public AMovable {
public:

    Mob(float _x, float _y, float _life, float _maxLife, Vector2 _direction, float speed);

    void TakeDamage(float _takedamage) override;
    void Deplacer() override;
};

#endif
