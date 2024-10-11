#ifndef VECTOR2_H__
#define VECTOR2_H__

#include <string>

class Vector2 {
    float x;
    float y;

public:

    //Setter
    void SetXY(float _x, float _y);

    //Getter
    float GetX();
    float GetY();


    Vector2(float, float);
};

#endif
