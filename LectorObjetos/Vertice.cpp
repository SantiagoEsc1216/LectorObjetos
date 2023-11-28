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

Vertice Vertice::getVector(Vertice v) {
	return  Vertice(v.getX() - this->getX(), v.getY() - this->getY(), v.getZ() - this->getZ(), -1);
}
float Vertice::prodPoint(Vertice v) {
	return v.getX() * this->getX() + v.getY() * this->getY() + v.getZ() * this->getZ();
}
Vertice Vertice::prodCross(Vertice v) {
	float resultX = (y * v.z) - (z * v.y);
	float resultY = (z * v.x) - (x * v.z);
	float resultZ = (x * v.y) - (y * v.x);

	return Vertice(resultX, resultY, resultZ,0);
}
void Vertice::normalizar() {
	float magnitud = getMagnitud();
	x /= magnitud;
	y /= magnitud;
	z /= magnitud;
}
float Vertice::getMagnitud() {
	return std::sqrt(x * x + y * y + z * z);
}

void Vertice::escalar(float factor) {
	x *= factor;
	y *= factor;
	z *= factor;
}

void Vertice::sumar(Vertice v) {
	x += v.x;
	y += v.y;
	z += v.z;
}


