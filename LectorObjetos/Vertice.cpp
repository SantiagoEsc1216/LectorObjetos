#include "Vertice.h"

Vertice::Vertice(float x, float y, float z, int id) {
	this->x = x;
	this->z = z;
	this->y = y;
	this->w = 1.0;
	this->id = id;
}


Vertice::Vertice() {
	this->x = 0;
	this->z = 0;
	this->y = 0;
	this->w = 1.0;
	this->id = 0;
}


void Vertice::setPuntos(vector<float> p) {
	this->x = p[0];
	this->y = p[1];
	this->z = p[2];
}

void Vertice::setId(int id) {
	this->id = id;
}

int Vertice::getId() {
	return id;
}

float Vertice::getX() {
	return x;
}
float Vertice::getY() {
	return y;
}
float Vertice::getZ() {
	return z;
}

vector<float> Vertice::getVertices() {
	 vector<float> puntos{ x, y, z , w};
	 return puntos;
}


