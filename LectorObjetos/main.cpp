#include "Lector.h"

int main() {

	Lector lector;
	vector<Modelo> modelos;

	modelos = lector.leerArchivo("prueba.obj");
	
	for (Modelo modelo : modelos) {
		modelo.imprimirModelo();
	}

	return 0;
}