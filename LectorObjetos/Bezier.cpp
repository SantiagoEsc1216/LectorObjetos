#include "Bezier.h"

Bezier::Bezier(Vertice puntos[4], float vel) {
	for (int i = 0; i < 4; i++) {
		this->puntos[i] = puntos[i];
	}
	this->vel = vel;
	t = 0;
	incX = incZ = incY = 0;
}
Vertice Bezier::getPoint() {
   float x = ((1 - t)* (1 - t)* (1 - t)* puntos[0].getX() +
		3 * (1 - t) * (1 - t) * t * puntos[1].getX() +
		3 * (1 - t) * t * t * puntos[2].getX() +
		t * t * t * puntos[3].getX());

   float y = ((1 - t) * (1 - t) * (1 - t) * puntos[0].getY() +
	   3 * (1 - t) * (1 - t) * t * puntos[1].getY() +
	   3 * (1 - t) * t * t * puntos[2].getY() +
	   t * t * t * puntos[3].getY());

   float z = ((1 - t) * (1 - t) * (1 - t) * puntos[0].getZ() +
	   3 * (1 - t) * (1 - t) * t * puntos[1].getZ() +
	   3 * (1 - t) * t * t * puntos[2].getZ() +
	   t * t * t * puntos[3].getZ());

   Vertice punto(x + incX, y + incY, z + incZ, -1);
   return punto;
}

void Bezier::incrementar() {
	this->t += vel;
}

float Bezier::get_t() {
	return t;
}

void Bezier::reset() {
	this->t = 0;
}

void Bezier::incrementarX(float i) {
	incX += i;
}
void Bezier::incrementarY(float i) {
	incY += i;
}
void Bezier::incrementarZ(float i) {
	incZ += i;
}