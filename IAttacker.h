#ifndef IATTACKER_H__
#define IATTACKER_H__

#include <string>

class Alive;
class IAttacker {

protected:

public:

	virtual void Attack(Alive* target) = 0;

};

#endif