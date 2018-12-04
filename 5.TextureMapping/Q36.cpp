#include <GL/freeglut.h>
#include <vector>
#include <iostream>
#include "MyHeader.h"
#include "LoadBitmap.h"
using namespace std;

GLvoid Reshape(int, int);
GLvoid drawScene(GLvoid);
void Keyboard(unsigned char, int, int);
void LoadBitMap();


void DrawFloor();
void DrawPyramid();
void DrawSnow();

void TimerFunction(int);
void CameraReset();
//-----------------------------
double zoom{ -50 };
double DegreeForAxisY{ 30 };

static GLubyte *pBytes;
static BITMAPINFO *info;

static GLuint texture[5];

struct Snow {
	double x;
	double y;
	double z;

	void Update()
	{
		y -= 0.5;
	}
};

vector<Snow> vSnow;

void LoadBitMap()
{
	glGenTextures(4, texture);


	glBindTexture(GL_TEXTURE_2D, texture[0]);
	pBytes = LoadDIBitmap("Jigsaw1.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	pBytes = LoadDIBitmap("Jigsaw2.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	pBytes = LoadDIBitmap("Jigsaw3.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	pBytes = LoadDIBitmap("Jigsaw4.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 256, 256, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	pBytes = LoadDIBitmap("background.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 3000, 2000, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_DECAL);
}


int main(int argc, char *argv[])
{
	//초기화 함수들 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Q36");
	LoadBitMap();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keyboard);

	glutTimerFunc(100, TimerFunction, 1);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

//윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0, 0, 0.2, 0.5);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();

	DrawFloor();
	DrawPyramid();
	DrawSnow();
	//
	glutSwapBuffers();
}

void TimerFunction(int value)
{
	DegreeForAxisY++;

	vSnow.push_back(Snow{ (double)(rand() % 20) - 10, 10, (double)(rand() % 20) - 10 });
	for (int d = 0; d < vSnow.size(); ++d)
	{
		if (vSnow[d].y == 0)
		{
			vSnow.erase(vSnow.begin() + d);
			break;
		}
	}
	CameraReset();

	glutPostRedisplay(); // 화면 재 출력
	glutTimerFunc(100, TimerFunction, 1); // 타이머함수 재 설정
}


void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);

	glTranslated(0.0, 0.0, zoom);

	glRotated(30, 1, 0, 0);
	glRotated(DegreeForAxisY, 0, 1, 0);
}


GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	CameraReset();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'y':	--DegreeForAxisY;		CameraReset(); break;
	case 'Y':	++DegreeForAxisY;		CameraReset(); break;
	case 'Z':
		++zoom; CameraReset(); break;
	case VK_ESCAPE: 	case 'Q':	case 'q':
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}

void DrawFloor()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-10.0, 0.0, -10.0);

		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-10.0, -0.0, 10.0);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(10.0, -0.0, 10.0);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(10.0, -0.0, -10.0);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void DrawPyramid()
{

	GLfloat A[3] = { 0,8,0 };
	GLfloat B[3] = { -5,0,0 };
	GLfloat C[3] = { 0,0,5 };
	GLfloat D[3] = { 5,0,0 };
	GLfloat E[3] = { 0,0,-5 };
	//
	//GLfloat* norm1 = Cross(Minus(B, C), Minus(B, A));
	//GLfloat* norm2 = Cross(Minus(C, D), Minus(C, A));
	//GLfloat* norm3 = Cross(Minus(D, E), Minus(D, A));
	//GLfloat* norm4 = Cross(Minus(E, B), Minus(E, A));
	//

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_TRIANGLES);
	{
		//if (bNormal) glNormal3f(norm1[0], norm1[1], norm1[2]);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3fv(A);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3fv(B);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3fv(C);
	}
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_TRIANGLES);
	{
		//if (bNormal) glNormal3f(norm2[0], norm2[1], norm2[2]);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3fv(A);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3fv(C);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3fv(D);
	}
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_TRIANGLES);
	{
		//if (bNormal)glNormal3f(norm3[0], norm3[1], norm3[2]);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3fv(A);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3fv(D);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3fv(E);
	}
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_TRIANGLES);
	{
		//if (bNormal) glNormal3f(norm4[0], norm4[1], norm4[2]);
		glTexCoord2f(0.5f, 1.0f);
		glVertex3fv(A);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3fv(E);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3fv(B);
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void DrawSnow()
{
	glLoadIdentity();

	WHITE;

	for (int d = 0; d < vSnow.size(); ++d)
	{
		glPushMatrix();
		glTranslated(vSnow[d].x, vSnow[d].y, vSnow[d].z);
		vSnow[d].Update();
		glutSolidSphere(0.2, 25, 25);
		glPopMatrix();
	}
}
