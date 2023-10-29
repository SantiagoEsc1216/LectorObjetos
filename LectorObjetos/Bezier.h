#pragma once
#include "Vertice.h"
class Bezier
{
public:
	Vertice puntos[4];
	float t, vel;
	Bezier(Vertice puntos[4], float t);
	Vertice getPoint();
	void incrementar();
	float get_t();
	void reset();
};

