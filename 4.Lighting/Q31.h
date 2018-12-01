#pragma once
#include <GL/freeglut.h>
#include "MyHeader.h"

GLfloat AmbientLight[] = { 0.2f,0.2f,0.2f,1.0f };
GLfloat DiffuseLight[] = { 1.0f, 0.0f, 0.0f, 1.0f };
GLfloat SpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat light0Pos[] = { 0.f,0.f,0.f, 1.f };
GLfloat light1Pos[] = { 0.f,0.f,0.f, 1.f };
GLfloat SpherePos[] = { 0.f,0.f,0.f, 1.f };

double zoom{ -30 };
bool bLight0, bLight1;

bool bRotation;
int dir{ 1 };
double tmpX, tmpZ;
double degree{ 0 };



void Initialization()
{
	tmpX = 20 * cos(degree);
	tmpZ = 20 * sin(degree);
	light0Pos[0] = tmpX;
	light0Pos[2] = tmpZ;

	tmpX = 10 * cos(degree - 180);
	tmpZ = 10 * sin(degree - 180);
	light1Pos[0] = tmpX;
	light1Pos[2] = tmpZ;

	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);
	glLightfv(GL_LIGHT0, GL_EMISSION, SpecularLight);

	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, blue);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SpecularLight);
	glLightfv(GL_LIGHT1, GL_POSITION, light1Pos);
	glLightfv(GL_LIGHT1, GL_EMISSION, SpecularLight);
}


void CameraReset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, WINDOW_WIDTH / WINDOW_HEIGHT, 1.0, 1000.0);

	glTranslated(0.0, 0.0, zoom);
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
		dir = -1;
		degree += dir * 0.1;
		break;
	case'Y':
		dir = 1;
		degree += dir * 0.1;
		break;
	case 'a':case 'A':
		bRotation = !bRotation;
		break;
	case 'd':
		red[0] -= 0.01f;		glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
		blue[2] -= 0.01f;	glLightfv(GL_LIGHT1, GL_DIFFUSE, blue);
		break;
	case 'D':
		red[0] += 0.01f;		glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
		blue[2] += 0.01f;	glLightfv(GL_LIGHT1, GL_DIFFUSE, blue);
	break;
	case 's':
		for (int i = 0; i < 3; ++i)
			SpecularLight[i] -= 0.1;
		break;
	case 'S':
		for (int i = 0; i < 3; ++i)
			SpecularLight[i] += 0.1;
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