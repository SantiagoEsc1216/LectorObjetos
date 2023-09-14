#include "Modelo.h"

Modelo::Modelo() {
	this->objeto = ' ';
}

Modelo::Modelo(char obj) {
	this->objeto = obj;
}

char Modelo::getModelo() {
	return this->objeto;
}
