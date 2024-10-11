#include <sstream>
#include "Entity.h"

Entity::Entity(float _x, float _y) : Position(_x, _y) {


}

void Entity::SetPosition(float _x, float _y)
{
	Position.SetXY(_x, _y);
}

Vector2 Entity::GetPosition()
{
	return Position;
}

