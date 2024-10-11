#include "BreakableObject.h"
#include <iostream>

BreakableObject::BreakableObject(float _x, float _y, float _life, float _maxLife) : Entity(_x, _y), Alive(_life, _maxLife)
{
    std::cout << "Breakable Object just created at x = " << _x << " and y = " << _y << " with " << _maxLife << " life" << std::endl;
}

void BreakableObject::SetXY(float _x, float _y) {
    SetPosition(_x, _y);
}

void BreakableObject::SetLifeMaxLife(float _maxlife, float life)
{
}

void BreakableObject::TakeDamage(float _takedamage) {
    Alive::TakeDamage(_takedamage);
    if (Life <= 0) {
        std::cout << "Breakable Object just broke" << std::endl;
    }
}