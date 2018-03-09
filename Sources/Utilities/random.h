#pragma once

inline void RandomInit() 
{
	srand(time(NULL));
};

inline float Random(float min, float max) 
{ 
	return (rand() / float(RAND_MAX))*(max - min) + min; 
}

inline int Random(int min, int max) 
{ 
	return rand() % (max - min + 1) + min; 
}