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
float Bigsize = 0.5f; //큰삼각형
float xPos, yPos;		//작은 삼각형
float orbit = 0.f;
int status = 0;
bool flag2 = true;
bool flag1, flag3 = false;

void main(int argc, char *argv[])
{
	//초기화 함수들 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);// 디스플레이 모드 설정 
	glutInitWindowPosition(0, 0); 	// 윈도우의 위치지정 
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); 	// 윈도우의 크기 지정 
	glutCreateWindow("Q13"); 	// 윈도우 생성 (윈도우 이름) 
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
	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기
	glMatrixMode(GL_MODELVIEW);


	small_degree += 5;
	

	glRotatef(degree, 0.f, 1.f, 0.f);
	{
		//-------XY평면 삼각형----------
		glPushMatrix();
			glColor3f(0.8f, 0.8f, 0.8f);
			glBegin(GL_LINE_LOOP);
				glVertex3f(0.0, Bigsize, 0.0);
				glVertex3f(Bigsize, -Bigsize, 0.0);
				glVertex3f(-Bigsize, -Bigsize, 0.0);
			glEnd();
			
			glColor3f(1.f, 1.f, 0.f);
			DrawTriangle(xPos, yPos);		//작은 삼각형
		
		glPopMatrix();

		

		//-------YZ평면 삼각형----------
		glPushMatrix();
		glColor3f(0.5f, 0.5f, 0.5f);
			glRotatef(90.f, 0.f, 1.f, 0.f);
			glBegin(GL_LINE_LOOP);
				glVertex3f(0.0, Bigsize, 0.0);
				glVertex3f(Bigsize, -Bigsize, 0.0);
				glVertex3f(-Bigsize, -Bigsize, 0.0);
			glEnd();

			glColor3f(0.f, 1.f, 1.f);
			DrawTriangle(xPos, yPos);		//작은 삼각형
			
		glPopMatrix();

		
	

		//-----------좌표계----------------
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
	//case를 나눠야함
	if (flag1)
	{
		if (xPos <= 0 && yPos >= Bigsize)				{ status = 0; orbit = 0.f;	flag1 = false; flag2 = true; } //↙
	}
	if (flag2)
	{
		if (xPos <= -Bigsize && yPos <= -Bigsize) { status = 1; orbit = 0.f; flag2 = false; flag3 = true; } //→	
	}
	if (flag3)
	{
		if (xPos >= +Bigsize && yPos <= +Bigsize) { status = 2; orbit = 0.f; flag3 = false; flag1 = true; } //↖
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


	glutPostRedisplay(); // 화면 재 출력
	glutTimerFunc (100, TimerFunction, 1); // 타이머함수 재 설정
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