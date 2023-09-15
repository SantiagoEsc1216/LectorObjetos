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
