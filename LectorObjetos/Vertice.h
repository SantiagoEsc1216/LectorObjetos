#pragma once
#include <vector>
using std::vector;
class Vertice
{
public:
	float x, y, z;

	Vertice(float x, float y, float z);

	vector<float> getVertices();
};

