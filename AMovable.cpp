#include "AMovable.h"

AMovable::AMovable(Vector2 _direction, float _speed) : Speed(_speed), Direction(_direction)
{
}

void AMovable::SetSpeed(float _speed)
{
	Speed = _speed;
}

void AMovable::SetDirection(Vector2 _direction)
{
	Direction = _direction;
}
