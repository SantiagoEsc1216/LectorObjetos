#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Vertice.h"
#include "Cara.h"
#include "Modelo.h"
#include <sstream>

using namespace std;

class Lector
{
private:
	string archivo;
public:
	string linea;
	vector<Vertice> vertices;
	vector<Cara> caras;
	Modelo modelo;
	int contadorId;

	Lector();

	void leerArchivo(string archivo);

	void imprimirObjeto();

	void guardarModelo(string linea);
	void guardarVertice(string linea);
	void guardarCara(string linea);
		
};

