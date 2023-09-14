#include "Cara.h"

Cara::Cara(int v1, int v2, int v3) {
	this->v1 = v1;
	this->v2 = v2;
	this->v3 = v3;
}

vector<int> Cara::getVertices() {
	vector<int> vertices{ v1, v2 ,v3 };
	return vertices;
}
