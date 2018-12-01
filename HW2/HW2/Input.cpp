#include <GL/freeglut.h>
#include "MyHeader.h"
extern bool bMouseFlag;
extern bool m_bSnow;
#include "Camera.h"
extern Camera cCamera;
#include "Vertex.h"
extern Vertex cVertex;

inline void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':	cCamera.AxisModulate(-1, 0, 0);break;
	case 'X':	cCamera.AxisModulate(+1, 0, 0); break;

	case 'y':	cCamera.AxisModulate(0,-1, 0); break;
	case 'Y':	cCamera.AxisModulate(0,+1, 0); break;

	case 'z':	cCamera.AxisModulate(0, 0, -1);break;
	case 'Z':	cCamera.AxisModulate(0, 0, +1);break;

	case 'V':	case 'v':
		cCamera.ToggleView();
		break;
	case 'P':case 'p':
		cCamera.ToggleOrtho();
		break;
	case 'H':case 'h':

		break;

	case '1':
		m_bSnow = !m_bSnow;
		break;

	case VK_ESCAPE:
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}

inline void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		auto X = (double)(x - WINDOW_WIDTH_HALF);
		auto Z = (double)(y - WINDOW_HEIGHT_HALF); //z축이라서 반대

		cVertex.Pushback(X, rand() % 100, Z, cCamera.m_view);
	}

	if (button == GLUT_RIGHT_BUTTON)		bMouseFlag = true;
	else bMouseFlag = false;
}

inline void MouseMotion(int x, int y)
{
	if (bMouseFlag)
	{
		auto X = (double)(x - WINDOW_WIDTH_HALF);
		auto Y = (double)(y - WINDOW_HEIGHT_HALF);

		cVertex.MouseMotion(X, Y, cCamera.m_view);
	}
}
