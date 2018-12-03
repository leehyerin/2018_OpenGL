#include <GL/freeglut.h>
#include "MyHeader.h"

extern bool bMouseFlag;

#include "Vertex.h"
#include "Camera.h"
#include "Weather.h"
#include "Robot.h"
extern Vertex cVertex;
extern Camera cCamera;
extern Weather cWeather;
extern Robot cRobot1;
extern vector<MyVec> vTree;

inline void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':	cCamera.AxisModulate(-1, 0, 0);break;
	case 'X':	cCamera.AxisModulate(+1, 0, 0); break;

	case 'y':	cCamera.AxisModulate(0,-1, 0); break;
	case 'Y':	cCamera.AxisModulate(0,+1, 0); break;

	case 'V':	case 'v':
		cCamera.ToggleView(cVertex.GetterisStart());
		break;
	case 'P':case 'p':
		cCamera.ToggleOrtho();
		break;
	case 'Z':
		cCamera.ZoomModulate(5);
		break;
	case 'z':
		cCamera.ZoomModulate(-5);
		break;
//-------------------------------------
	case 'A':case'a':
		cRobot1.ChangeToDestDir(LEFT);
		break;
	case 'D':case 'd':
		cRobot1.ChangeToDestDir(RIGHT);
		break;
	case 'W':case 'w':
		cRobot1.ChangeToDestDir(UP);
		break;
	case 'S':case 's':
		cRobot1.ChangeToDestDir(DOWN);
		break;
//-------------------------------------

	case '0':
		cWeather.ToggleFalling();
		break;
	case '1':
		cWeather.ToggleWeather();
		break;
	case '8':
		cVertex.StartTrain();
		cCamera.ToggleView(cVertex.GetterisStart());
		break;
	case 'f': case 'F': case VK_SHIFT:
		cRobot1.ShotBullet();
		break;
	case VK_ESCAPE:
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}
inline void SpecialKeyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: //camera left
		//cCamera.PosModulate(-1, 0);
		break;
	case GLUT_KEY_RIGHT: //camera right
		break;
	case GLUT_KEY_UP: //camera up
		break;
	case GLUT_KEY_DOWN: //camera down
		break;
	}
}

inline void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		bool isTree = false;

		int X = (x - WINDOW_WIDTH_HALF);
		int Z = (y - WINDOW_HEIGHT_HALF); //z!

		if (CheckBoundary(-200, +200, X) 	&& CheckBoundary(-200, +200, Z))
		{
			for (auto d : vTree)		if (CheckColl(X, Z, d.x, d.z)) isTree = true;
			
			if (!isTree) cVertex.Pushback(X, rand() % 50, Z, cCamera.GetView());
		}
	}

	if (button == GLUT_RIGHT_BUTTON)		bMouseFlag = true;
	else bMouseFlag = false;
}

inline void MouseMotion(int x, int y)
{
	if (bMouseFlag)
	{
		int X = (x - WINDOW_WIDTH_HALF);
		int Y = (y - WINDOW_HEIGHT_HALF);

		cVertex.MouseMotion(X, Y, cCamera.GetView());
	}
}
