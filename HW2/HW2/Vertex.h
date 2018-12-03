#pragma once
#include "MyHeader.h"
#include <vector>
using namespace std;

class Vertex
{
	vector<MyVec> m_vVertex;

	vector<pair<Point2D, MyVec>> m_vSlop;
	Train m_Train;
	bool m_isTrainStart;
	int m_CollCnt;
	bool m_isFirst;

public:
	Vertex();
	~Vertex();
	void Pushback(double x, double y, double z, View view);
	void MouseMotion(double x, double z, View);
	void DrawVertices();
	void DrawSpline();

	void SetTrainInitState();
	void StartTrain() { m_isTrainStart = true; SetTrainInitState(); }
	bool GetterisStart() {	return m_isTrainStart	;}
	void MoveTrain();

	bool CheckCollisionRobotbyVertex(double, double);
};

