#ifndef PLAYER_H__
#define PLAYER_H__

#include <string>
#include "Entity.h"
#include "Alive.h"
#include "AMovable.h"
#include "IAttacker.h"

class Player : public Entity, public Alive, public AMovable, public IAttacker {

public:
    Player(float _x, float _y, float _life, float _maxLife, Vector2 _direction, float _speed);

    void TakeDamage(float _takedamage) override;
    void Deplacer() override;
    void Attack(Alive* target) override;
};

#endif
