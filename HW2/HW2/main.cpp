#include "DrawFunc.cpp"
#include "Input.cpp"
#include "Camera.h"
#include "Vertex.h"
#include "Robot.h"
#include "Weather.h"

GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);

void DefaultTimer(int);
void CollisionTimer(int);
//-----------------------------
void SetupRC();

vector<MyVec> vTree;
Camera cCamera;
Vertex cVertex;
Robot cRobot1(-10, 10, 0);
Robot cRobot2(0, 10,20);
Weather cWeather;

bool bMouseFlag;

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH_HALF * 2, WINDOW_HEIGHT_HALF * 2);
	glutCreateWindow("HW2");

	SetupRC();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeyboard);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMotion);

	glutTimerFunc(100, DefaultTimer, 1);
	glutTimerFunc(100, CollisionTimer, 2);

	glutReshapeFunc(Reshape);
	glutMainLoop();
}

GLvoid drawScene(GLvoid)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	DrawFloor();
	DrawAxis();
	DrawTrees();
	cVertex.DrawVertices();
	cVertex.DrawSpline();

	cRobot1.Draw();
	BLUE;
	cRobot1.DrawBeige();
	cRobot2.Draw();
	RED;
	cRobot2.DrawBeige();

	cWeather.Draw();

	glutSwapBuffers();
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
			(double)(rand() % 400 - 200), 10,
			(double)(rand() % 400 - 200) });
		--n;
	}
}

void DefaultTimer(int value)
{
	cCamera.Reset();	
	
	cRobot1.Move();
	cRobot1.ParticleProcess();
	cRobot2.Move();
	if (CheckColl(cRobot1.GetterPosX(), cRobot1.GetterPosZ(), cRobot2.GetterPosX(), cRobot2.GetterPosZ()))
		cRobot2.ChangeToDestDir(cRobot1.GetterDir());
	cWeather.Falling();


	//----------------------------------
	glutPostRedisplay(); 
	glutTimerFunc(100, DefaultTimer, 1); 
}

void CollisionTimer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(200, CollisionTimer, 2);
}

