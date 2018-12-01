#pragma once
#include "MyHeader.h"
#include <vector>
using namespace std;

class Vertex
{
	vector<MyVec> m_vVertex;
public:
	Vertex();
	~Vertex();
	void Pushback(double x, double y, double z, View view);
	void MouseMotion(double x, double z, View);
	void DrawVertices();
};

