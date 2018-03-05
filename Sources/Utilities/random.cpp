#include "random.h"

void Random::RandomInit()
{
	srand(time(NULL));
}

float Random::RandomF(float min, float max) 
{ 
	return (rand() / float(RAND_MAX))*(max - min) + min; 
}

int Random::RandomI(int min, int max) 
{ 
	return rand() % (max - min + 1) + min; 
}