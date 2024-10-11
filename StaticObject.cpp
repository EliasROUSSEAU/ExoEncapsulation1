#include "StaticObject.h"
#include "iostream"

StaticObject::StaticObject(float _x, float _y) : Entity(_x,_y)
{
	std::cout << "Static Object just created at x = " << _x << " and y = " << _y << std::endl;
}

void StaticObject::SetXY(float _x, float _y)
{
}
