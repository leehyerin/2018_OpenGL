#include <GL/freeglut.h>
#include <vector>
#include "Myheader.h"
#include "WinFunction.h"
using namespace std;

GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Keyboard(unsigned char, int, int);
void TimerFunction(int);

//-----------------------------
void SetupRC();
void CameraReset();

void MoveBall_Front();
void MoveBall_Top();

void DrawSpring();

GLUquadricObj *qobj;
double DegreeForAxisY, zoomZ;
double FrontFaceDegree, TopFaceDegree;
double BallDegree, BallX, BallY, BallZ;
int dir;
vector<MyVec> SpringPoints;
int PtrIdx;

void SetupRC()
{
	zoomZ = -70;
	FrontFaceDegree = TopFaceDegree = 0;
	dir = 1;
	DegreeForAxisY = 45;
	BallDegree = BallX = BallZ = 0;
	BallY = -1;
	//spring
	int theta = 0; int rad = 5; int y = 5;

	for (int i = 0; i < 500; ++i)
	{
		SpringPoints.push_back(MyVec{ rad*cos(ConvertToRadian(theta)),y+(double)theta*0.02, rad*sin(ConvertToRadian(theta))}); 
		theta +=2;
	}
	PtrIdx = 0;
}

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);  
	glutInitWindowPosition(0, 0); 	
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	
	glutCreateWindow("Q25"); 	
	SetupRC();
	glutDisplayFunc(drawScene); 
	glutKeyboardFunc(Keyboard);  
	glutTimerFunc(100, TimerFunction, 1);
	MenuProcess();
			
	glutReshapeFunc(Reshape);	
	glutMainLoop();
}

GLvoid drawScene(GLvoid)
{
	glClearColor(0.5f, 0.5f, 1.f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	if (bFlat) glShadeModel(GL_FLAT);
	else glShadeModel(GL_SMOOTH);

	glFrontFace(GL_CCW);

	//GLint p0[3] = { 10.f, 10.f, 10.0 };
	//GLint p1[3] = { -10.f, 10.f, 10.0 };
	//GLint p2[3] = { -10.f, -10.f, 10.0 };
	//GLint p3[3] = { 10.f, -10.f, 10.0 };

	//GLint p4[3] = { 10.f, 10.f, -10.0 };
	//GLint p5[3] = { -10.f, 10.f, -10.0 };
	//GLint p6[3] = { -10.f, -10.f, -10.0 };
	//GLint p7[3] = { 10.f, -10.f, -10.0 };

	//---------------------------------------
	//Front Face
	glLoadIdentity();
	if (bFrontFaceOpen){
		glTranslated(0, -10, 10);
		glRotated(FrontFaceDegree, 1, 0, 0);
		glTranslated(0, 10, -10);
	}
	glBegin(GL_QUADS);
	Vertex0;
	Vertex1;
	Vertex2;
	Vertex3;
	glEnd();
	glLoadIdentity();
	//Top Face
	if (bTopFaceOpen) {
		glTranslated(0, 10, -10);
		glRotated(TopFaceDegree, 1, 0, 0);
		glTranslated(0, -10, 10);
	}
	glBegin(GL_QUADS);
	Vertex4;
	Vertex5;
	Vertex1;
	Vertex0;
	glEnd();
	//---------------------------------------
	glLoadIdentity();
	glBegin(GL_QUADS);
	//Left Face
	Vertex1;
	Vertex5;
	Vertex6;
	Vertex2;
	//Right Face
	Vertex4;
	Vertex0;
	Vertex3;
	Vertex7;
	//Bottom Face
	Vertex3;
	Vertex2;
	Vertex6;
	Vertex7;
	//Back Face
	Vertex7;
	Vertex6;
	Vertex5;
	Vertex4;
	glEnd ();


	//----------------------------
	//Ball
	glLoadIdentity();
	glColor3f(0.5, 0.5, 0.5);	
	glTranslated(BallX, BallY, BallZ); 
	glRotated(BallDegree*4, 1, 0, 0);
	glutSolidSphere(5, 10, 10);	WHITE; glutWireSphere(5, 10, 10);

	if(bTopFaceOpen)	DrawSpring();

	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	CameraReset();
}

void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);

	glTranslated(0.0, 0.0, zoomZ);
	glRotated(30, 1, 0, 0);
	glRotated(DegreeForAxisY, 0, 1, 0);
}

void MoveBall_Front()
{
	BallDegree += 0.5;
	if (BallDegree < 40)
		BallZ += 2 * PI * BallDegree / 360;
}

void MoveBall_Top()
{
	BallX = SpringPoints[PtrIdx].x;
	BallY = SpringPoints[PtrIdx].y;
	BallZ = SpringPoints[PtrIdx].z;
	if (PtrIdx < 495) PtrIdx += 5;
}	
	
void DrawSpring()
{
	glLoadIdentity();

	glBegin(GL_LINE_STRIP);
	BLACK;
	
	for (auto d : SpringPoints)
		glVertex3d(d.x, d.y, d.z);

	glEnd();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'y':	--DegreeForAxisY;		CameraReset(); break;
	case 'Y':	++DegreeForAxisY;		CameraReset(); break;

	case '-':	--zoomZ;		CameraReset(); break;
	case '+':	++zoomZ;		CameraReset(); break;

	case VK_ESCAPE: 	case 'Q':	case 'q':
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}

void TimerFunction(int value)
{
	--DegreeForAxisY;

	if (bFrontFaceOpen) 
	{
		if (FrontFaceDegree < 90) FrontFaceDegree += 2; 
		MoveBall_Front();
	}
	if (bTopFaceOpen) 
	{
		if (TopFaceDegree > -180) TopFaceDegree -= 2; 
		MoveBall_Top();
	}
	//---------------------------------------------
	CameraReset();
	glutPostRedisplay(); 
	glutTimerFunc(100, TimerFunction, 1); 
}


