#pragma once
#include <GL/freeglut.h>
#include <vector>
#include <iostream>
#include "MyHeader.h"
using namespace std;

GLfloat AmbientLight[] = { 0.5f, 0.5f,0.5f,1.0f };
GLfloat SpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat light0Pos[] = { 0.f,7.f,0.f, 1.f };
GLfloat light1Pos[] = { 0.f,7.f,0.f, 1.f };
GLfloat SpherePos[] = { 0.f,7.f,0.f, 1.f };
GLfloat SpotlightPos[] = { 0.f,0.f,0.f,1.f };
GLfloat Spotdir[] = { 0,-1,0,1 };

double zoom{ -50 }, CameraForY;
bool bLight0, bLight1;

double tmpX, tmpZ;
double degree{ 0 };

bool bNormal, bSnow{ true };
bool bParticle;
float timer;

struct Snow {
	double x;
	double y;
	double z;
};

class Floor {
public:
	double x, z;
	GLfloat diff[4] = { 0.1f,0.1f,0.1f,1.f };

	inline void snowing()
	{
		for (int i = 0; i < 3; ++i)
			diff[i] += 0.1f;
	}
};

class Particle
{
public:
	MyVec pos;
	MyVec dir;

	Particle(double x,double z)
	{
		pos.x = x + rand() % 6 - 3;
		pos.y = 3 + rand() % 6 - 3;
		pos.z = z + rand() % 6 - 3;

		dir.x= rand() % 2;
		dir.y = rand() % 2;
		dir.z = rand() % 2;

		double len = sqrt(dir.x*dir.x + dir.y*dir.y + dir.z*dir.z);
		dir.x /= len;
		dir.y /= len;
		dir.z /= len;

	}

	inline void Update()
	{
		pos = pos + dir;
	}
};

vector<Snow> vSnow;
vector<Floor> vFloor;
vector<Particle> vParticles;

//-----------·Îº¿-------------
double XRobot, YRobot, ZRobot;
int dir;
double DegreeForRobotArms, DegreeForRobotDir;
bool RobotMoveX, RobotMoveZ;


void Initialization()
{
	tmpX = 15 * cos(degree);
	tmpZ = 15 * sin(degree);
	light0Pos[0] = tmpX;
	light0Pos[2] = tmpZ;

	tmpX = 15 * cos(degree - 180);
	tmpZ = 15 * sin(degree - 180);
	light1Pos[0] = tmpX;
	light1Pos[2] = tmpZ;

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, AmbientLight);

	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);

	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, blue);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SpecularLight);
	glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);

	SpotlightPos[0] = XRobot;
	SpotlightPos[1] = 5;
	SpotlightPos[2] = ZRobot;

	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, Spotdir);
	glLightfv(GL_LIGHT2, GL_POSITION, SpotlightPos);
	glLighti(GL_LIGHT2, GL_SPOT_CUTOFF, 90);
	glLighti(GL_LIGHT2, GL_SPOT_EXPONENT, 1);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, SpecularLight);
	glEnable(GL_LIGHT2);

	//--------------------------------------------------

	double x, z;

	for (double x = -20; x < 20; ++x)
		for (double z = -20; z < 20; ++z)
			vFloor.push_back(Floor{ x,z });

	//--------------------------------------------------
	XRobot = 0, YRobot = 5, ZRobot = 10;
	dir = 1;
	DegreeForRobotArms = DegreeForRobotDir = 0;

}

void DrawFloor()
{
	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularLight);
	glMateriali(GL_FRONT, GL_SHININESS, 64);

	for (auto d : vFloor)
	{
		glMaterialfv(GL_FRONT, GL_EMISSION, d.diff);
		glPushMatrix();
		glTranslated(d.x, 0, d.z);
		glScaled(1, 0.1, 1);
		glutSolidCube(1.0);
		glPopMatrix();
	}
}

void DrawPyramid()
{
	GLfloat diff[] = { 1.0,0.8,0,1 };
	glEnable(GL_COLOR_MATERIAL);
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, diff);
	YELLOW;
	glEnable(GL_NORMALIZE);

	GLfloat A[3] = { 0,8,0 };
	GLfloat B[3] = { -5,0,0 };
	GLfloat C[3] = { 0,0,5 };
	GLfloat D[3] = { 5,0,0 };
	GLfloat E[3] = { 0,0,-5 };

	GLfloat* norm1 = Cross(Minus(B, C), Minus(B, A));
	GLfloat* norm2 = Cross(Minus(C, D), Minus(C, A));
	GLfloat* norm3 = Cross(Minus(D, E), Minus(D, A));
	GLfloat* norm4 = Cross(Minus(E, B), Minus(E, A));

	glBegin(GL_TRIANGLES);
	{
		if (bNormal) glNormal3f(norm1[0], norm1[1], norm1[2]);
		glVertex3fv(A);
		glVertex3fv(B);
		glVertex3fv(C);

		if (bNormal) glNormal3f(norm2[0], norm2[1], norm2[2]);
		glVertex3fv(A);
		glVertex3fv(C);
		glVertex3fv(D);

		if (bNormal)glNormal3f(norm3[0], norm3[1], norm3[2]);
		glVertex3fv(A);
		glVertex3fv(D);
		glVertex3fv(E);

		if (bNormal) glNormal3f(norm4[0], norm4[1], norm4[2]);
		glVertex3fv(A);
		glVertex3fv(E);
		glVertex3fv(B);
	}
	glEnd();

	glBegin(GL_POLYGON);
	{
		glVertex3fv(B);
		glVertex3fv(C);
		glVertex3fv(D);
		glVertex3fv(E);
	}
	glEnd();
	glDisable(GL_COLOR_MATERIAL);
}

