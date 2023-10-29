#include "Matriz.h"

Matriz::Matriz() {
	matriz.resize(4, vector<float>(4, 0.0));
	this->tipo = -1;
	this->eje = -1;
}

Matriz::Matriz(float x, float y, float z, int tipo) {

	vector<float> v{ x, y, z };
	matriz.resize(4, vector<float>(4, 0.0));
	this->tipo = tipo;
	this->eje = -1;
	switch (tipo)
	{
	case MATRIZ_ESCALACION:
		for (int i = 0; i < 3; i++) {
			matriz[i][i] = v[i];
		}
		matriz[3][3] = 1;
		break;
	case MATRIZ_TRASLACION:
		for (int i = 0; i < 3; i++) {
			matriz[i][i] = 1;
			matriz[i][3] = v[i];
		}
		matriz[3][3] = 1;
		break;
	default:
		break;
	}
}

void Matriz::setMatriz(float x, float y, float z, int tipo) {

	vector<float> v{ x, y, z };
	matriz.resize(4, vector<float>(4, 0.0));
	this->tipo = tipo;
	this->eje = -1;
	switch (tipo)
	{
	case MATRIZ_ESCALACION:
		for (int i = 0; i < 3; i++) {
			matriz[i][i] = v[i];
		}
		matriz[3][3] = 1;
		break;
	case MATRIZ_TRASLACION:
		for (int i = 0; i < 3; i++) {
			matriz[i][i] = 1;
			matriz[i][3] = v[i];
		}
		matriz[3][3] = 1;
		break;
	default:
		break;
	}
}

Matriz::Matriz(Vertice v) {
	matriz.resize(4, vector<float>(4, 0.0));
	matriz[0][3] = v.getX();
	matriz[1][3] = v.getY();
	matriz[2][3] = v.getZ();
	matriz[3][3] = 1;
	for (int i = 0; i < 3; i++) {
		matriz[i][i] = 1;
	}
	this->tipo = MATRIZ_TRASLACION;
	this->eje = -1;
}

Matriz::Matriz(float grados, int eje) {
	double pi = 3.14159265359;
	double radianes = grados * (pi / 180.0);
	grado = 0;
	this->tipo = MATRIZ_ROTACION;
	this->eje = -1;
	matriz.resize(4, vector<float>(4, 0.0));

	switch (eje)
	{
	case EJE_Y:
		this->eje = EJE_Y;
		matriz[0][0] = matriz[2][2] = cos(grado);
		matriz[1][1] = 1;
		matriz[0][2] = sin(grado);
		matriz[2][0] = -sin(grado);
		matriz[3][3] = 1;
		break;
	case EJE_X:
		this->eje = EJE_X;
		matriz[1][1] = matriz[2][2] = cos(grado);
		matriz[0][0] = 1;
		matriz[2][1] = sin(grado);
		matriz[1][2] = -sin(grado);
		matriz[3][3] = 1;
		break;
	default:
		break;
	}
}
Matriz::Matriz(vector<vector<float>> m) {
	matriz = m;
}

vector<vector<float>> Matriz::multiplicar(vector<vector<float>> matriz2) {
	vector<vector<float>> result(4, vector<float>(4, 0.0));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				result[i][j] += matriz[i][k] * matriz[k][j];
			}
		}
	}
	return result;
}

vector<float> Matriz::multiplicar(vector<float> v){
	vector<float> result(4, 0.0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result[i] += matriz[i][j] * v[j];
		}
	}
	return result;
}

void Matriz::incrementar() {
	
	switch (tipo)
	{
	case MATRIZ_TRASLACION:
		this->matriz[0][3] = this->matriz[0][3] + matriz[0][3] * 0.0001;
		this->matriz[1][3] = this->matriz[1][3] + matriz[1][3] * 0.0001;
		this->matriz[2][3] = this->matriz[2][3] + matriz[2][3] * 0.0001;
		break;
	case MATRIZ_ROTACION:
		grado = grado + 0.00002;
		if (grado >= 2 * 3.14159265359) {
			grado = 0;
		}
		switch (eje)
		{
		case EJE_Y:
			matriz[0][0] = matriz[2][2] = cos(grado);
			matriz[0][2] = sin(grado);
			matriz[2][0] = -sin(grado);
			break;
		case EJE_X:
			matriz[1][1] = matriz[2][2] = cos(grado);
			matriz[2][1] = sin(grado);
			matriz[1][2] = -sin(grado);
			break;
		default:
			break;
		}

	default: 
		break;
	}
}