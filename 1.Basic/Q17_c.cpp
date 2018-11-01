#include <GL/freeglut.h>
#include "Myheader.h"
GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Keyboard(unsigned char, int, int);
void TimerFunction(int);
//-----------------------------
void DrawShape();
void SetupRC();
void MenuFunc(int);
void RotateAxis();
void RotateObject();
void CameraReset();

//

void DrawSun();
void DrawEarth();
void DrawJupiter();
void DrawNeptune();
void DrawMoon();
void DrawEuropa();
void DrawTriton();

//
bool isSolid;
bool isPerspective;
//
int EarthDegree, JupiterDegree, NeptuneDegree;
float EarthX, EarthZ;
float JupiterX, JupiterZ;
float NeptuneX, NeptuneZ;
float MoonX, MoonZ;
float EuropaX, EuropaZ;
float TritonX, TritonZ;
//
GLUquadricObj *qobj;
double DegreeForCameraAxisX, DegreeForCameraAxisY, DegreeForCameraAxisZ;
double TranslationForCameraX, TranslationForCameraY;
double x, y,  theta;
double zoom, DegreeForObject, depth;


void SetupRC()
{
	isPerspective = true;
	zoom = -30;
	DegreeForObject = 0;
	DegreeForCameraAxisX = 0, DegreeForCameraAxisY = 0, DegreeForCameraAxisZ = 0;
	TranslationForCameraX = 0, TranslationForCameraY = 0;
	x = 0;	y = 0;
	radius = 5;
	theta = 0;

	EarthDegree = 0, JupiterDegree = 0, NeptuneDegree = 0;
	EarthX = 10.0f, EarthZ = 0.0f;
	JupiterX = 10.0f, JupiterZ = 0.0f;
	NeptuneX = 10.0f, NeptuneZ = 0.0f;
	MoonX = 2.5f, MoonZ = 0.0f;
	EuropaX = 2.5f, EuropaZ = 0.0f;
	TritonX = 2.5f, TritonZ = 0.0f;
}
// 메뉴
void MenuFunc(int button)
{
	switch (button)
	{
	case 1:
		isSolid = true;
		break;

	case 2:
		isSolid = false;
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	//초기화 함수들 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);  // 더블 버퍼링과 3차원으로 그린다. 
	glutInitWindowPosition(0, 0); 	// 윈도우의 위치지정 
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// 윈도우의 크기 지정 
	glutCreateWindow("Q17"); 	// 윈도우 생성 (윈도우 이름) 
	SetupRC();
	// 필요한 콜백 함수 설정 

	glutCreateMenu(MenuFunc);
		glutAddMenuEntry("Solid", 1);
		glutAddMenuEntry("Wire", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(drawScene);	// 출력 함수의 지정 
	glutKeyboardFunc(Keyboard); //키입력 
	glutTimerFunc(100, TimerFunction, 1); // 타이머 함수 설정 
	glutReshapeFunc(Reshape);	// 다시 그리기 함수의 지정 

	glutMainLoop();
}


//윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0f, 0.5f, 0.35f);

	//-----------좌표계----------------
	glLoadIdentity();
	RotateAxis();
	glColor3f(0.f, 0.f, 1.f);
	glPushMatrix();
		glTranslated(0.0, 0.0, -1.5);
		glScaled(0.5, 0.5, 3);
		glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(1.f, 0.f, 0.f);
	glPushMatrix();
		glTranslated(1.5, 0.0, 0.0);
		glScaled(3, 0.5, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.f, 1.f, 0.f);
	glPushMatrix();
		glTranslated(0.0, 1.5, 0);
		glScaled(0.5, 3, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();

	glRotatef(10.0f, 1.0f, 0.0f, 0.0f);

	DrawSun();
	DrawEarth();
	DrawJupiter();
	DrawNeptune();



	glutSwapBuffers();
}

void DrawSun()
{
	glPushMatrix();
	glColor3f(1.f, 0.0f, 0.0f);
	if (isSolid)
		glutSolidSphere(3.0, 20.0, 20.0);
	else
		glutWireSphere(3.0, 20.0, 20.0);
	glPopMatrix();
}

void DrawEarth()
{
	glPushMatrix();
	glColor3f(0.0f, 1.f, 0.0f);

	// 행성 궤도
	glPushMatrix();
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x33ff); 
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(10.0f * cos(angle), 0.0f, 10.0f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// 행성
	glPushMatrix();
	glDisable(GL_LINE_STIPPLE);
	glTranslatef(EarthX, 0.0f, EarthZ);
	if (isSolid)
		glutSolidSphere(2.0, 20.0, 20.0);
	else
		glutWireSphere(2.0, 20.0, 20.0);
	DrawMoon();
	glPopMatrix();
	glPopMatrix();
}

void DrawJupiter()
{
	glPushMatrix();
	glColor3f(0.6f, 0.5f, 0.1f);
	glRotatef(45.0f, 1.0f, 0.0f, 1.0f);

	// 궤도
	glPushMatrix();
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x33ff); 
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(10.0f * cos(angle), 0.0f, 10.0f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// 행성
	glPushMatrix();
	glDisable(GL_LINE_STIPPLE);
	glTranslatef(JupiterX, 0.0f, JupiterZ);
	if (isSolid)
		glutSolidSphere(2.0, 20.0, 20.0);
	else
		glutWireSphere(2.0, 20.0, 20.0);
	DrawEuropa();
	glPopMatrix();
	glPopMatrix();
}

void DrawNeptune()
{
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.f);
	glRotatef(-45.0f, 1.0f, 0.0f, 1.0f);

	// 궤도
	glPushMatrix();
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x33ff); 
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(10.0f * cos(angle), 0.0f, 10.0f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// 행성
	glPushMatrix();
	glDisable(GL_LINE_STIPPLE);
	glTranslatef(NeptuneX, 0.0f, NeptuneZ);
	if (isSolid)
		glutSolidSphere(2.0, 20.0, 20.0);
	else
		glutWireSphere(2.0, 20.0, 20.0);
	DrawTriton();
	glPopMatrix();
	glPopMatrix();
}

void DrawMoon()
{
	glColor3f(0.5f, 0.5f, 0.5f);

	// 위성 궤도
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(2.5f * cos(angle), 0.0f, 2.5f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// 위성
	glPushMatrix();
	glTranslatef(MoonX, 0.0f, MoonZ);
	if (isSolid)
		glutSolidSphere(0.5, 20.0, 20.0);
	else
		glutWireSphere(0.5, 20.0, 20.0);
	glPopMatrix();
}

void DrawEuropa()
{
	glColor3f(0.0f, 0.5f, 0.3f);

	// 위성 궤도
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(2.5f * cos(angle), 0.0f, 2.5f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// 위성
	glPushMatrix();
	glTranslatef(EuropaX, 0.0f, EuropaZ);
	if (isSolid)		glutSolidSphere(0.5, 20.0, 20.0);
	else		glutWireSphere(0.5, 20.0, 20.0);
	glPopMatrix();
}

void DrawTriton()
{
	glColor3f(1.0f, 1.f, 0.5f);

	// 위성 궤도
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(2.5f * cos(angle), 0.0f, 2.5f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// 위성
	glPushMatrix();
	glTranslatef(TritonX, 0.0f, TritonZ);
	if (isSolid)
		glutSolidSphere(0.5, 20.0, 20.0);
	else
		glutWireSphere(0.5, 20.0, 20.0);
	glPopMatrix();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	CameraReset();
}

void RotateAxis()
{
	glRotated(DegreeForCameraAxisX, 1.0, 0.0, 0.0);
	glRotated(DegreeForCameraAxisY, 0.0, 1.0, 0.0);
	glRotated(DegreeForCameraAxisZ, 0.0, 0.0, 1.0);
}

void RotateObject()
{
	glRotated(DegreeForObject, 0.0, 1.0, 0.0);
}

void CircularRotate()
{
	theta += 1;	if (theta >= 360) theta = 0;

	x = radius * cos(theta*RADIAN);
	y = radius * sin(theta*RADIAN);
}

void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(isPerspective) gluPerspective(60, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);
	else glOrtho(-WINDOW_WIDTH/2, +WINDOW_WIDTH/2,-WINDOW_HEIGHT/2, +WINDOW_HEIGHT/2, 1.0, 1000.0);
	
	glTranslated(TranslationForCameraX, TranslationForCameraY, zoom);
	glRotated(DegreeForCameraAxisX, DegreeForCameraAxisY, DegreeForCameraAxisZ, 0.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':	--DegreeForCameraAxisX; 		break;
	case 'X':	++DegreeForCameraAxisX; 	break;

	case 'y':	--DegreeForCameraAxisY;		break;
	case 'Y':	++DegreeForCameraAxisY;		break;

	case 'z':	--DegreeForCameraAxisZ;		break;
	case 'Z':	++DegreeForCameraAxisZ;		break;


	case 'a':case 'A':	--TranslationForCameraX; 			CameraReset();		break;
	case 'd':case 'D':	++TranslationForCameraX; 			CameraReset();		break;

	case 's': case 'S':	--TranslationForCameraY;				CameraReset();		break;
	case 'w':case 'W':  ++TranslationForCameraY;			CameraReset();		break;


	case '+':
		++zoom;
		CameraReset();
		break;
	case '-':
		--zoom;
		CameraReset();
		break;
	case 'i': case'I':
		SetupRC();
		break;
	case'p':case'P': 
		isPerspective = !isPerspective;		
		CameraReset();		
		break;
	case VK_ESCAPE: 	case 'Q':	case 'q':
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}

void TimerFunction(int value)
{
	++DegreeForObject;
	EarthX = 10.0f * cos(EarthDegree * RADIAN);
	EarthZ = 10.0f * sin(EarthDegree * RADIAN);
	JupiterX = 10.0f * cos(JupiterDegree * RADIAN);
	JupiterZ = 10.0f * sin(JupiterDegree * RADIAN);
	NeptuneX = 10.0f * cos(NeptuneDegree * RADIAN);
	NeptuneZ = 10.0f * sin(NeptuneDegree * RADIAN);

	MoonX = 2.5f * cos(EarthDegree * 10 * RADIAN);
	MoonZ = 2.5f * sin(EarthDegree * 10 * RADIAN);
	EuropaX = 2.5f * cos(JupiterDegree * 10 * RADIAN);
	EuropaZ = 2.5f * sin(JupiterDegree * 10 * RADIAN);
	TritonX = 2.5f * cos(NeptuneDegree * 10 * RADIAN);
	TritonZ = 2.5f * sin(NeptuneDegree * 10 * RADIAN);

	EarthDegree += 5;
	JupiterDegree += 3;
	NeptuneDegree += 1;


	CircularRotate();

	glutPostRedisplay(); // 화면 재 출력
	glutTimerFunc(100, TimerFunction, 1); // 타이머함수 재 설정
}

void DrawShape()
{
	if(!isSolid)	gluQuadricDrawStyle(qobj, GLU_LINE);
	else		gluQuadricDrawStyle(qobj, GLU_FILL);
	
	gluSphere(qobj, 1.5, 30, 10);
}
