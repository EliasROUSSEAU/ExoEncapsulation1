#ifndef AMOVABLE_H__
#define AMOVABLE_H__

#include <string>
#include "Vector2.h"

class AMovable {

protected:
	Vector2 Direction;
	float Speed;

public:

	virtual void SetSpeed(float _speed);
	virtual void SetDirection(Vector2 _direction);
	virtual void Deplacer() = 0;

	AMovable(Vector2, float);

};

#endif