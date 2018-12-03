#include "Camera.h"
#include <GL/freeglut.h>

void Camera::ToggleOrtho() 
{
	m_isPerspective = !m_isPerspective;

	if (m_isPerspective) m_Zoom = -250;
	else m_Zoom = 0;
}

void Camera::ToggleView(bool isStart)
{
	if (!isStart)
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
	}
	else
	{
		m_view = QUARTERVIEW; ToggleOrtho();
	}


	ViewChange();
}

void Camera::ViewChange()
{
	switch (m_view)
	{
	case TOPVIEW:
		m_Axis.x = 90; m_Axis.y = 0; m_Axis.z = 0;
		break;
	case SIDEVIEW:
		m_Axis.x = 0; m_Axis.y = 0; m_Axis.z = 0;
		break;
	case QUARTERVIEW:
		m_Axis.x = 45; m_Axis.y = 30; m_Axis.z = 0;
		break;
	}
}

void Camera::AxisModulate(double x, double y, double z)
{
	m_Axis.x += x;
	m_Axis.y += y;
	m_Axis.z += z;
}
//
//void Camera::PosModulate(double x, double y)
//{
//	m_Pos.x += x;
//	m_Pos.y += y;
//}

void Camera::ZoomModulate(double z)
{
	if (m_isPerspective)
		m_Zoom += z;
}

void Camera::Reset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (!m_isPerspective)
		glOrtho(-WINDOW_WIDTH_HALF, WINDOW_WIDTH_HALF,
			-WINDOW_HEIGHT_HALF, WINDOW_HEIGHT_HALF, -400.0, 400.0);
	else
	{
		gluPerspective(60, WINDOW_WIDTH_HALF / WINDOW_HEIGHT_HALF, 1.0, 1000.0);
	}
	glTranslated(0, 0, m_Zoom);

	glRotated(m_Axis.x, 1, 0, 0);
	glRotated(m_Axis.y, 0, 1, 0);
	glRotated(m_Axis.z, 0, 0, 1);
}
