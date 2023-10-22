#pragma once
#include <vector>
#include <cmath>

using std::vector;
class Matriz
{
public:
	static const int MATRIZ_TRASLACION = 0;
	static const int MATRIZ_ESCALACION = 1;
	static const int MATRIZ_ROTACION = 2;
	static const int EJE_X = 3;
	static const int EJE_Y = 4;
	static const int EJE_Z = 5;
	vector<vector<float>> matriz;
	int tipo;

	Matriz();
	Matriz(float x, float y, float z, int tipo);
	Matriz(float grados, int eje);
	Matriz(vector<vector<float>> m);
	vector<vector<float>> multiplicar(vector<vector<float>> matriz2);
	vector<float> multiplicar(vector<float> v);
};

