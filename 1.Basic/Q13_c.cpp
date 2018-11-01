#include <GL/freeglut.h>
#include "Myheader.h"

GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Keyboard(unsigned char, int, int );
void TimerFunction(int);
//-----------------------------
void DrawTriangle(float, float);

float degree = 0.f;
float small_degree = 0.f;
float Bigsize = 0.5f; //ū�ﰢ��
float xPos, yPos;		//���� �ﰢ��
float orbit = 0.f;
int status = 0;
bool flag2 = true;
bool flag1, flag3 = false;

void main(int argc, char *argv[])
{
	//�ʱ�ȭ �Լ��� 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// ���÷��� ��� ���� 
	glutInitWindowPosition(0, 0); 	// �������� ��ġ���� 
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// �������� ũ�� ���� 
	glutCreateWindow("Q13"); 	// ������ ���� (������ �̸�) 
	glutDisplayFunc(drawScene);	// ��� �Լ��� ���� 
	glutKeyboardFunc(Keyboard); //Ű�Է� 
	glutTimerFunc(100, TimerFunction, 1); // Ÿ�̸� �Լ� ���� 
	glutReshapeFunc(Reshape);	// �ٽ� �׸��� �Լ��� ���� 
	glutMainLoop();
}

 //������ ��� �Լ�
GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ�
	glMatrixMode(GL_MODELVIEW);


	small_degree += 5;
	

	glRotatef(degree, 0.f, 1.f, 0.f);
	{
		//-------XY��� �ﰢ��----------
		glPushMatrix();
			glColor3f(0.8f, 0.8f, 0.8f);
			glBegin(GL_LINE_LOOP);
				glVertex3f(0.0, Bigsize, 0.0);
				glVertex3f(Bigsize, -Bigsize, 0.0);
				glVertex3f(-Bigsize, -Bigsize, 0.0);
			glEnd();
			
			glColor3f(1.f, 1.f, 0.f);
			DrawTriangle(xPos, yPos);		//���� �ﰢ��
		
		glPopMatrix();

		

		//-------YZ��� �ﰢ��----------
		glPushMatrix();
		glColor3f(0.5f, 0.5f, 0.5f);
			glRotatef(90.f, 0.f, 1.f, 0.f);
			glBegin(GL_LINE_LOOP);
				glVertex3f(0.0, Bigsize, 0.0);
				glVertex3f(Bigsize, -Bigsize, 0.0);
				glVertex3f(-Bigsize, -Bigsize, 0.0);
			glEnd();

			glColor3f(0.f, 1.f, 1.f);
			DrawTriangle(xPos, yPos);		//���� �ﰢ��
			
		glPopMatrix();

		
	

		//-----------��ǥ��----------------
		glLoadIdentity();

		glColor3f(1.f, 1.f, 1.f);
		glBegin(GL_LINES);
		glVertex3f(-1.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, -1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
		glEnd();
		//--------------------------------
	}
	glFlush ();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT, -400.0, 400.0);
}


void Keyboard(unsigned char key, int x, int y)
{ 
	switch (key)
	{
	case 'Y':
		++degree;
		break;
	case 'y':
		--degree;
		break;	
	case 'S':
		if (Bigsize < 1.f)
			Bigsize += 0.1f;
		break;
	case 's':
		if (Bigsize > 0.2f)
			Bigsize -= 0.1f;
		break;
	case VK_ESCAPE:
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}

void TimerFunction(int value)
{
	//case�� ��������
	if (flag1)
	{
		if (xPos <= 0 && yPos >= Bigsize)				{ status = 0; orbit = 0.f;	flag1 = false; flag2 = true; } //��
	}
	if (flag2)
	{
		if (xPos <= -Bigsize && yPos <= -Bigsize) { status = 1; orbit = 0.f; flag2 = false; flag3 = true; } //��	
	}
	if (flag3)
	{
		if (xPos >= +Bigsize && yPos <= +Bigsize) { status = 2; orbit = 0.f; flag3 = false; flag1 = true; } //��
	}
	orbit += 0.01;

	switch(status)
	{
	case 0:
		xPos = - orbit;
		yPos = +Bigsize - 2 * orbit;
		glTranslatef(-orbit, +Bigsize - 2 * orbit, 0.0f);
		break;
	case 1:
		xPos = -Bigsize + orbit;
		yPos = -Bigsize;
		glTranslatef(-Bigsize + orbit, -Bigsize, 0.0f);
		break;
	case 2:
		xPos = +Bigsize - orbit;
		yPos = -Bigsize + 2 * orbit;
		glTranslatef(+Bigsize - orbit , -Bigsize + 2 * orbit, 0.0f);
		break;
	}


	glutPostRedisplay(); // ȭ�� �� ���
	glutTimerFunc (100, TimerFunction, 1); // Ÿ�̸��Լ� �� ����
}

void DrawTriangle(float x, float y)
{
	glPushMatrix();
	glRotatef(small_degree, 0.f, 1.f, 0.f);

	glBegin(GL_TRIANGLES);
	
	glVertex2f(     x,  y + 0.1f);      //    o
	glVertex2f(x - 0.1f, y - 0.1f);
	glVertex2f(x + 0.1f, y - 0.1f); // ------
	
	glEnd();	
	
	glPopMatrix();

}