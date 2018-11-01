#include <GL/freeglut.h>
#include "Myheader.h"
GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Keyboard(unsigned char, int, int);
void TimerFunction(int);
//-----------------------------
void DrawShape();
void SetupRC();
void DrawAxis();
void DrawFloor();
void RotateObject();
void CameraReset();

//
//
GLUquadricObj *qobj;
double DegreeForCameraAxisX, DegreeForCameraAxisY, DegreeForCameraAxisZ;
double TranslationForCameraX, TranslationForCameraY;
double x, y, z;
double thetaX, thetaY, thetaZ;
double zoom, DegreeForObject, depth;
extern int delta = 4;
int isSign = 1;
bool MoveX, MoveY, MoveZ;
#define PlusDelta(x)  x + isSign * 2 * PI * radius / (360 / delta)

void SetupRC()
{
	zoom = -30;
	DegreeForObject = 0;
	DegreeForCameraAxisX = 30, DegreeForCameraAxisY = 0, DegreeForCameraAxisZ = 0;
	TranslationForCameraX = 0, TranslationForCameraY = 0;
	x = 0;	y = 0; z = 0;
	radius = 5;
	MoveX = false; MoveY = false;	MoveZ = false;

	CameraReset();
}

int main(int argc, char *argv[])
{
	//�ʱ�ȭ �Լ��� 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);  // ���� ���۸��� 3�������� �׸���. 
	glutInitWindowPosition(0, 0); 	// �������� ��ġ���� 
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// �������� ũ�� ���� 
	glutCreateWindow("Q19"); 	// ������ ���� (������ �̸�) 
	SetupRC();
	
	//---------------�ݹ� �Լ�--------------------
	glutDisplayFunc(drawScene);	// ��� �Լ��� ���� 
	glutKeyboardFunc(Keyboard); //Ű�Է� 
	glutTimerFunc(100, TimerFunction, 1); // Ÿ�̸� �Լ� ���� 
	glutReshapeFunc(Reshape);	// �ٽ� �׸��� �Լ��� ���� 

	glutMainLoop();
}


//������ ��� �Լ�
GLvoid drawScene(GLvoid)
{
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	DrawAxis();	  //��ǥ��
	DrawFloor(); //�ٴ�
	DrawShape();//��

	glutSwapBuffers();
}


void DrawAxis()
{
	//-----------��ǥ��----------------
	glLoadIdentity();
	glColor3f(0.f, 0.f, 1.f);

		glPushMatrix();
			glTranslated(0.0, 0.0, -1.5);
			glScaled(0.25, 0.25, 3);
			glutSolidCube(1.0);
		glPopMatrix();

		glColor3f(1.f, 0.f, 0.f);
		glPushMatrix();
			glTranslated(1.5, 0.0, 0.0);
			glScaled(3, 0.25, 0.25);
			glutSolidCube(1.0);
		glPopMatrix();

		glColor3f(0.f, 1.f, 0.f);
		glPushMatrix();
			glTranslated(0.0, 1.5, 0);
			glScaled(0.25, 3, 0.25);
			glutSolidCube(1.0);
		glPopMatrix();

}

void DrawFloor()
{
	//-----------�ٴ� -------------
	glLoadIdentity();
	glPushMatrix();
		glColor3f(0.6, 0.4, 0.4);
		glTranslated(0.0, -10.0, 0.0);
		glScaled(1.2, 0.05, 1.2);
		glutSolidCube(30.0);
	glPopMatrix();
}


void DrawShape()
{
	glLoadIdentity();

	glPushMatrix();
		glColor3f(0.56, 0.78, 0.23);

		if (MoveX) 
		{
			x = PlusDelta(x);
			MoveX = false;
		}
		else if (MoveZ)
		{
			z = PlusDelta(z);
			MoveZ = false;
		}
		else if (MoveY)
		{
			MoveY = false;
		}

		glTranslated(x, -10.0, z);

		glRotated(thetaX, 0, 0, 1);
		glRotated(thetaY, 0, 1, 0);
		glRotated(thetaZ, 1, 0, 0);
		
		cout << "X" << thetaX << "Y" << thetaY << "Z" << thetaZ << endl;
		
		glutWireSphere(1.5, 20.0, 20.0);
	glPopMatrix();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	CameraReset();
}

void RotateObject()
{
	glRotated(DegreeForObject, 1.0, 0.0, 0.0);
	glRotated(DegreeForObject, 0.0, 1.0, 0.0);
}


void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);

	glTranslated(TranslationForCameraX, TranslationForCameraY, zoom);
	glRotated(DegreeForCameraAxisX, DegreeForCameraAxisY, DegreeForCameraAxisZ, 0.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':	--DegreeForCameraAxisX; 		CameraReset(); break;
	case 'X':	++DegreeForCameraAxisX; 	CameraReset(); break;

	case 'y':	--DegreeForCameraAxisY;		CameraReset(); break;
	case 'Y':	++DegreeForCameraAxisY;		CameraReset(); break;

	case 'z':	--DegreeForCameraAxisZ;		CameraReset(); break;
	case 'Z':	++DegreeForCameraAxisZ;		CameraReset(); break;

	case 'a':case 'A':	--TranslationForCameraX; 		CameraReset(); break;
	case 'd':case 'D':	++TranslationForCameraX; 		CameraReset(); break;
																					
	case 's': case 'S':	--TranslationForCameraY;			CameraReset(); break;
	case 'w':case 'W':  ++TranslationForCameraY;		CameraReset(); break;

	case 'l': 
		isSign = 1; thetaX -= delta;  
		if (thetaX >= -650) MoveX = true;
		break;
	case 'L':
		isSign = -1;thetaX += delta;
		if (thetaX <= 650)	MoveX = true;
		break;

	case 'n': isSign = 1;  thetaZ -= delta;
		if (thetaZ >= -500) MoveZ = true;
		break;
	case 'N': isSign = -1; thetaZ += delta;
		if (thetaZ <= 500) MoveZ = true;
		break;

	case 'm': isSign = 1; MoveY = true;		thetaY -= delta;
		break;
	case 'M': isSign = -1; MoveY = true;	thetaY += delta;
		break;

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
	case VK_ESCAPE: 	case 'Q':	case 'q':
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}

void TimerFunction(int value)
{
	glutPostRedisplay(); // ȭ�� �� ���
	glutTimerFunc(100, TimerFunction, 1); // Ÿ�̸��Լ� �� ����
}
