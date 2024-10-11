#include "Mob.h"

Mob::Mob(float _x, float _y, float _life, float _maxLife, Vector2 _direction, float _speed) : Entity(_x, _y), Alive(_life, _maxLife), AMovable(_direction, _speed)
{

    std::cout << "Mob just created at x = " << _x << " and y = " << _y << " with " << _maxLife << " life with direction x = " << _direction.GetX() << " and y = " << _direction.GetY() << std::endl;
}

void Mob::TakeDamage(float _takedamage) {

    Alive::TakeDamage(_takedamage);
    if (GetLife() <= 0) {
        std::cout << "Mob just die" << std::endl;
    }
}

void Mob::Deplacer() {
    std::cout << "Mob move to x = " << GetPosition().GetX() << " and y = " << GetPosition().GetY() << std::endl;
}
