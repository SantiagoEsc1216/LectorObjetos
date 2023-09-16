#include "Lector.h"

int main() {

	Lector lector;
	Modelo modelo;

	modelo = lector.leerArchivo("objeto.obj");
	modelo.imprimirModelo();

	return 0;
}