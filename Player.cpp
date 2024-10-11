#include "Player.h"
#include <iostream>

Player::Player(float _x, float _y, float _life, float _maxLife, Vector2 _direction, float _speed) : Entity(_x, _y), Alive(_life, _maxLife), AMovable(_direction, _speed)
{
    std::cout << "Player just created at x = " << GetPosition().GetX() << " and y = " << GetPosition().GetY() << " with " << _maxLife << " life with direction x = " << _direction.GetX() << " and y = " << _direction.GetY() << std::endl;
}

void Player::TakeDamage(float _takedamage)
{
    Alive::TakeDamage(_takedamage);
    if (GetLife() <= 0) {
        std::cout << "Player just died" << std::endl;
    }
}

void Player::Deplacer()
{
    std::cout << "Player moved to x = " << GetPosition().GetX() << " and y = " << GetPosition().GetY() << std::endl;
}

void Player::Attack(Alive* target)
{
    if (target) {
        target->TakeDamage(10); // Enlever 10 points de vie
        std::cout << "Player just attacked." << std::endl;
    }
}
