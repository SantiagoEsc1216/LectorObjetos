#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Modelo.h"
#include <sstream>

using namespace std;

class Lector
{
private:
	string archivo;
public:
	string linea;
	vector<Modelo> modelos;
	int contadorId;
	int indexModelo;

	Lector();

	Modelo leerArchivo(string archivo);

	void guardarModelo(string linea);
	void guardarVertice(string linea);
	void guardarCara(string linea);
		
};

