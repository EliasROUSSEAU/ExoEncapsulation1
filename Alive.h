#ifndef ALIVE_H__
#define ALIVE_H__

#include <string>

class Alive {

protected:

	float MaxLife;
	float Life;

public:

	virtual float GetLife();
	virtual float GetMaxLife();
	virtual void TakeDamage(float _takedamage);

	Alive(float, float);

};

#endif