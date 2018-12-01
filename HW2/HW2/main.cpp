#include "DrawFunc.cpp"
#include "Input.cpp"
#include "Camera.h"
#include "Vertex.h"
#include "Robot.h"

GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);

void DefaultTimer(int);
void SpecialTimer(int);
void SnowTimer(int);
//-----------------------------
void SetupRC();

vector<MyVec> vTree;
Camera cCamera;
Vertex cVertex;
Robot cRobot;
vector<MyVec> vSnow;

bool bMouseFlag;
bool m_bSnow=true;

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH_HALF * 2, WINDOW_HEIGHT_HALF * 2);
	glutCreateWindow("HW2");

	SetupRC();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMotion);

	glutTimerFunc(100, DefaultTimer, 1);
	//glutTimerFunc(100, SpecialTimer, 2);
	//glutTimerFunc(200, SnowTimer, 3);

	glutReshapeFunc(Reshape);
	glutMainLoop();
}

GLvoid drawScene(GLvoid)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//	DrawFloor();
	DrawAxis();
//	cVertex.DrawVertices();
//	DrawTrees();
	cRobot.Draw();

	glFlush(); 
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	cCamera.Reset();
}

void SetupRC()
{
	int n = rand() % 10 + 10;  //0~9 + 10

	while (n > 0)
	{
		vTree.push_back(MyVec{
			(double)(rand() % 200 - 100),10,
			(double)(rand() % 200 - 100) });
		--n;
	}
}

void DefaultTimer(int value)
{
	cCamera.Reset();


	//-----------------클래스로 정리할 것---------------
	bool col=false;
	int idx = 0;
	if (m_bSnow)
	{
		for (int i = 0; i < vSnow.size(); ++i)
		{
			if (vSnow[i].y > 0)
			{
				vSnow[i].y -= 0.5;
			}
			else
			{
				if (col) idx = i;
			}
		}

		if (col)
		{
			vSnow.erase(vSnow.begin() + idx); 
		}
	}
	//----------------------------------
	glutPostRedisplay(); 
	glutTimerFunc(100, DefaultTimer, 1); 
}

void SpecialTimer(int value)
{
	cRobot.ParticleProcess();

	glutPostRedisplay();
	glutTimerFunc(100, SnowTimer, 2);
}

void SnowTimer(int value)
{
	double x = rand() % 40 - 20;
	double z = rand() % 40 - 20;
	vSnow.push_back(MyVec{ x,10.0,z });

	glutPostRedisplay(); 
	glutTimerFunc(200, SnowTimer, 3); 
}
