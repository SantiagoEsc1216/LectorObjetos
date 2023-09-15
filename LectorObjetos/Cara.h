#pragma once
#include <vector>

using std::vector;

class Cara
{
public:
	int v1, v2, v3;
	Cara(int v1, int v2, int v3);
	Cara();
	
	void setVertices(vector<int> v);
	vector<int> getVertices();
};

