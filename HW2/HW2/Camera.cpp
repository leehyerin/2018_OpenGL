#include "Camera.h"
#include <GL/freeglut.h>

void Camera::ToggleView()
{
	switch (m_view) 
	{
	case TOPVIEW: 
		m_view = SIDEVIEW;
		break;
	case SIDEVIEW:
		m_view = QUARTERVIEW;
		break;
	case QUARTERVIEW:
		m_view = TOPVIEW;
		break;
	}

	ViewChange();
}

void Camera::ViewChange()
{
	switch (m_view)
	{
	case TOPVIEW:
		Axis.x = 90; Axis.y = 0; Axis.z = 0;
		break;
	case SIDEVIEW:
		Axis.x = 0; Axis.y = 0; Axis.z = 0;
		break;
	case QUARTERVIEW:
		Axis.x = 45; Axis.y = 30; Axis.z = 0;
		break;
	}
}

void Camera::AxisModulate(double x, double y, double z)
{
	Axis.x += x;
	Axis.y += y;
	Axis.z += z;
}

void Camera::Reset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (!m_isPerspective)
		glOrtho(-WINDOW_WIDTH_HALF, WINDOW_WIDTH_HALF,
			-WINDOW_HEIGHT_HALF, WINDOW_HEIGHT_HALF, -400.0, 400.0);
	else
		gluPerspective(60, 1, -1, 1000); //잘 안되는군..

	glRotated(Axis.x, 1, 0, 0);
	glRotated(Axis.y, 0, 1, 0);
	glRotated(Axis.z, 0, 0, 1);
}
