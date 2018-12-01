#pragma once
#include <GL/freeglut.h>
#include "MyHeader.h"

extern vector<MyVec> vTree;


inline void DrawFloor()
{
	glPushMatrix();
	SOIL;
	glTranslated(0, -10, 0);
	glScaled(1, 0.1, 1);
	glutSolidCube(400.0);
	glPopMatrix();
}

inline void DrawAxis()
{
	glBegin(GL_LINES);
	RED;
	glVertex3d(-100, 0, 0);
	glVertex3d(100, 0, 0);
	GREEN;
	glVertex3d(0, -100, 0);
	glVertex3d(0, 100, 0);
	BLUE;
	glVertex3d(0, 0, -100);
	glVertex3d(0, 0, 100);
	glEnd();
}

inline void DrawTrees()
{
	for (auto d : vTree)
	{
		glPushMatrix();
		{
			glTranslated(d.x, d.y, d.z);
			GREEN;
			glutSolidSphere(10.0, 10, 10);
			BROWN;
			glTranslated(0, -10.0, 0);
			glScaled(0.5, 3, 0.5);
			glutSolidCube(5.0);
		}
		glPopMatrix();
	}
}
