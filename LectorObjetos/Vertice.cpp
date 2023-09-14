#include "Vertice.h"

Vertice::Vertice(float x, float y, float z) {
	this->x = x;
	this->z = z;
	this->y = y;
}

vector<float> Vertice::getVertices() {
	 vector<float> puntos{ x, y, z };
	 return puntos;
}


