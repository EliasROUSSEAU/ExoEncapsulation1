#include "Alive.h"

Alive::Alive(float _life, float _maxlife) : Life(_life), MaxLife(_maxlife)
{
}


float Alive::GetLife()
{
	return Life;
}

float Alive::GetMaxLife()
{
	return MaxLife;
}

void Alive::TakeDamage(float _takedamage)
{
	Life -= _takedamage;
}