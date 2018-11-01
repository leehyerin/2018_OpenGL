#include <GL/freeglut.h>
#include "Myheader.h"
GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Keyboard(unsigned char, int, int);
void TimerFunction(int);
//-----------------------------
void SetupRC();
void CameraReset();

void MoveX();

GLUquadricObj *qobj;
double DegreeForAxisY, zoom;
double x, y, z;
int dir;
double Degree_Bottom, Degree_Middle_Y, Degree_Middle_z, Degree_Top_X, Degree_Top_Z;

void main(int argc, char *argv[])
{
	//�ʱ�ȭ �Լ��� 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);  // ���� ���۸��� 3�������� �׸���. 
	glutInitWindowPosition(0, 0); 	// �������� ��ġ���� 
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// �������� ũ�� ���� 
	glutCreateWindow("Q20"); 	// ������ ���� (������ �̸�) 
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
	glColor3f(0.f, 0.f, 1.f);
	glPushMatrix();
	glTranslated(0.0, 0.0, -1.0);
	glScaled(0.5, 0.5, 3);
	glutSolidCube(0.7);
	glPopMatrix();

	glColor3f(1.f, 0.f, 0.f);
	glPushMatrix();
	glTranslated(1.0, 0.0, 0.0);
	glScaled(3, 0.5, 0.5);
	glutSolidCube(0.7);
	glPopMatrix();

	glColor3f(0.f, 1.f, 0.f);
	glPushMatrix();
	glTranslated(0.0, 1.0, 0);
	glScaled(0.5, 3, 0.5);
	glutSolidCube(0.7);		
	glPopMatrix();

	//-----------�ٴ� -------------
	glLoadIdentity();
	glColor3f(0.6, 0.4, 0.4);
	glTranslated(0.0, -10.0, 0);
	glScaled(1.0, 0.1, 1.0);
	glutSolidCube(30.0);	 glColor3f(0, 0, 0);		glutWireCube(30.0);

	//-----------��ü---------------
	glLoadIdentity();
	
	glPushMatrix();
		glColor3f(0.38f, 0.75f, 1.f);
		glTranslated(x, y, z);
		glRotated(Degree_Bottom, 0, 1, 0); 
		glScaled(3.f, 1.f, 3.f);
		glutSolidCube(1.0);		glColor3f(0,0,0);		glutWireCube(1.0);
	glPopMatrix();
		
	glLoadIdentity();

		glColor3f(1.f, 1.f, 0.f);
			glTranslated(x, y + 1.0, z/2);
			glRotated(Degree_Bottom, 0, 1, 0); //����
			glRotated(Degree_Middle_z, 0, 0, 1); //����
			glRotated(Degree_Middle_Y, 0, 1, 0); 

			glPushMatrix();
				glTranslated(0, -1.0, 0);
				glScaled(0.5f, 4.f, 0.5f);
				glutSolidCube(0.8);		glColor3f(0, 0, 0);		glutWireCube(0.8);
			glPopMatrix();
			//
			glColor3f(0.48f, 0.98f, 0.5f);
			glTranslated(0, -2.5, 0);
			glRotated(Degree_Top_X, 1, 0, 0);//����
			glRotated(Degree_Top_Z, 0, 0, 1);//����

			glPushMatrix();
				glTranslated(0, -1.0, 0);
				glScaled(0.5f, 4.f, 0.5f);
				glutSolidCube(0.5);		glColor3f(0, 0, 0);		glutWireCube(0.5);
			glPopMatrix();

		glPopMatrix();

	
	//--------------------------------

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

	glTranslated(0.0, 0.0, zoom);

	glRotated(DegreeForAxisY, 0, 1, 0);
}

void SetupRC()
{
	zoom = -50;
	x = 0, y = -10, z = 0;
	dir = 1;
	Degree_Bottom = 0; Degree_Middle_z = 180; //Degree_Top = 180;
}

void MoveX()
{
	x += dir * 0.1;

	if (12 < x) dir *= -1;
	else if (x < -12) dir *= -1;
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'y':	--DegreeForAxisY;		CameraReset(); break;
	case 'Y':	++DegreeForAxisY;		CameraReset(); break;
														
	case '-':	--zoom;		CameraReset(); break;
	case '+':	++zoom;		CameraReset(); break;

	case '1': Degree_Bottom += 5; break;
	case '!': Degree_Bottom += 5; break;
	case '2': Degree_Middle_z += 5;	break;
	case '@':Degree_Middle_z -= 5;	break;
	case '3': Degree_Top_X += 5;		break;
	case '#': Degree_Top_X -= 5;		break;
	case '4': Degree_Top_Z += 5;		break;
	case '$': Degree_Top_Z -= 5;		break;
	case '5' :Degree_Middle_Y += 5; break;
	case '%':Degree_Middle_Y -= 5; break;

	case VK_ESCAPE: 	case 'Q':	case 'q':
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}

void TimerFunction(int value)
{
	MoveX();

	glutPostRedisplay(); // ȭ�� �� ���
	glutTimerFunc(100, TimerFunction, 1); // Ÿ�̸��Լ� �� ����
}
