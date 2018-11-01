#include <GL/freeglut.h>
#include "Myheader.h"
GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Keyboard(unsigned char, int, int);
void TimerFunction(int);
//-----------------------------
void DrawWireShape();
void DrawSolidShape();
void SetupRC();
void RotateAxis();
void RotateLeft();
void RotateRight();

GLUquadricObj *qobj;
int type;
double DegreeForAxisX, DegreeForAxisY, zoom;
double DegreeForLeft, DegreeForRight;

void main(int argc, char *argv[])
{
	//�ʱ�ȭ �Լ��� 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);  // ���� ���۸��� 3�������� �׸���. 
	glutInitWindowPosition(0, 0); 	// �������� ��ġ���� 
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// �������� ũ�� ���� 
	glutCreateWindow("Q16"); 	// ������ ���� (������ �̸�) 
	// ���� ���� �ʱ�ȭ �Լ� 
	SetupRC();
	// �ʿ��� �ݹ� �Լ� ���� 
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

	//-----------��ǥ��----------------
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

	//-----------�ٴ� -------------
	glLoadIdentity();
	RotateAxis();
	glColor3f(0.6, 0.4, 0.4);
	glTranslated(0.0, -10.0, 0);
	glScaled(1.0, 0.1, 1.0);
	glutSolidCube(30.0);
	
	//-----------��ü---------------
	glColor3f(1.f, 1.f, 1.f);
	glLoadIdentity();
	qobj = gluNewQuadric(); // ��ü �����ϱ�
	gluQuadricNormals( qobj, GLU_SMOOTH ); // ���� ���� 
	gluQuadricOrientation( qobj, GLU_OUTSIDE ); // ���� ���� 
	RotateAxis(); //��ü ��ǥ��
	glPushMatrix();
		glScaled(3.f, 3.f, 3.f);
		glPushMatrix();
			glTranslated(-3, 0, 0);
			RotateLeft();
			DrawWireShape();
		glPopMatrix();
		
		glTranslated(3, 0, 0);
		RotateRight();
		DrawSolidShape();
	glPopMatrix();
	//--------------------------------

	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective (60, WINDOW_WIDTH/WINDOW_HEIGHT, 1.0, 1000.0); 
	glTranslated (0.0, 0.0, -30.0);
}

void SetupRC() 
{
	type = CUBE;
	// ��� ���� �ʱ�ȭ
}

void RotateAxis()
{
	glRotated(DegreeForAxisX, 1.0, 0.0, 0.0);
	glRotated(DegreeForAxisY, 0.0, 1.0, 0.0);
	glRotated(zoom, 0.0, 0.0, 1.0);
}

void RotateLeft()
{
	glRotated(DegreeForLeft, 0.0, 1.0, 0.0);
}

void RotateRight()
{
	glRotated(DegreeForRight, 0.0, 1.0, 0.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':	--DegreeForAxisX; 		break;
	case 'X':	++DegreeForAxisX; 		break;
		
	case 'y':	--DegreeForAxisY;		break;
	case 'Y':	++DegreeForAxisY;		break;
		
	case 'z':	--zoom;		break;
	case 'Z':	++zoom;		break;
		
	case 'l':	case 'L':
		++DegreeForLeft;
		break;
	case 'r':	case 'R':
		++DegreeForRight;
		break;
	case 'o':	case 'O':
		++DegreeForLeft;
		++DegreeForRight;
		break;
	case 'c':	case 'C':
		type = rand() % 4;
		break;
	case '1':		type = CUBE;				break;
	case '2':		type = CYLINDER;		break;
	case '3':		type = TEAPOT;			break;
	case '4':		type = SPHERE;			break;

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

void DrawWireShape()
{
	gluQuadricDrawStyle(qobj, GLU_LINE);
	
	switch (type)
	{
	case CUBE:
		glutWireCube(1.0);
		break;
	case CYLINDER:
		gluCylinder(qobj, 1.0, 0.0, 2.0, 20, 8);
		break;
	case TEAPOT:
		glutWireTeapot(1.0);
		break;
	case SPHERE:
		gluSphere( qobj, 1.5, 30, 10 ); 
		break;
	default:
		break;
	}
}

void DrawSolidShape()
{
	gluQuadricDrawStyle(qobj, GLU_FILL);
	
	switch (type)
	{
	case CUBE:
		glutSolidCube(1.0);
		break;
	case CYLINDER:
		gluCylinder(qobj, 1.0, 0.0, 2.0, 20, 8);
		break;
	case TEAPOT:
		glutSolidTeapot(1.0);
		break;
	case SPHERE:
		gluSphere(qobj, 1.5, 30, 10);
		break;
	default:
		break;
	}
}