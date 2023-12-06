#pragma once
#include "Vertice.h"
class Bezier
{
public:
	float incX, incY, incZ;
	Vertice puntos[4];
	float t, vel;
	Bezier(Vertice puntos[4], float t);
	Vertice getPoint();
	void incrementar();
	float get_t();
	void reset();
	void incrementarX(float i);
	void incrementarY(float i);
	void incrementarZ(float i);
};

