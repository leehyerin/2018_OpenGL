#pragma once
#include "MyHeader.h"

class Camera
{
public:
	View m_view{ TOPVIEW };
	MyVec Axis{ 90,0,0 };
	bool m_isPerspective{ false };

	inline void ToggleOrtho() { m_isPerspective = !m_isPerspective; }
	void ToggleView();
	void ViewChange();
	void AxisModulate(double x, double y, double z);
	void Reset();
};