#pragma once
#include <iostream>
#include <string>
#include "Vertice.h"
#include "Cara.h"


using namespace std;

class Modelo
{
public:
	string objeto;
	vector<Vertice> vertices;
	vector<Cara> caras;

	Modelo();
	Modelo(string ob);

	void setModelo(string obj);
	string getModelo();

	void imprimirModelo();
};

