#ifndef STATICOBJECT_H__
#define STATICOBJECT_H__

#include <iostream>
#include "Entity.h"

class StaticObject:public Entity {

public:

	StaticObject(float _x, float _y);
	virtual void SetXY(float _x, float _y);

};

#endif