void DrawSnow()
{
	GLfloat emi[] = { 1.f,1.f,1.f,1.f };
	glMaterialfv(GL_FRONT, GL_EMISSION, emi);

	for (auto d : vSnow)
	{
		glPushMatrix();
		glTranslated(d.x, d.y, d.z);
		glutSolidSphere(0.2, 25, 25);
		glPopMatrix();
	}
}

void DrawLight()
{
	GLfloat yel[] = { 1.f,1.f,0.f,1.f };
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
	//glMaterialfv(GL_FRONT,GL_EMISSION, yel);

	glPushMatrix();
	glTranslated(SpherePos[0], SpherePos[1], SpherePos[2]);
	glutSolidSphere(1.0, 25, 25);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_EMISSION, red);
	glPushMatrix();
	glTranslated(light0Pos[0], light0Pos[1], light0Pos[2]);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1, 2, 10, 10);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_EMISSION, blue);
	glPushMatrix();
	glTranslated(light1Pos[0], light1Pos[1], light1Pos[2]);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1, 2, 10, 10);
	glPopMatrix();

}

void DrawRobot()
{  //-----------°´Ã¼---------------
	glLoadIdentity();

	glPushMatrix();
	glTranslated(XRobot, YRobot, ZRobot); //ÃàÀÌµ¿
	glRotated(DegreeForRobotDir, 0, 1, 0);     //ÀüÃ¼ ÀÚÀü
	glTranslated(-XRobot, -YRobot, -ZRobot);//Ãà ¿øÁ¡À¸·Î

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	//¸Ó¸®
	glPushMatrix();
	CYAN;
	glTranslated(XRobot, YRobot + 5, ZRobot);
	glScaled(3.f, 3.f, 1.f);
	glutSolidCube(1.0);
	glPopMatrix();
	//ÄÚ
	glPushMatrix();
	RED;
	glTranslated(XRobot, YRobot + 5, ZRobot + 1);
	glutSolidSphere(0.5, 5, 5);
	glPopMatrix();
	//¸öÅë
	glPushMatrix();
	glColor3f(0.38f, 0.75f, 1.f);
	glTranslated(XRobot, YRobot, ZRobot);
	glScaled(2.f, 3.f, 1.f);
	glutSolidCube(2.0);
	glPopMatrix();

	//ÆÈ
	glPushMatrix();
	WHITE;
	glTranslated(XRobot - 2.5, YRobot, ZRobot);
	glRotated(-30, 0, 0, 1);
	glTranslated(0, 2, 0);
	glRotated(DegreeForRobotArms, 1, 0, 0);
	glTranslated(0, -2, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1.0);//¿ÞÆÈ
	glPopMatrix();

	glPushMatrix();
	YELLOW;
	glTranslated(XRobot + 2.5, YRobot, ZRobot);
	glRotated(30, 0, 0, 1);
	glTranslated(0, 2, 0);
	glRotated(-DegreeForRobotArms, 1, 0, 0);
	glTranslated(0, -2, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1.0);	//¿À¸¥ÆÈ
	glPopMatrix();

	//´Ù¸®
	glPushMatrix();
	BLACK;
	glTranslated(XRobot - 1.5, YRobot - 5.0, ZRobot);
	glTranslated(0, 2, 0);
	glRotated(-DegreeForRobotArms, 1, 0, 0);
	glTranslated(0, -2, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1.0);	//¿Þ´Ù¸®
	glPopMatrix();

	glPushMatrix();
	GREEN;
	glTranslated(XRobot + 1.5, YRobot - 5.0, ZRobot);
	glTranslated(0, 2, 0);
	glRotated(DegreeForRobotArms, 1, 0, 0);
	glTranslated(0, -2, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1.0);	//¿À¸¥ÂÊ´Ù¸®
	glPopMatrix();

	glPopMatrix();
	
	glDisable(GL_COLOR_MATERIAL);

}

///////////////////////////
void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);

	glTranslated(0.0, 0.0, zoom);
	glRotated(10, 1, 0, 0);
	glRotated(CameraForY, 0, 1, 0);
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
	case '1':
		bLight0 = !bLight0;
		break;
	case '2':
		bLight1 = !bLight1;
		break;
	case 'y':
		--CameraForY; CameraReset();
		break;
	case'Y':
		++CameraForY; CameraReset();
		break;
	case 'A':case'a':
		DegreeForRobotDir = LEFT;
		dir = -1;
		RobotMoveX = true; RobotMoveZ = false;
		break;
	case 'D':case 'd':
		DegreeForRobotDir = RIGHT;
		dir = 1;
		RobotMoveX = true; RobotMoveZ = false;
		break;
	case 'W':case 'w':
		DegreeForRobotDir = UP;
		dir = -1;
		RobotMoveZ = true; RobotMoveX = false; 
		break;
	case 'S':case 's':
		DegreeForRobotDir = DOWN;
		dir = 1;
		RobotMoveZ = true; RobotMoveX = false; 
		break;
	case 'o':
		bNormal = false;
		break;
	case 'O':
		bNormal = true;
		break;
	case 'p': case 'P':
		bSnow = !bSnow;
		break;
	case 'z':
		--zoom; CameraReset(); break;
	case 'Z':
		++zoom; CameraReset(); break;
	case VK_ESCAPE: 	case 'Q':	case 'q':
		::PostQuitMessage(0);
		break;
	default:
		break;
	}
}