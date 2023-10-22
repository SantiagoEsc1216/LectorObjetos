#pragma once
#include <vector>
using std::vector;
class Vertice
{
public:
	int id;
	float x, y, z, w;

	Vertice(float x, float y, float z, int id);
	Vertice();

	void setPuntos(vector<float> p);
	void setId(int id);

	int getId();
	float getX();
	float getY();
	float getZ();
	vector<float> getVertices();
};

