#include <sstream>
#include "Vector2.h"

Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {

}

void Vector2::SetXY(float _x, float _y) {
	x = _x;
	y = _y;
}

float Vector2::GetX() {
	return x;

}

float Vector2::GetY() {
	return y;
}
