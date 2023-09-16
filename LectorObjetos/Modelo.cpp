#include "Modelo.h"

Modelo::Modelo() {
	this->objeto = ' ';
}

Modelo::Modelo(string obj) {
	this->objeto = obj;
}

void Modelo::setModelo(string obj) {
	this->objeto = obj;
}

string Modelo::getModelo() {
	return this->objeto;
}

void Modelo::imprimirModelo() {

	cout << "o: " << objeto << endl;


	for (Vertice v : vertices)
	{
		cout << fixed << "v: " << v.getX() << " " << v.getY() << " " << v.getZ() << endl;
	}

	for (Cara c : caras) {
		cout << "f: ";
		for (int v : c.getVertices()) {
			cout << v << " ";
		}
		cout << endl;
	}

}
