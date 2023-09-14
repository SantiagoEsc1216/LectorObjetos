#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Vertice.h"
#include "Cara.h"
#include "Modelo.h"

using namespace std;

class Lector
{
private:
	string archivo;
public:
	vector <string> lineas;
	string linea;
	vector<Vertice> vertices;
	vector<Cara> caras;
	Modelo obj;

	Lector();

	void leerArchivo(string archivo);

	void imprimirObjeto();
		
};

