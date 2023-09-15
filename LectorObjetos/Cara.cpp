#include "Cara.h"

Cara::Cara(int v1, int v2, int v3) {
	this->v1 = v1;
	this->v2 = v2;
	this->v3 = v3;
}

Cara::Cara() {
	this->v1 = 0;
	this->v2 = 0;
	this->v3 = 0;
}

void Cara::setVertices(vector<int> v) {
	this->v1 = v[0];
	this->v2 = v[1];
	this->v3 = v[2];
}


vector<int> Cara::getVertices() {
	vector<int> vertices{ v1, v2 ,v3 };
	return vertices;
}
