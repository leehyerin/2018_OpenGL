#pragma once
#include <GL/freeglut.h>
#include <vector>
#include <iostream>
#include "MyHeader.h"
using namespace std;

GLfloat AmbientLight[] = { 0.3f, 0.3f,0.3f,1.0f };
GLfloat DiffuseLight[] = { 1.0f, 0.0f, 0.0f, 1.0f };
GLfloat SpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat light0Pos[] = { 0.f,0.f,0.f, 1.f };
GLfloat light1Pos[] = { 0.f,0.f,0.f, 1.f };
GLfloat SpherePos[] = { 0.f,3.f,0.f, 1.f };

double zoom{ -50 }, CameraForY;
bool bLight0, bLight1;

int dir{ 1 };
double tmpX, tmpZ;
double degree{ 0 };

bool bNormal, bSnow{true};

struct Snow {
	double x;
	double y;
	double z;
};

class Floor 
{
public:
	double x, z;
	GLfloat diff[4] = { 0.1f,0.1f,0.1f,1.f };
	
	void snowing() 
	{
		for (int i = 0; i < 3; ++i)
			diff[i] += 0.1f;
	}
};

vector<Snow> vSnow;
vector<Floor> vFloor;

void Initialization()
{
	tmpX = 10 * cos(degree);
	tmpZ = 10 * sin(degree);
	light0Pos[0] = tmpX;
	light0Pos[2] = tmpZ;

	tmpX = 10 * cos(degree - 180);
	tmpZ = 10 * sin(degree - 180);
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
	//--------------------------------------------------
	
	double x, z;

	for (double x = -10; x < 10; ++x)
		for (double z = -10; z < 10; ++z)
			vFloor.push_back(Floor{ x,z });

}

void DrawFloor()
{
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
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
	glEnable(GL_NORMALIZE);

	GLfloat A[3] = { 0,5,0 };
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
	glPushMatrix();
	glTranslated(SpherePos[0], SpherePos[1], SpherePos[2]);
	glutSolidSphere(2.0, 20, 10);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_EMISSION, red);
	glPushMatrix();
	glTranslated(light0Pos[0], light0Pos[1], light0Pos[2]);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(2, 3, 10, 10);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_EMISSION, blue);
	glPushMatrix();
	glTranslated(light1Pos[0], light1Pos[1], light1Pos[2]);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(2, 3, 10, 10);
	glPopMatrix();
}

void DrawCone()
{
	glPushMatrix();
	glTranslated(-10, 0, -10);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1, 2, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 0, 10);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1, 2, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 0, -10);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1, 2, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 0, 10);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(1, 2, 4, 4);
	glPopMatrix();
}

void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);

	glTranslated(0.0, 0.0, zoom);
	glRotated(30, 1, 0, 0);
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
	case 'a':
		for (int i = 0; i < 3; ++i)
			AmbientLight[i] -= 0.1f;	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, AmbientLight);
		break;
	case 'A':
		for (int i = 0; i < 3; ++i)
			AmbientLight[i] += 0.1f;	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, AmbientLight);
		break;
	case 'd':
		red[0] -= 0.01f;		glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
		blue[2] -= 0.01f;		glLightfv(GL_LIGHT1, GL_DIFFUSE, blue);
		break;
	case 'D':
		red[0] += 0.01f;		glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
		blue[2] += 0.01f;		glLightfv(GL_LIGHT1, GL_DIFFUSE, blue);
		break;
	case 's':
		for (int i = 0; i < 3; ++i)
			SpecularLight[i] -= 0.1;
		break;
	case 'S':
		for (int i = 0; i < 3; ++i)
			SpecularLight[i] += 0.1;
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