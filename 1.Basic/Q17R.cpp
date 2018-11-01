#include <GL/freeglut.h>
#include <iostream>
using namespace std;

#define RADIAN 0.0174532
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

void SetupRC();
GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void MenuFunc(int);
void Keyboard(unsigned char, int, int);
void TimerFunction(int);

void DrawSun();
void DrawEarth();
void DrawJupiter();
void DrawNeptune();
void DrawMoon();
void DrawEuropa();
void DrawTriton();

//
bool isSolid;

int EarthDegree, JupiterDegree, NeptuneDegree;
float EarthX, EarthZ;
float JupiterX, JupiterZ;
float NeptuneX, NeptuneZ;
float MoonX, MoonZ;
float EuropaX, EuropaZ;
float TritonX, TritonZ;

bool isPerspective;
double zoom, DegreeForCamera;

void main(int argc, char *argv[])
{
	int SolidMenu, WireMenu;

	//�ʱ�ȭ �Լ���
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // ���÷��� ��� ����
	glutInitWindowPosition(100, 100); // �������� ��ġ����
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); // �������� ũ�� ����
	glutCreateWindow("Q17"); // ������ ���� (������ �̸�)
	SetupRC(); // ���� ���� �ʱ�ȭ �Լ�

	glutCreateMenu(MenuFunc);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(drawScene); // ��� �Լ��� ����
	glutReshapeFunc(Reshape); // �ٽ� �׸��� �Լ��� ����
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(100, TimerFunction, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glutMainLoop();
}

// �ʱ�ȭ �Լ�
void SetupRC()
{
	isSolid = true;

	EarthDegree = 0, JupiterDegree = 0, NeptuneDegree = 0;
	EarthX = 10.0f, EarthZ = 0.0f;
	JupiterX = 10.0f, JupiterZ = 0.0f;
	NeptuneX = 10.0f, NeptuneZ = 0.0f;
	MoonX = 2.5f, MoonZ = 0.0f;
	EuropaX = 2.5f, EuropaZ = 0.0f;
	TritonX = 2.5f, TritonZ = 0.0f;

	isPerspective = true;
	zoom = -30;
}

// �޴�
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

// ������ ��� �Լ�
GLvoid drawScene(GLvoid)
{
	printf("%d\n", isPerspective);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(10.0f, 1.0f, 0.0f, 0.0f);

	DrawSun();
	DrawEarth();
	DrawJupiter();
	DrawNeptune();

	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (!isPerspective)
	{
		glOrtho(-WINDOW_WIDTH / 2, WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2, -1.0, 1.0);
		glTranslatef(0.0, 0.0, zoom/2);
	}
	else
	{
		gluPerspective(60.0f, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);
		glTranslatef(0.0, 0.0, zoom);
	}

}

void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (!isPerspective)
		glOrtho(-WINDOW_WIDTH / 2, WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2, -1.0, 1.0);

	else
		gluPerspective(60.0f, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);

	glTranslated(0.0, 0.0, zoom);

	glRotated(DegreeForCamera, 0.0, 1.0, 0.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'p': case 'P':
			isPerspective = !isPerspective;
		break;

	case 'q': case 'Q': case VK_ESCAPE:
		exit(0);
		break;
	//ī�޶� z�࿡ ���� ���� / �ܾƿ� �Ѵ�
	case 'i': case 'I':
		zoom += 3;
		CameraReset();
		break;
	case 'o': case 'O':
		zoom -= 3;
		CameraReset();
	default:
		break;
	}

	glutPostRedisplay();
}

void TimerFunction(int value)
{
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

	glutPostRedisplay();
	glutTimerFunc(100, TimerFunction, 1);
}

void DrawSun()
{
	glPushMatrix();
	glColor3f(0.85f, 0.0f, 0.0f);
	if (isSolid)
		glutSolidSphere(3.0, 20.0, 20.0);
	else
		glutWireSphere(3.0, 20.0, 20.0);
	glPopMatrix();
}

void DrawEarth()
{
	glPushMatrix();
	glColor3f(0.0f, 0.85f, 0.0f);

	// �༺ �˵�
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(10.0f * cos(angle), 0.0f, 10.0f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// �༺
	glPushMatrix();
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

	// �˵�
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(10.0f * cos(angle), 0.0f, 10.0f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// �༺
	glPushMatrix();
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
	glColor3f(0.0f, 0.0f, 0.85f);
	glRotatef(-45.0f, 1.0f, 0.0f, 1.0f);

	// �˵�
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(10.0f * cos(angle), 0.0f, 10.0f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// �༺
	glPushMatrix();
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

	// ���� �˵�
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(2.5f * cos(angle), 0.0f, 2.5f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// ����
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
	glColor3f(0.0f, 0.5f, 0.35f);

	// ���� �˵�
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(2.5f * cos(angle), 0.0f, 2.5f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// ����
	glPushMatrix();
	glTranslatef(EuropaX, 0.0f, EuropaZ);
	if (isSolid)
		glutSolidSphere(0.5, 20.0, 20.0);
	else
		glutWireSphere(0.5, 20.0, 20.0);
	glPopMatrix();
}

void DrawTriton()
{
	glColor3f(1.0f, 1.5f, 0.5f);

	// ���� �˵�
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * RADIAN;
		glVertex3f(2.5f * cos(angle), 0.0f, 2.5f * sin(angle));
	}
	glEnd();
	glPopMatrix();

	// ����
	glPushMatrix();
	glTranslatef(TritonX, 0.0f, TritonZ);
	if (isSolid)
		glutSolidSphere(0.5, 20.0, 20.0);
	else
		glutWireSphere(0.5, 20.0, 20.0);
	glPopMatrix();
}