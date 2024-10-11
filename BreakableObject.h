#ifndef BREAKABLEOBJECT_H__
#define BREAKABLEOBJECT_H__

#include <iostream>
#include "Vector2.h"
#include "Entity.h"
#include "Alive.h"

class BreakableObject: public Entity, public Alive {
protected:

public:
	BreakableObject(float _x, float _y, float _life, float _maxLife);
	void SetXY(float _x,float _y);
	void SetLifeMaxLife(float _maxlife, float life);
	void TakeDamage(float _takedamage) override;
};

#endif