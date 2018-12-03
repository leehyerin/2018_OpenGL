#pragma once
#include "MyHeader.h"

class Camera
{
	//MyVec m_Pos;
	MyVec m_Axis{ 90,0,0 };
	bool m_isPerspective{ false };
	double m_Zoom{-10};
	View m_view{ TOPVIEW };
	bool m_isFreeView;
public:
	View GetView() {	return m_view;	}
	void ToggleOrtho();
	void ToggleView(bool isStart);
	void ToggleFreeView() { m_isFreeView=!m_isFreeView; }
	void ViewChange();
	void AxisModulate(double x, double y, double z);
	//void PosModulate(double x, double y);
	void ZoomModulate(double z);
	void Reset();
};