#pragma once
#include <GL/freeglut.h>
#include "MyHeader.h"

extern vector<MyVec> vTree;

inline void DrawFloor()
{
	glPushMatrix();
	SOIL;
	glTranslated(0, 0, 0);
	glScaled(1, 0.01, 1);
	glutSolidCube(400.0);
	glPopMatrix();
}

inline void DrawAxis()
{
	glBegin(GL_LINES);
	RED;
	glVertex3d(-50, 0, 0);
	glVertex3d(50, 0, 0);
	GREEN;
	glVertex3d(0, -50, 0);
	glVertex3d(0, 50, 0);
	BLUE;
	glVertex3d(0, 0, -50);
	glVertex3d(0, 0, 50);
	glEnd();
}

inline void DrawTrees()
{
	for (auto d : vTree)
	{
		glPushMatrix();
		{
			glTranslated(0, 20.0, 0);
			glTranslated(d.x, d.y, d.z);
			GREEN;
			glutSolidSphere(15.0, 10, 10);
			BROWN;
			glTranslated(0, -15.0, 0);
			glScaled(1, 3, 1);
			glutSolidCube(10.0);
		}
		glPopMatrix();
	}
}

